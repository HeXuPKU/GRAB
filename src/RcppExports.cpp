// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// setSparseGRMInCPP
void setSparseGRMInCPP(Rcpp::List t_KinMatListR);
RcppExport SEXP _GRAB_setSparseGRMInCPP(SEXP t_KinMatListRSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type t_KinMatListR(t_KinMatListRSEXP);
    setSparseGRMInCPP(t_KinMatListR);
    return R_NilValue;
END_RCPP
}
// setDenseGRMInCPP
void setDenseGRMInCPP(double t_memoryChunk, double t_minMafGRM, double t_maxMissingGRM);
RcppExport SEXP _GRAB_setDenseGRMInCPP(SEXP t_memoryChunkSEXP, SEXP t_minMafGRMSEXP, SEXP t_maxMissingGRMSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type t_memoryChunk(t_memoryChunkSEXP);
    Rcpp::traits::input_parameter< double >::type t_minMafGRM(t_minMafGRMSEXP);
    Rcpp::traits::input_parameter< double >::type t_maxMissingGRM(t_maxMissingGRMSEXP);
    setDenseGRMInCPP(t_memoryChunk, t_minMafGRM, t_maxMissingGRM);
    return R_NilValue;
END_RCPP
}
// getDenseGRMInCPP
arma::vec getDenseGRMInCPP(arma::vec t_bVec, std::string t_excludeChr, int t_grainSize);
RcppExport SEXP _GRAB_getDenseGRMInCPP(SEXP t_bVecSEXP, SEXP t_excludeChrSEXP, SEXP t_grainSizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type t_bVec(t_bVecSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_excludeChr(t_excludeChrSEXP);
    Rcpp::traits::input_parameter< int >::type t_grainSize(t_grainSizeSEXP);
    rcpp_result_gen = Rcpp::wrap(getDenseGRMInCPP(t_bVec, t_excludeChr, t_grainSize));
    return rcpp_result_gen;
END_RCPP
}
// setMarker_GlobalVarsInCPP
void setMarker_GlobalVarsInCPP(std::string t_impute_method, double t_missing_cutoff, double t_min_maf_marker, double t_min_mac_marker, unsigned int t_omp_num_threads);
RcppExport SEXP _GRAB_setMarker_GlobalVarsInCPP(SEXP t_impute_methodSEXP, SEXP t_missing_cutoffSEXP, SEXP t_min_maf_markerSEXP, SEXP t_min_mac_markerSEXP, SEXP t_omp_num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_impute_method(t_impute_methodSEXP);
    Rcpp::traits::input_parameter< double >::type t_missing_cutoff(t_missing_cutoffSEXP);
    Rcpp::traits::input_parameter< double >::type t_min_maf_marker(t_min_maf_markerSEXP);
    Rcpp::traits::input_parameter< double >::type t_min_mac_marker(t_min_mac_markerSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type t_omp_num_threads(t_omp_num_threadsSEXP);
    setMarker_GlobalVarsInCPP(t_impute_method, t_missing_cutoff, t_min_maf_marker, t_min_mac_marker, t_omp_num_threads);
    return R_NilValue;
END_RCPP
}
// setRegion_GlobalVarsInCPP
void setRegion_GlobalVarsInCPP(std::string t_impute_method, double t_missing_cutoff, double t_max_maf_region, double t_min_mac_region, unsigned int t_max_markers_region, unsigned int t_omp_num_threads);
RcppExport SEXP _GRAB_setRegion_GlobalVarsInCPP(SEXP t_impute_methodSEXP, SEXP t_missing_cutoffSEXP, SEXP t_max_maf_regionSEXP, SEXP t_min_mac_regionSEXP, SEXP t_max_markers_regionSEXP, SEXP t_omp_num_threadsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_impute_method(t_impute_methodSEXP);
    Rcpp::traits::input_parameter< double >::type t_missing_cutoff(t_missing_cutoffSEXP);
    Rcpp::traits::input_parameter< double >::type t_max_maf_region(t_max_maf_regionSEXP);
    Rcpp::traits::input_parameter< double >::type t_min_mac_region(t_min_mac_regionSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type t_max_markers_region(t_max_markers_regionSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type t_omp_num_threads(t_omp_num_threadsSEXP);
    setRegion_GlobalVarsInCPP(t_impute_method, t_missing_cutoff, t_max_maf_region, t_min_mac_region, t_max_markers_region, t_omp_num_threads);
    return R_NilValue;
END_RCPP
}
// mainMarkerInCPP
Rcpp::List mainMarkerInCPP(std::string t_method, std::string t_genoType, std::vector<uint32_t> t_genoIndex);
RcppExport SEXP _GRAB_mainMarkerInCPP(SEXP t_methodSEXP, SEXP t_genoTypeSEXP, SEXP t_genoIndexSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_method(t_methodSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_genoType(t_genoTypeSEXP);
    Rcpp::traits::input_parameter< std::vector<uint32_t> >::type t_genoIndex(t_genoIndexSEXP);
    rcpp_result_gen = Rcpp::wrap(mainMarkerInCPP(t_method, t_genoType, t_genoIndex));
    return rcpp_result_gen;
END_RCPP
}
// mainRegionInCPP
Rcpp::List mainRegionInCPP(std::string t_method, std::string t_genoType, std::vector<uint32_t> t_genoIndex, std::string t_outputFile, unsigned int t_n, arma::mat P1Mat, arma::mat P2Mat);
RcppExport SEXP _GRAB_mainRegionInCPP(SEXP t_methodSEXP, SEXP t_genoTypeSEXP, SEXP t_genoIndexSEXP, SEXP t_outputFileSEXP, SEXP t_nSEXP, SEXP P1MatSEXP, SEXP P2MatSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_method(t_methodSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_genoType(t_genoTypeSEXP);
    Rcpp::traits::input_parameter< std::vector<uint32_t> >::type t_genoIndex(t_genoIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_outputFile(t_outputFileSEXP);
    Rcpp::traits::input_parameter< unsigned int >::type t_n(t_nSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type P1Mat(P1MatSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type P2Mat(P2MatSEXP);
    rcpp_result_gen = Rcpp::wrap(mainRegionInCPP(t_method, t_genoType, t_genoIndex, t_outputFile, t_n, P1Mat, P2Mat));
    return rcpp_result_gen;
END_RCPP
}
// getGenoInCPP
arma::mat getGenoInCPP(std::string t_genoType, Rcpp::DataFrame t_markerInfo, int n, std::string t_imputeMethod);
RcppExport SEXP _GRAB_getGenoInCPP(SEXP t_genoTypeSEXP, SEXP t_markerInfoSEXP, SEXP nSEXP, SEXP t_imputeMethodSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_genoType(t_genoTypeSEXP);
    Rcpp::traits::input_parameter< Rcpp::DataFrame >::type t_markerInfo(t_markerInfoSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_imputeMethod(t_imputeMethodSEXP);
    rcpp_result_gen = Rcpp::wrap(getGenoInCPP(t_genoType, t_markerInfo, n, t_imputeMethod));
    return rcpp_result_gen;
END_RCPP
}
// getSpGenoInCPP
arma::sp_mat getSpGenoInCPP(std::string t_genoType, Rcpp::DataFrame t_markerInfo, int n, std::string t_imputeMethod);
RcppExport SEXP _GRAB_getSpGenoInCPP(SEXP t_genoTypeSEXP, SEXP t_markerInfoSEXP, SEXP nSEXP, SEXP t_imputeMethodSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_genoType(t_genoTypeSEXP);
    Rcpp::traits::input_parameter< Rcpp::DataFrame >::type t_markerInfo(t_markerInfoSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_imputeMethod(t_imputeMethodSEXP);
    rcpp_result_gen = Rcpp::wrap(getSpGenoInCPP(t_genoType, t_markerInfo, n, t_imputeMethod));
    return rcpp_result_gen;
END_RCPP
}
// setPLINKobjInCPP
void setPLINKobjInCPP(std::string t_bimFile, std::string t_famFile, std::string t_bedFile, std::vector<std::string> t_SampleInModel, std::string t_AlleleOrder);
RcppExport SEXP _GRAB_setPLINKobjInCPP(SEXP t_bimFileSEXP, SEXP t_famFileSEXP, SEXP t_bedFileSEXP, SEXP t_SampleInModelSEXP, SEXP t_AlleleOrderSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_bimFile(t_bimFileSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_famFile(t_famFileSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_bedFile(t_bedFileSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type t_SampleInModel(t_SampleInModelSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_AlleleOrder(t_AlleleOrderSEXP);
    setPLINKobjInCPP(t_bimFile, t_famFile, t_bedFile, t_SampleInModel, t_AlleleOrder);
    return R_NilValue;
END_RCPP
}
// setBGENobjInCPP
void setBGENobjInCPP(std::string t_bgenFileName, std::string t_bgenFileIndex, std::vector<std::string> t_SampleInBgen, std::vector<std::string> t_SampleInModel, bool t_isSparseDosageInBgen, bool t_isDropmissingdosagesInBgen, std::string t_AlleleOrder);
RcppExport SEXP _GRAB_setBGENobjInCPP(SEXP t_bgenFileNameSEXP, SEXP t_bgenFileIndexSEXP, SEXP t_SampleInBgenSEXP, SEXP t_SampleInModelSEXP, SEXP t_isSparseDosageInBgenSEXP, SEXP t_isDropmissingdosagesInBgenSEXP, SEXP t_AlleleOrderSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type t_bgenFileName(t_bgenFileNameSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_bgenFileIndex(t_bgenFileIndexSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type t_SampleInBgen(t_SampleInBgenSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type t_SampleInModel(t_SampleInModelSEXP);
    Rcpp::traits::input_parameter< bool >::type t_isSparseDosageInBgen(t_isSparseDosageInBgenSEXP);
    Rcpp::traits::input_parameter< bool >::type t_isDropmissingdosagesInBgen(t_isDropmissingdosagesInBgenSEXP);
    Rcpp::traits::input_parameter< std::string >::type t_AlleleOrder(t_AlleleOrderSEXP);
    setBGENobjInCPP(t_bgenFileName, t_bgenFileIndex, t_SampleInBgen, t_SampleInModel, t_isSparseDosageInBgen, t_isDropmissingdosagesInBgen, t_AlleleOrder);
    return R_NilValue;
END_RCPP
}
// setPOLMMobjInCPP
void setPOLMMobjInCPP(arma::mat t_muMat, arma::mat t_iRMat, arma::mat t_Cova, arma::uvec t_yVec, double t_tau, bool t_printPCGInfo, double t_tolPCG, int t_maxiterPCG, double t_varRatio, double t_SPA_cutoff, bool t_flagSparseGRM);
RcppExport SEXP _GRAB_setPOLMMobjInCPP(SEXP t_muMatSEXP, SEXP t_iRMatSEXP, SEXP t_CovaSEXP, SEXP t_yVecSEXP, SEXP t_tauSEXP, SEXP t_printPCGInfoSEXP, SEXP t_tolPCGSEXP, SEXP t_maxiterPCGSEXP, SEXP t_varRatioSEXP, SEXP t_SPA_cutoffSEXP, SEXP t_flagSparseGRMSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type t_muMat(t_muMatSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_iRMat(t_iRMatSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_Cova(t_CovaSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type t_yVec(t_yVecSEXP);
    Rcpp::traits::input_parameter< double >::type t_tau(t_tauSEXP);
    Rcpp::traits::input_parameter< bool >::type t_printPCGInfo(t_printPCGInfoSEXP);
    Rcpp::traits::input_parameter< double >::type t_tolPCG(t_tolPCGSEXP);
    Rcpp::traits::input_parameter< int >::type t_maxiterPCG(t_maxiterPCGSEXP);
    Rcpp::traits::input_parameter< double >::type t_varRatio(t_varRatioSEXP);
    Rcpp::traits::input_parameter< double >::type t_SPA_cutoff(t_SPA_cutoffSEXP);
    Rcpp::traits::input_parameter< bool >::type t_flagSparseGRM(t_flagSparseGRMSEXP);
    setPOLMMobjInCPP(t_muMat, t_iRMat, t_Cova, t_yVec, t_tau, t_printPCGInfo, t_tolPCG, t_maxiterPCG, t_varRatio, t_SPA_cutoff, t_flagSparseGRM);
    return R_NilValue;
END_RCPP
}
// setPOLMMobjInCPP_NULL
Rcpp::List setPOLMMobjInCPP_NULL(bool t_flagSparseGRM, arma::mat t_Cova, arma::uvec t_yVec, arma::vec t_beta, arma::vec t_bVec, arma::vec t_eps, double t_tau, Rcpp::List t_SPmatR, Rcpp::List t_controlList);
RcppExport SEXP _GRAB_setPOLMMobjInCPP_NULL(SEXP t_flagSparseGRMSEXP, SEXP t_CovaSEXP, SEXP t_yVecSEXP, SEXP t_betaSEXP, SEXP t_bVecSEXP, SEXP t_epsSEXP, SEXP t_tauSEXP, SEXP t_SPmatRSEXP, SEXP t_controlListSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< bool >::type t_flagSparseGRM(t_flagSparseGRMSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_Cova(t_CovaSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type t_yVec(t_yVecSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type t_beta(t_betaSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type t_bVec(t_bVecSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type t_eps(t_epsSEXP);
    Rcpp::traits::input_parameter< double >::type t_tau(t_tauSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type t_SPmatR(t_SPmatRSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type t_controlList(t_controlListSEXP);
    rcpp_result_gen = Rcpp::wrap(setPOLMMobjInCPP_NULL(t_flagSparseGRM, t_Cova, t_yVec, t_beta, t_bVec, t_eps, t_tau, t_SPmatR, t_controlList));
    return rcpp_result_gen;
END_RCPP
}
// setSPACoxobjInCPP
void setSPACoxobjInCPP(arma::mat t_cumul, arma::vec t_mresid, arma::mat t_XinvXX, arma::mat t_tX, int t_N, double t_pVal_covaAdj_Cutoff, double t_SPA_Cutoff);
RcppExport SEXP _GRAB_setSPACoxobjInCPP(SEXP t_cumulSEXP, SEXP t_mresidSEXP, SEXP t_XinvXXSEXP, SEXP t_tXSEXP, SEXP t_NSEXP, SEXP t_pVal_covaAdj_CutoffSEXP, SEXP t_SPA_CutoffSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type t_cumul(t_cumulSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type t_mresid(t_mresidSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_XinvXX(t_XinvXXSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type t_tX(t_tXSEXP);
    Rcpp::traits::input_parameter< int >::type t_N(t_NSEXP);
    Rcpp::traits::input_parameter< double >::type t_pVal_covaAdj_Cutoff(t_pVal_covaAdj_CutoffSEXP);
    Rcpp::traits::input_parameter< double >::type t_SPA_Cutoff(t_SPA_CutoffSEXP);
    setSPACoxobjInCPP(t_cumul, t_mresid, t_XinvXX, t_tX, t_N, t_pVal_covaAdj_Cutoff, t_SPA_Cutoff);
    return R_NilValue;
END_RCPP
}
// squares
std::vector<double> squares(Rcpp::NumericVector data);
RcppExport SEXP _GRAB_squares(SEXP dataSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type data(dataSEXP);
    rcpp_result_gen = Rcpp::wrap(squares(data));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_GRAB_setSparseGRMInCPP", (DL_FUNC) &_GRAB_setSparseGRMInCPP, 1},
    {"_GRAB_setDenseGRMInCPP", (DL_FUNC) &_GRAB_setDenseGRMInCPP, 3},
    {"_GRAB_getDenseGRMInCPP", (DL_FUNC) &_GRAB_getDenseGRMInCPP, 3},
    {"_GRAB_setMarker_GlobalVarsInCPP", (DL_FUNC) &_GRAB_setMarker_GlobalVarsInCPP, 5},
    {"_GRAB_setRegion_GlobalVarsInCPP", (DL_FUNC) &_GRAB_setRegion_GlobalVarsInCPP, 6},
    {"_GRAB_mainMarkerInCPP", (DL_FUNC) &_GRAB_mainMarkerInCPP, 3},
    {"_GRAB_mainRegionInCPP", (DL_FUNC) &_GRAB_mainRegionInCPP, 7},
    {"_GRAB_getGenoInCPP", (DL_FUNC) &_GRAB_getGenoInCPP, 4},
    {"_GRAB_getSpGenoInCPP", (DL_FUNC) &_GRAB_getSpGenoInCPP, 4},
    {"_GRAB_setPLINKobjInCPP", (DL_FUNC) &_GRAB_setPLINKobjInCPP, 5},
    {"_GRAB_setBGENobjInCPP", (DL_FUNC) &_GRAB_setBGENobjInCPP, 7},
    {"_GRAB_setPOLMMobjInCPP", (DL_FUNC) &_GRAB_setPOLMMobjInCPP, 11},
    {"_GRAB_setPOLMMobjInCPP_NULL", (DL_FUNC) &_GRAB_setPOLMMobjInCPP_NULL, 9},
    {"_GRAB_setSPACoxobjInCPP", (DL_FUNC) &_GRAB_setSPACoxobjInCPP, 7},
    {"_GRAB_squares", (DL_FUNC) &_GRAB_squares, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_GRAB(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
