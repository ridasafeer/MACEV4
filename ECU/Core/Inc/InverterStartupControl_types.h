/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: InverterStartupControl_types.h
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

#ifndef RTW_HEADER_InverterStartupControl_types_h_
#define RTW_HEADER_InverterStartupControl_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_MI_STATUSES_
#define DEFINED_TYPEDEF_FOR_MI_STATUSES_

typedef enum {
  UNKNOWN = 0,                         /* Default value */
  STS_INIT,
  STARTUP,
  RUNNING,
  SHUTDOWN,
  MI_STS_ERROR,
  OFF
} MI_STATUSES;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MI_CMD_
#define DEFINED_TYPEDEF_FOR_MI_CMD_

typedef enum {
  CMD_INIT = 0,                        /* Default value */
  IDLE,
  CMD_STARTUP,
  CMD_SHUTDOWN,
  ERR_RESET
} MI_CMD;

#endif

/* Parameters (default storage) */
typedef struct P_InverterStartupControl_T_ P_InverterStartupControl_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_InverterStartupContro_T RT_MODEL_InverterStartupContr_T;

#endif                          /* RTW_HEADER_InverterStartupControl_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
