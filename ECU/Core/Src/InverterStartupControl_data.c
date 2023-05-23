/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: InverterStartupControl_data.c
 *
 * Code generated for Simulink model 'InverterStartupControl'.
 *
 * Model version                  : 1.142
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun May 21 19:01:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "InverterStartupControl.h"

/* Invariant block signals (default storage) */
const ConstB_InverterStartupControl_T InverterStartupControl_ConstB = {
  6.0                                  /* '<S3>/Width' */
};

/* Block parameters (default storage) */
P_InverterStartupControl_T InverterStartupControl_P = {
  /* Mask Parameter: TappedDelay_vinit
   * Referenced by: '<S3>/Tapped Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S1>/Constant1'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S1>/Constant6'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant7'
   */
  0.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S1>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S1>/Manual Switch1'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
