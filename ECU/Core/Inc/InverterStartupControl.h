/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: InverterStartupControl.h
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

#ifndef RTW_HEADER_InverterStartupControl_h_
#define RTW_HEADER_InverterStartupControl_h_
#ifndef InverterStartupControl_COMMON_INCLUDES_
#define InverterStartupControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                             /* InverterStartupControl_COMMON_INCLUDES_ */

#include "InverterStartupControl_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S4>/LEFT_MOTOR' */
typedef struct {
  uint8_T is_c2_InverterStartupControl;/* '<S4>/LEFT_MOTOR' */
  uint8_T is_AMK_startup;              /* '<S4>/LEFT_MOTOR' */
  uint8_T is_AMK_errorReset;           /* '<S4>/LEFT_MOTOR' */
  uint8_T is_AMK_shutdown;             /* '<S4>/LEFT_MOTOR' */
  uint8_T is_active_c2_InverterStartupCon;/* '<S4>/LEFT_MOTOR' */
  uint8_T temporalCounter_i1;          /* '<S4>/LEFT_MOTOR' */
} DW_LEFT_MOTOR_InverterStartup_T;

/* Block signals (default storage) */
typedef struct {
  real_T VectorConcatenate[6];         /* '<S3>/Vector Concatenate' */
} B_InverterStartupControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TappedDelay_X[5];             /* '<S3>/Tapped Delay' */
  uint8_T is_c1_InverterStartupControl;/* '<S1>/Chart' */
  uint8_T is_active_c1_InverterStartupCon;/* '<S1>/Chart' */
  DW_LEFT_MOTOR_InverterStartup_T sf_RIGHT_MOTOR;/* '<S4>/RIGHT_MOTOR' */
  DW_LEFT_MOTOR_InverterStartup_T sf_LEFT_MOTOR;/* '<S4>/LEFT_MOTOR' */
} DW_InverterStartupControl_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Width;                  /* '<S3>/Width' */
} ConstB_InverterStartupControl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T APPS;                         /* '<Root>/APPS' */
  real_T AMK_ActualVelocity_R;         /* '<Root>/In1' */
  real_T AMK_MagnetizingCurrent_R;     /* '<Root>/In2' */
  real_T AMK_TorqueCurrent_R;          /* '<Root>/In3' */
  real_T AMK_bDcOn_R;                  /* '<Root>/In4' */
  real_T AMK_bDerating_R;              /* '<Root>/In5' */
  real_T AMK_bError_R;                 /* '<Root>/In6' */
  real_T AMK_bInverterOn_R;            /* '<Root>/In7' */
  real_T AMK_bQuitDcOn_R;              /* '<Root>/In8' */
  real_T AMK_bQuitInverterOn_R;        /* '<Root>/In9' */
  real_T AMK_bSystemReady_R;           /* '<Root>/In10' */
  real_T AMK_bWarn_R;                  /* '<Root>/In11' */
  real_T AMK_ErrorInfo_R;              /* '<Root>/In12' */
  real_T AMK_TempIGBT_R;               /* '<Root>/In13' */
  real_T AMK_TempInverter_R;           /* '<Root>/In14' */
  real_T AMK_TempMotor_R;              /* '<Root>/In15' */
  real_T AMK_ActualVelocity_L;         /* '<Root>/In16' */
  real_T AMK_MagnetizingCurrent_L;     /* '<Root>/In17' */
  real_T AMK_TorqueCurrent_L;          /* '<Root>/In18' */
  real_T AMK_bDcOn_L;                  /* '<Root>/In19' */
  real_T AMK_bDerating_L;              /* '<Root>/In20' */
  real_T AMK_bError_L;                 /* '<Root>/In21' */
  real_T AMK_bInverterOn_L;            /* '<Root>/In22' */
  real_T AMK_bQuitDcOn_L;              /* '<Root>/In23' */
  real_T AMK_bQuitInverterOn_L;        /* '<Root>/In24' */
  real_T AMK_bSystemReady_L;           /* '<Root>/In25' */
  real_T AMK_bWarn_L;                  /* '<Root>/In26' */
  real_T AMK_ErrorInfo_L;              /* '<Root>/In27' */
  real_T AMK_TempIGBT_L;               /* '<Root>/In28' */
  real_T AMK_TempInverter_L;           /* '<Root>/In29' */
  real_T AMK_TempMotor_L;              /* '<Root>/In30' */
} ExtU_InverterStartupControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_T AMK_bInverterOn_R;           /* '<Root>/AMK_bInverterOn_R' */
  uint8_T AMK_bDcOn_R;                 /* '<Root>/AMK_bDcOn_R' */
  uint8_T AMK_bEnable_R;               /* '<Root>/AMK_bEnable_R' */
  uint8_T AMK_bErrorReset_R;           /* '<Root>/AMK_bErrorReset_R' */
  real32_T AMK_TargetVelocity_R;       /* '<Root>/AMK_TargetVelocity_R' */
  real32_T AMK_TorqueLimitPositiv_R;   /* '<Root>/AMK_TorqueLimitPositiv_R' */
  real32_T AMK_TorqueLimitNegativ_R;   /* '<Root>/AMK_TorqueLimitNegativ_R' */
  uint8_T AMK_bInverterOn_L;           /* '<Root>/AMK_bInverterOn_L' */
  uint8_T AMK_bDcOn_L;                 /* '<Root>/AMK_bDcOn_L' */
  uint8_T AMK_bEnable_L;               /* '<Root>/AMK_bEnable_L' */
  uint8_T AMK_bErrorReset_L;           /* '<Root>/AMK_bErrorReset_L' */
  real32_T AMK_TargetVelocity_L;       /* '<Root>/AMK_TargetVelocity_L' */
  real32_T AMK_TorqueLimitPositiv_L;   /* '<Root>/AMK_TorqueLimitPositiv_L' */
  real32_T AMK_TorqueLimitNegativ_L;   /* '<Root>/AMK_TorqueLimitNegativ_L' */
} ExtY_InverterStartupControl_T;

/* Parameters (default storage) */
struct P_InverterStartupControl_T_ {
  real_T TappedDelay_vinit;            /* Mask Parameter: TappedDelay_vinit
                                        * Referenced by: '<S3>/Tapped Delay'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant11_Value;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant11'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 50
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 50
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant7'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S1>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_InverterStartupContro_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_InverterStartupControl_T InverterStartupControl_P;

/* Block signals (default storage) */
extern B_InverterStartupControl_T InverterStartupControl_B;

/* Block states (default storage) */
extern DW_InverterStartupControl_T InverterStartupControl_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_InverterStartupControl_T InverterStartupControl_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_InverterStartupControl_T InverterStartupControl_Y;
extern const ConstB_InverterStartupControl_T InverterStartupControl_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void InverterStartupControl_initialize(void);
extern void InverterStartupControl_step(void*);
extern void InverterStartupControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_InverterStartupContr_T *const InverterStartupControl_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S4>/Delay' : Unused code path elimination
 * Block '<S4>/GreaterThan' : Unused code path elimination
 * Block '<S4>/OR' : Unused code path elimination
 * Block '<S4>/Switch' : Unused code path elimination
 * Block '<S4>/motorErrorActive' : Unused code path elimination
 * Block '<S4>/motorErrorActive1' : Unused code path elimination
 * Block '<S4>/overallMotorState' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'InverterStartupControl'
 * '<S1>'   : 'InverterStartupControl/Control'
 * '<S2>'   : 'InverterStartupControl/Control/Chart'
 * '<S3>'   : 'InverterStartupControl/Control/Running Avg'
 * '<S4>'   : 'InverterStartupControl/Control/motor_interface'
 * '<S5>'   : 'InverterStartupControl/Control/motor_interface/LEFT_MOTOR'
 * '<S6>'   : 'InverterStartupControl/Control/motor_interface/RIGHT_MOTOR'
 */
#endif                                /* RTW_HEADER_InverterStartupControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
