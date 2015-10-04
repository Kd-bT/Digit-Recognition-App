/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_digit_nn_predict_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 29-Sep-2015 21:33:52
 */

#ifndef ___CODER_DIGIT_NN_PREDICT_API_H__
#define ___CODER_DIGIT_NN_PREDICT_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_digit_nn_predict_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T digit_nn_predict(real_T X[784]);
extern void digit_nn_predict_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void digit_nn_predict_atexit(void);
extern void digit_nn_predict_initialize(void);
extern void digit_nn_predict_terminate(void);
extern void digit_nn_predict_xil_terminate(void);

#endif

/*
 * File trailer for _coder_digit_nn_predict_api.h
 *
 * [EOF]
 */
