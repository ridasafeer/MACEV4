/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: InverterStartupControl_private.h
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

#ifndef RTW_HEADER_InverterStartupControl_private_h_
#define RTW_HEADER_InverterStartupControl_private_h_
#include "rtwtypes.h"
#include "InverterStartupControl_types.h"
#include "InverterStartupControl.h"

extern void InverterStartup_LEFT_MOTOR_Init(MI_STATUSES *rty_MI_motorStatus,
  uint8_T *rty_AMK_bInverterOn_tx, uint8_T *rty_AMK_bDcOn_tx, uint8_T
  *rty_AMK_bEnable, uint8_T *rty_AMK_bErrorReset, real32_T
  *rty_AMK_TargetVelocity, real32_T *rty_AMK_TorqueLimitPositiv, real32_T
  *rty_AMK_TorqueLimitNegativ);
extern void InverterStartupContr_LEFT_MOTOR(MI_CMD rtu_GOV_e_miCmd, real_T
  rtu_AMK_bSystemReady, real_T rtu_AMK_bError, real_T rtu_AMK_bQuitDcOn, real_T
  rtu_AMK_bDcOn_rx, real_T rtu_AMK_bQuitInverterOn, real_T
  rtu_AMK_bInverterOn_rx, real32_T rtu_VD_T_motorSpeedRequest, real32_T
  rtu_VD_T_motorTorqueLimitPositi, real32_T rtu_VD_T_motorTorqueLimitNegati,
  MI_STATUSES *rty_MI_motorStatus, uint8_T *rty_AMK_bInverterOn_tx, uint8_T
  *rty_AMK_bDcOn_tx, uint8_T *rty_AMK_bEnable, uint8_T *rty_AMK_bErrorReset,
  real32_T *rty_AMK_TargetVelocity, real32_T *rty_AMK_TorqueLimitPositiv,
  real32_T *rty_AMK_TorqueLimitNegativ, DW_LEFT_MOTOR_InverterStartup_T *localDW);

#endif                        /* RTW_HEADER_InverterStartupControl_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
