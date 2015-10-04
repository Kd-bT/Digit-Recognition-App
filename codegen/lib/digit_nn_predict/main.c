/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 29-Sep-2015 21:33:52
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "digit_nn_predict.h"
#include "main.h"
#include "digit_nn_predict_terminate.h"
#include "digit_nn_predict_initialize.h"

#include <stdio.h>

/* Function Declarations */
static void argInit_1x784_real_T(double result[784]);
static double argInit_real_T(void);
static void main_digit_nn_predict(void);

/* Function Definitions */

/*
 * Arguments    : double result[784]
 * Return Type  : void
 */
static void argInit_1x784_real_T(double result[784])
{
  int b_j1;

  /* Loop over the array to initialize each element. */
  for (b_j1 = 0; b_j1 < 784; b_j1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[b_j1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_digit_nn_predict(void)
{
  double dv2[784];
  double p;

  /* Initialize function 'digit_nn_predict' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'digit_nn_predict'. */
  argInit_1x784_real_T(dv2);
  p = digit_nn_predict(dv2);
  printf("%f\n", p);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  digit_nn_predict_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_digit_nn_predict();

  /* Terminate the application.
     You do not need to do this more than one time. */
  digit_nn_predict_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
