
#ifndef WTSPAG_HPP
#define WTSPAG_HPP

// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

namespace WtSPAG{

class WtSPAGClass
{
private:
  
  ////////////////////// -------------------- members ---------------------------------- //////////////////////
  arma::vec m_mresid;             // residuals
  //arma::vec m_weight;             // weights
  int m_N;                        // sample size     
  double m_SPA_Cutoff;            // cutoff of standardized score to use normal approximation or SPA
  arma::vec m_AF_ref;             // refrence MAF
  arma::vec m_AN_ref;             // reference MAC   
  arma::vec m_pvalue_bat;         // batch effect pvalue
  double m_pvalue_bat_cutoff;     // batch effect cut off 
  arma::vec residNonOutlier;      //non-outlier residual 
  arma::vec residOutlier;         //outlier residual:R-R
public:
  
  WtSPAGClass(arma::mat t_mresid,
              // arma::vec t_weight,
              int t_N,
              double t_SPA_Cutoff);
  
  void set_AF_ref(arma::vec t_AF_ref){m_AF_ref = t_AF_ref;}
  void set_AN_ref(arma::vec t_AN_ref){m_AN_ref = t_AN_ref;}
  void set_pvalue_bat(arma::vec t_pvalue_bat){m_pvalue_bat = t_pvalue_bat;}
  void set_pvalue_bat_cutoff(double t_pvalue_bat_cutoff){m_pvalue_bat_cutoff = t_pvalue_bat_cutoff;}
  
  
  // The MGF of G (genotype)
  arma::vec M_G0(arma::vec t, double MAF){
    arma::vec re = pow((1 - MAF + MAF * arma::exp(t)), 2);
    return re;
  }
  
  // The first derivative of the MGF of G (genotype)
  arma::vec M_G1(arma::vec t, double MAF){
    arma::vec re = 2 * (MAF * arma::exp(t)) % (1 - MAF + MAF * arma::exp(t));
    return re;                           
  }
  
  // The second derivative of the MGF of G (genotype)
  arma::vec M_G2(arma::vec t, double MAF){
    arma::vec re = 2 * pow(MAF * arma::exp(t), 2) + 2 * (MAF * arma::exp(t)) % (1 - MAF + MAF * arma::exp(t));
    return re;
  }
  
  // The CGF of G (genotype)
  arma::vec K_G0(arma::vec t, double MAF){
    arma::vec re = arma::log(M_G0(t, MAF));
    return re;
  }
  
  // The first derivative of the CGF of G (genotype)
  arma::vec K_G1(arma::vec t, double MAF){
    arma::vec re = M_G1(t, MAF) / M_G0(t, MAF);
    return re;
  }
  
  // The second derivative of the CGF of G (genotype)
  arma::vec K_G2(arma::vec t, double MAF){
    arma::vec re = (M_G0(t, MAF) % M_G2(t, MAF) - pow(M_G1(t, MAF), 2)) / pow(M_G0(t, MAF), 2);
    return re;
  }
  
  // The CGF of score test statistic 
  double H_org(double t
                 , arma::vec R
                 , const double& MAF
                 
  ) {
    
    double out = sum(K_G0(t * R , MAF)) ;
    
    return out;
  }
  
  // The first derivative of the CGF of score test statistic 
  double H1_adj(double t
                  , arma::vec R
                  , const double& MAF
                  , const double& s
                  
  ) {
    double out = sum(R% K_G1(t * R, MAF))-s;
    return out;
  }
  // The second derivative of the CGF of score test statistic 
  double H2(double t
              , arma::vec R
              , const double& MAF
              
  ) {
    double out = sum(pow(R, 2) % K_G2(t * R, MAF)) ;
    
    return out;
  }
  
  
  // partial normal distribution approximation
  arma::vec Horg_H2(double t, arma::vec R, const double MAF)
  {
    arma::vec Horg_H2_vec(2);
    double Horg = H_org(t, R, MAF);
    double H_2 = H2(t, R, MAF)  ;
    Horg_H2_vec.at(0) = Horg;
    Horg_H2_vec.at(1) = H_2;
    return Horg_H2_vec;
  }
  
  arma::vec H1_adj_H2(double t, arma::vec R, double s,const double MAF)
  {
    arma::vec H1_adj_H2_vec(2);
    double H_1_adj = H1_adj(t, R, MAF, s);
    double H_2 = H2(t, R, MAF) ;
    // double H1_adj = sum(R % K_G1(t * R, MAF)) - s;
    // double H2 = sum(pow(R, 2) % K_G2(t * R, MAF));
    H1_adj_H2_vec.at(0) = H_1_adj;
    H1_adj_H2_vec.at(1) = H_2;
    return H1_adj_H2_vec;
  }
  
  // The below code is from SPACox.hpp
  Rcpp::List fastgetroot_K1(double t_initX,
                            const double& s,
                            const double MAF,
                            double mean_nonOutlier,
                            double var_nonOutlier,
                            const arma::vec residOutlier
  )
  {
    double x = t_initX, oldX;
    double K1 = 0, K2 = 0, oldK1;
    double diffX = arma::datum::inf, oldDiffX;
    bool converge = true;
    double tol = 0.001;
    int maxiter = 100;
    int iter = 0;
    
    for(iter = 0; iter < maxiter; iter ++){
      
      oldX = x;
      oldDiffX = diffX;
      oldK1 = K1;
      
      // K1 = H1_adj(x, R, s, MAFVec);
      // K2 = H2(x, R, MAFVec);
      
      arma::vec H1_adj_H2_vec = H1_adj_H2(x, residOutlier,s,MAF);
      
      K1 = H1_adj_H2_vec.at(0) + mean_nonOutlier + var_nonOutlier * x;
      K2 = H1_adj_H2_vec.at(1) + var_nonOutlier;
      
      diffX = -1 * K1 / K2;
      
      if(!std::isfinite(K1)){
        // checked it on 07/05:
        // if the solution 'x' tends to infinity, 'K2' tends to 0, and 'K1' tends to 0 very slowly.
        // then we can set the one sided p value as 0 (instead of setting converge = F)
        x = arma::datum::inf;
        K2 = 0;
        break;
      }
      
      if(arma::sign(K1) != arma::sign(oldK1)){
        while(std::abs(diffX) > std::abs(oldDiffX) - tol){
          diffX = diffX / 2;
        }
      }
      
      if(std::abs(diffX) < tol) break;
      
      x = oldX + diffX;
    }
    
    if(iter == maxiter) 
      converge = false;
    
    Rcpp::List yList = Rcpp::List::create(Rcpp::Named("root") = x,
                                          Rcpp::Named("iter") = iter,
                                          Rcpp::Named("converge") = converge,
                                          Rcpp::Named("K2") = K2);
    return yList;
  } 
  
  double GetProb_SPA_G(const double MAF, 
                       const arma::vec residOutlier, 
                       double s, 
                       bool lower_tail,
                       double mean_nonOutlier,
                       double var_nonOutlier)
  {
    double initX = 0;
    
    // The following initial values are validated on 03/25/2021
    // if(q2 > 0) initX = 3;
    // if(q2 <= 0) initX = -3;
    
    Rcpp::List rootList = fastgetroot_K1(initX, s, MAF, mean_nonOutlier, var_nonOutlier, residOutlier);
    double zeta = rootList["root"];
    
    // std::cout << "zeta:\t" << zeta << std::endl;
    
    // double k1 = H_org(zeta, R, MAFVec);
    // double k2 = H2(zeta, R, MAFVec);
    arma::vec k12 = Horg_H2(zeta, residOutlier, MAF);
    double k1 = k12.at(0) + mean_nonOutlier * zeta + 0.5 * var_nonOutlier * pow(zeta, 2);
    double k2 = k12.at(1) + var_nonOutlier;
    
    double temp1 = zeta * s - k1;
    
    double w = arma::sign(zeta) * sqrt(2 * temp1);
    double v = zeta * sqrt(k2);
    
    double pval = arma::normcdf(arma::sign(lower_tail - 0.5) * (w + log(v/w) / w));
    return pval;
  }     
  
  
  double getMarkerPval(arma::vec t_GVec, 
                       double t_altFreq, 
                       double& t_zScore, 
                       bool t_flip,     // if true, genotype is flipped and AF_ref should be 1-AF_ref
                       int t_i)
  {
    double AF_ref = m_AF_ref.at(t_i);
    double AN_ref = m_AN_ref.at(t_i);
    double pvalue_bat = m_pvalue_bat.at(t_i);
    
    if(t_flip)  // t_altFreq>0.5
    {
      t_GVec = 2-t_GVec;                 //g=2-g
      t_altFreq =2 - t_altFreq; 
      AF_ref = 1 - AF_ref;
    }
    
    // If pvalue for batch effect is less than the cutoff, then we do not use reference (external) allele frequency information
    if(pvalue_bat < m_pvalue_bat_cutoff)
      AN_ref = 0;
    
    // The below is from WtCoxG-2023-07-27-LY.R
    
    double AF = (m_N * t_altFreq + AN_ref * AF_ref) / (m_N + AN_ref);
    double S = sum(m_mresid % (t_GVec - 2 * AF));
    
    double G_var = 2 * AF * (1 - AF);
    
    double meanR = mean(m_mresid);
    double tildeR = meanR * m_N / (m_N + AN_ref);
    
    double S_var = (sum(pow(m_mresid - tildeR, 2)) + AN_ref * pow(tildeR, 2)) * G_var;
    t_zScore = S / sqrt(S_var);
    
    double pval = 0;
    
    if(std::abs(t_zScore) < m_SPA_Cutoff){
    pval = arma::normcdf(-1*std::abs(t_zScore))*2;
    return pval;
    }
    
    double mean_nonOutlier = (sum(residNonOutlier-tildeR) - AN_ref * tildeR ) *2*AF;
    double var_nonOutlier = (sum(pow((residNonOutlier-tildeR), 2) + AN_ref * pow(tildeR, 2))) * G_var;
    // Saddlepoint approximation (check SPAmix.hpp for more details)
    // The MGF of G (genotype)
    // return pval;
    double pval1 = GetProb_SPA_G(AF, 
                                 residOutlier-tildeR, 
                                 std::abs(S), 
                                 false,
                                 mean_nonOutlier,
                                 var_nonOutlier);
    
    double pval2 = GetProb_SPA_G(AF, 
                                 residOutlier-tildeR, 
                                 -1 * std::abs(S), 
                                 false,
                                 mean_nonOutlier,
                                 var_nonOutlier);
    pval = pval1 + pval2;
    return(pval);
    
    
  }
  
};

}

#endif
