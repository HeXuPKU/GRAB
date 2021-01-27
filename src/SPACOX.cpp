
// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

#include "SPACOX.hpp"
#include "approxfun.hpp"

namespace SPACOX {

SPACOXClass::SPACOXClass(arma::mat t_cumul,
                         arma::vec t_mresid,
                         arma::mat t_XinvXX,
                         arma::mat t_tX,
                         int t_N,
                         double t_pVal_covaAdj_Cutoff,
                         double t_pVal_SPA_Cutoff)
{
  m_mresid = t_mresid;
  m_varResid = var(m_mresid);
  m_XinvXX = t_XinvXX;
  m_tX = t_tX;
  m_N = t_N;
  m_pVal_covaAdj_Cutoff = t_pVal_covaAdj_Cutoff;
  m_pVal_SPA_Cutoff = t_pVal_SPA_Cutoff;
  
  m_K_0_emp.setApproxFun(t_cumul.col(1), t_cumul.col(2));
  m_K_1_emp.setApproxFun(t_cumul.col(1), t_cumul.col(2));
  m_K_2_emp.setApproxFun(t_cumul.col(1), t_cumul.col(2));
}

}
