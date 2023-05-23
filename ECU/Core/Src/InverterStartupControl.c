/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: InverterStartupControl.c
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
#include "InverterStartupControl_types.h"
#include "rtwtypes.h"
#include "InverterStartupControl_private.h"

/* Named constants for Chart: '<S4>/LEFT_MOTOR' */
#define Inver_IN_enforceSetpointsZero_b ((uint8_T)1U)
#define Inver_IN_motorOff_waitingForGov ((uint8_T)6U)
#define Inverte_IN_enforceSetpointsZero ((uint8_T)2U)
#define InverterSt_IN_AMK_errorDetected ((uint8_T)1U)
#define InverterSta_IN_waiting_sysReady ((uint8_T)4U)
#define InverterStar_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define InverterStart_IN_AMK_errorReset ((uint8_T)2U)
#define InverterStartupC_IN_AMK_running ((uint8_T)3U)
#define InverterStartupC_IN_AMK_startup ((uint8_T)5U)
#define InverterStartupC_IN_toggleReset ((uint8_T)4U)
#define InverterStartupCo_IN_commandOff ((uint8_T)1U)
#define InverterStartupCo_IN_toggleDCon ((uint8_T)3U)
#define InverterStartupCon_IN_commandOn ((uint8_T)1U)
#define InverterStartupCon_IN_sendReset ((uint8_T)2U)
#define InverterStartup_IN_AMK_shutdown ((uint8_T)4U)
#define InverterStartup_IN_toggleEnable ((uint8_T)3U)

/* Named constants for Chart: '<S1>/Chart' */
#define InverterStartupCont_IN_Shutdown ((uint8_T)5U)
#define InverterStartupContro_IN_Error0 ((uint8_T)1U)
#define InverterStartupContro_IN_Error1 ((uint8_T)2U)
#define InverterStartupControl_IN_Init ((uint8_T)3U)
#define InverterStartupControl_IN_Run  ((uint8_T)4U)

/* Block signals (default storage) */
B_InverterStartupControl_T InverterStartupControl_B;

/* Block states (default storage) */
DW_InverterStartupControl_T InverterStartupControl_DW;

/* External inputs (root inport signals with default storage) */
ExtU_InverterStartupControl_T InverterStartupControl_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_InverterStartupControl_T InverterStartupControl_Y;

/* Real-time model */
static RT_MODEL_InverterStartupContr_T InverterStartupControl_M_;
RT_MODEL_InverterStartupContr_T *const InverterStartupControl_M =
  &InverterStartupControl_M_;

/*
 * System initialize for atomic system:
 *    '<S4>/LEFT_MOTOR'
 *    '<S4>/RIGHT_MOTOR'
 */
void InverterStartup_LEFT_MOTOR_Init(MI_STATUSES *rty_MI_motorStatus, uint8_T
  *rty_AMK_bInverterOn_tx, uint8_T *rty_AMK_bDcOn_tx, uint8_T *rty_AMK_bEnable,
  uint8_T *rty_AMK_bErrorReset, real32_T *rty_AMK_TargetVelocity, real32_T
  *rty_AMK_TorqueLimitPositiv, real32_T *rty_AMK_TorqueLimitNegativ)
{
  *rty_MI_motorStatus = UNKNOWN;
  *rty_AMK_bInverterOn_tx = 0U;
  *rty_AMK_bDcOn_tx = 0U;
  *rty_AMK_bEnable = 0U;
  *rty_AMK_bErrorReset = 0U;
  *rty_AMK_TargetVelocity = 0.0F;
  *rty_AMK_TorqueLimitPositiv = 0.0F;
  *rty_AMK_TorqueLimitNegativ = 0.0F;
}

/*
 * Output and update for atomic system:
 *    '<S4>/LEFT_MOTOR'
 *    '<S4>/RIGHT_MOTOR'
 */
void InverterStartupContr_LEFT_MOTOR(MI_CMD rtu_GOV_e_miCmd, real_T
  rtu_AMK_bSystemReady, real_T rtu_AMK_bError, real_T rtu_AMK_bQuitDcOn, real_T
  rtu_AMK_bDcOn_rx, real_T rtu_AMK_bQuitInverterOn, real_T
  rtu_AMK_bInverterOn_rx, real32_T rtu_VD_T_motorSpeedRequest, real32_T
  rtu_VD_T_motorTorqueLimitPositi, real32_T rtu_VD_T_motorTorqueLimitNegati,
  MI_STATUSES *rty_MI_motorStatus, uint8_T *rty_AMK_bInverterOn_tx, uint8_T
  *rty_AMK_bDcOn_tx, uint8_T *rty_AMK_bEnable, uint8_T *rty_AMK_bErrorReset,
  real32_T *rty_AMK_TargetVelocity, real32_T *rty_AMK_TorqueLimitPositiv,
  real32_T *rty_AMK_TorqueLimitNegativ, DW_LEFT_MOTOR_InverterStartup_T *localDW)
{
  if (localDW->temporalCounter_i1 < 255U) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S4>/LEFT_MOTOR' */
  /* Gateway: Control/motor_interface/LEFT_MOTOR */
  /* During: Control/motor_interface/LEFT_MOTOR */
  if (localDW->is_active_c2_InverterStartupCon == 0U) {
    /* Entry: Control/motor_interface/LEFT_MOTOR */
    localDW->is_active_c2_InverterStartupCon = 1U;

    /* Entry Internal: Control/motor_interface/LEFT_MOTOR */
    /* Transition: '<S5>:30' */
    localDW->is_c2_InverterStartupControl = Inver_IN_motorOff_waitingForGov;

    /* Entry 'motorOff_waitingForGov': '<S5>:31' */
    *rty_MI_motorStatus = OFF;
    *rty_AMK_bInverterOn_tx = 0U;
    *rty_AMK_bDcOn_tx = 0U;
    *rty_AMK_bEnable = 0U;
    *rty_AMK_bErrorReset = 0U;
    *rty_AMK_TargetVelocity = 0.0F;
    *rty_AMK_TorqueLimitPositiv = 0.0F;
    *rty_AMK_TorqueLimitNegativ = 0.0F;
  } else {
    switch (localDW->is_c2_InverterStartupControl) {
     case InverterSt_IN_AMK_errorDetected:
      /* During 'AMK_errorDetected': '<S5>:81' */
      if (rtu_GOV_e_miCmd == ERR_RESET) {
        /* Transition: '<S5>:90' */
        localDW->is_c2_InverterStartupControl = InverterStart_IN_AMK_errorReset;
        localDW->is_AMK_errorReset = Inver_IN_enforceSetpointsZero_b;

        /* Entry 'enforceSetpointsZero': '<S5>:114' */
        *rty_AMK_TargetVelocity = 0.0F;
        *rty_AMK_TorqueLimitPositiv = 0.0F;
        *rty_AMK_TorqueLimitNegativ = 0.0F;
        *rty_AMK_bInverterOn_tx = 0U;
      }
      break;

     case InverterStart_IN_AMK_errorReset:
      /* During 'AMK_errorReset': '<S5>:89' */
      switch (localDW->is_AMK_errorReset) {
       case Inver_IN_enforceSetpointsZero_b:
        *rty_AMK_bInverterOn_tx = 0U;

        /* During 'enforceSetpointsZero': '<S5>:114' */
        if (rtu_AMK_bInverterOn_rx == 0.0) {
          /* Transition: '<S5>:123' */
          localDW->is_AMK_errorReset = InverterStartup_IN_toggleEnable;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'toggleEnable': '<S5>:122' */
          *rty_AMK_bEnable = 0U;
        }
        break;

       case InverterStartupCon_IN_sendReset:
        *rty_AMK_bErrorReset = 1U;

        /* During 'sendReset': '<S5>:128' */
        if (localDW->temporalCounter_i1 >= 100U) {
          /* Transition: '<S5>:132' */
          localDW->is_AMK_errorReset = InverterStartupC_IN_toggleReset;

          /* Entry 'toggleReset': '<S5>:131' */
          *rty_AMK_bErrorReset = 0U;
        }
        break;

       case InverterStartup_IN_toggleEnable:
        *rty_AMK_bEnable = 0U;

        /* During 'toggleEnable': '<S5>:122' */
        if (localDW->temporalCounter_i1 >= 100U) {
          /* Transition: '<S5>:127' */
          localDW->is_AMK_errorReset = InverterStartupCon_IN_sendReset;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'sendReset': '<S5>:128' */
          *rty_AMK_bErrorReset = 1U;
        }
        break;

       default:
        *rty_AMK_bErrorReset = 0U;

        /* During 'toggleReset': '<S5>:131' */
        if (rtu_AMK_bSystemReady == 1.0) {
          /* Transition: '<S5>:133' */
          localDW->is_AMK_errorReset = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            Inver_IN_motorOff_waitingForGov;

          /* Entry 'motorOff_waitingForGov': '<S5>:31' */
          *rty_MI_motorStatus = OFF;
          *rty_AMK_bInverterOn_tx = 0U;
          *rty_AMK_bDcOn_tx = 0U;
          *rty_AMK_bEnable = 0U;
          *rty_AMK_bErrorReset = 0U;
          *rty_AMK_TargetVelocity = 0.0F;
          *rty_AMK_TorqueLimitPositiv = 0.0F;
          *rty_AMK_TorqueLimitNegativ = 0.0F;
        }
        break;
      }
      break;

     case InverterStartupC_IN_AMK_running:
      /* During 'AMK_running': '<S5>:49' */
      if (rtu_AMK_bError == 1.0) {
        /* Transition: '<S5>:62' */
        localDW->is_c2_InverterStartupControl = InverterSt_IN_AMK_errorDetected;

        /* Entry 'AMK_errorDetected': '<S5>:81' */
        *rty_MI_motorStatus = MI_STS_ERROR;
      } else if (rtu_GOV_e_miCmd == CMD_SHUTDOWN) {
        /* Transition: '<S5>:109' */
        localDW->is_c2_InverterStartupControl = InverterStartup_IN_AMK_shutdown;

        /* Entry 'AMK_shutdown': '<S5>:93' */
        localDW->is_AMK_shutdown = Inverte_IN_enforceSetpointsZero;

        /* Entry 'enforceSetpointsZero': '<S5>:104' */
        *rty_MI_motorStatus = SHUTDOWN;
        *rty_AMK_TargetVelocity = 0.0F;
        *rty_AMK_TorqueLimitPositiv = 0.0F;
        *rty_AMK_TorqueLimitNegativ = 0.0F;
        *rty_AMK_bInverterOn_tx = 0U;
      } else {
        *rty_MI_motorStatus = RUNNING;
        *rty_AMK_TargetVelocity = rtu_VD_T_motorSpeedRequest;
        *rty_AMK_TorqueLimitPositiv = rtu_VD_T_motorTorqueLimitPositi;
        *rty_AMK_TorqueLimitNegativ = rtu_VD_T_motorTorqueLimitNegati;
      }
      break;

     case InverterStartup_IN_AMK_shutdown:
      /* During 'AMK_shutdown': '<S5>:93' */
      switch (localDW->is_AMK_shutdown) {
       case InverterStartupCo_IN_commandOff:
        *rty_AMK_bEnable = 0U;

        /* During 'commandOff': '<S5>:106' */
        if (rtu_AMK_bQuitInverterOn == 0.0) {
          /* Transition: '<S5>:101' */
          localDW->is_AMK_shutdown = InverterStartupCo_IN_toggleDCon;

          /* Entry 'toggleDCon': '<S5>:107' */
          *rty_AMK_bDcOn_tx = 0U;
        } else if (rtu_AMK_bError == 1.0) {
          /* Transition: '<S5>:99' */
          /* Transition: '<S5>:98' */
          localDW->is_AMK_shutdown = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterSt_IN_AMK_errorDetected;

          /* Entry 'AMK_errorDetected': '<S5>:81' */
          *rty_MI_motorStatus = MI_STS_ERROR;
        }
        break;

       case Inverte_IN_enforceSetpointsZero:
        *rty_AMK_bInverterOn_tx = 0U;

        /* During 'enforceSetpointsZero': '<S5>:104' */
        if (rtu_AMK_bInverterOn_rx == 0.0) {
          /* Transition: '<S5>:97' */
          localDW->is_AMK_shutdown = InverterStartupCo_IN_commandOff;

          /* Entry 'commandOff': '<S5>:106' */
          *rty_AMK_bEnable = 0U;
        } else if (rtu_AMK_bError == 1.0) {
          /* Transition: '<S5>:96' */
          /* Transition: '<S5>:98' */
          localDW->is_AMK_shutdown = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterSt_IN_AMK_errorDetected;

          /* Entry 'AMK_errorDetected': '<S5>:81' */
          *rty_MI_motorStatus = MI_STS_ERROR;
        }
        break;

       default:
        *rty_AMK_bDcOn_tx = 0U;

        /* During 'toggleDCon': '<S5>:107' */
        if ((rtu_AMK_bDcOn_rx == 0.0) && (rtu_AMK_bQuitDcOn == 0.0)) {
          /* Transition: '<S5>:103' */
          localDW->is_AMK_shutdown = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            Inver_IN_motorOff_waitingForGov;

          /* Entry 'motorOff_waitingForGov': '<S5>:31' */
          *rty_MI_motorStatus = OFF;
          *rty_AMK_bInverterOn_tx = 0U;
          *rty_AMK_bDcOn_tx = 0U;
          *rty_AMK_bEnable = 0U;
          *rty_AMK_bErrorReset = 0U;
          *rty_AMK_TargetVelocity = 0.0F;
          *rty_AMK_TorqueLimitPositiv = 0.0F;
          *rty_AMK_TorqueLimitNegativ = 0.0F;
        } else if (rtu_AMK_bError == 1.0) {
          /* Transition: '<S5>:100' */
          /* Transition: '<S5>:98' */
          localDW->is_AMK_shutdown = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterSt_IN_AMK_errorDetected;

          /* Entry 'AMK_errorDetected': '<S5>:81' */
          *rty_MI_motorStatus = MI_STS_ERROR;
        }
        break;
      }
      break;

     case InverterStartupC_IN_AMK_startup:
      /* During 'AMK_startup': '<S5>:53' */
      switch (localDW->is_AMK_startup) {
       case InverterStartupCon_IN_commandOn:
        *rty_AMK_bEnable = 1U;
        *rty_AMK_bInverterOn_tx = 1U;

        /* During 'commandOn': '<S5>:47' */
        if ((rtu_AMK_bInverterOn_rx == 1.0) && (rtu_AMK_bQuitInverterOn == 1.0))
        {
          /* Transition: '<S5>:50' */
          localDW->is_AMK_startup = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterStartupC_IN_AMK_running;

          /* Entry 'AMK_running': '<S5>:49' */
        } else if (rtu_AMK_bError == 1.0) {
          /* Transition: '<S5>:73' */
          /* Transition: '<S5>:69' */
          localDW->is_AMK_startup = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterSt_IN_AMK_errorDetected;

          /* Entry 'AMK_errorDetected': '<S5>:81' */
          *rty_MI_motorStatus = MI_STS_ERROR;
        }
        break;

       case Inverte_IN_enforceSetpointsZero:
        /* During 'enforceSetpointsZero': '<S5>:40' */
        if (localDW->temporalCounter_i1 >= 200U) {
          /* Transition: '<S5>:48' */
          localDW->is_AMK_startup = InverterStartupCon_IN_commandOn;

          /* Entry 'commandOn': '<S5>:47' */
          *rty_AMK_bEnable = 1U;
          *rty_AMK_bInverterOn_tx = 1U;
        } else if (rtu_AMK_bError == 1.0) {
          /* Transition: '<S5>:72' */
          /* Transition: '<S5>:69' */
          localDW->is_AMK_startup = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterSt_IN_AMK_errorDetected;

          /* Entry 'AMK_errorDetected': '<S5>:81' */
          *rty_MI_motorStatus = MI_STS_ERROR;
        }
        break;

       case InverterStartupCo_IN_toggleDCon:
        *rty_AMK_bDcOn_tx = 1U;

        /* During 'toggleDCon': '<S5>:38' */
        if ((rtu_AMK_bDcOn_rx == 1.0) && (rtu_AMK_bQuitDcOn == 1.0)) {
          /* Transition: '<S5>:41' */
          localDW->is_AMK_startup = Inverte_IN_enforceSetpointsZero;
          localDW->temporalCounter_i1 = 0U;

          /* Entry 'enforceSetpointsZero': '<S5>:40' */
          *rty_AMK_TargetVelocity = 0.0F;
          *rty_AMK_TorqueLimitPositiv = 0.0F;
          *rty_AMK_TorqueLimitNegativ = 0.0F;
        } else if (rtu_AMK_bError == 1.0) {
          /* Transition: '<S5>:71' */
          /* Transition: '<S5>:69' */
          localDW->is_AMK_startup = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterSt_IN_AMK_errorDetected;

          /* Entry 'AMK_errorDetected': '<S5>:81' */
          *rty_MI_motorStatus = MI_STS_ERROR;
        }
        break;

       default:
        /* During 'waiting_sysReady': '<S5>:35' */
        if (rtu_AMK_bSystemReady == 1.0) {
          /* Transition: '<S5>:39' */
          localDW->is_AMK_startup = InverterStartupCo_IN_toggleDCon;

          /* Entry 'toggleDCon': '<S5>:38' */
          *rty_AMK_bDcOn_tx = 1U;
        } else if (rtu_AMK_bError == 1.0) {
          /* Transition: '<S5>:70' */
          /* Transition: '<S5>:69' */
          localDW->is_AMK_startup = InverterStar_IN_NO_ACTIVE_CHILD;
          localDW->is_c2_InverterStartupControl =
            InverterSt_IN_AMK_errorDetected;

          /* Entry 'AMK_errorDetected': '<S5>:81' */
          *rty_MI_motorStatus = MI_STS_ERROR;
        }
        break;
      }
      break;

     default:
      *rty_AMK_bInverterOn_tx = 0U;
      *rty_AMK_bDcOn_tx = 0U;
      *rty_AMK_bEnable = 0U;
      *rty_AMK_bErrorReset = 0U;

      /* During 'motorOff_waitingForGov': '<S5>:31' */
      if (rtu_GOV_e_miCmd == CMD_STARTUP) {
        /* Transition: '<S5>:33' */
        localDW->is_c2_InverterStartupControl = InverterStartupC_IN_AMK_startup;
        localDW->is_AMK_startup = InverterSta_IN_waiting_sysReady;

        /* Entry 'waiting_sysReady': '<S5>:35' */
        *rty_MI_motorStatus = STARTUP;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/LEFT_MOTOR' */
}

/* Model step function */
void InverterStartupControl_step(void* args)
{
  real_T rtb_ManualSwitch1;
  real_T tmp;
  int32_T i;
  MI_CMD rtb_GOV_e_miCmd;
  MI_STATUSES MI_motorStatus;

  /* Chart: '<S1>/Chart' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Inport: '<Root>/In10'
   *  Inport: '<Root>/In21'
   *  Inport: '<Root>/In25'
   *  Inport: '<Root>/In6'
   */
  /* Gateway: Control/Chart */
  /* During: Control/Chart */
  if (InverterStartupControl_DW.is_active_c1_InverterStartupCon == 0U) {
    /* Entry: Control/Chart */
    InverterStartupControl_DW.is_active_c1_InverterStartupCon = 1U;

    /* Entry Internal: Control/Chart */
    /* Transition: '<S2>:2' */
    InverterStartupControl_DW.is_c1_InverterStartupControl =
      InverterStartupControl_IN_Init;

    /* Entry 'Init': '<S2>:5' */
    rtb_GOV_e_miCmd = CMD_INIT;
  } else {
    switch (InverterStartupControl_DW.is_c1_InverterStartupControl) {
     case InverterStartupContro_IN_Error0:
      rtb_GOV_e_miCmd = ERR_RESET;

      /* During 'Error0': '<S2>:8' */
      if (InverterStartupControl_U.AMK_bError_R == 0.0) {
        /* Transition: '<S2>:12' */
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Run;

        /* Entry 'Run': '<S2>:1' */
        rtb_GOV_e_miCmd = CMD_STARTUP;
      }
      break;

     case InverterStartupContro_IN_Error1:
      rtb_GOV_e_miCmd = ERR_RESET;

      /* During 'Error1': '<S2>:21' */
      if (InverterStartupControl_U.AMK_bError_L == 0.0) {
        /* Transition: '<S2>:24' */
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Run;

        /* Entry 'Run': '<S2>:1' */
        rtb_GOV_e_miCmd = CMD_STARTUP;
      }
      break;

     case InverterStartupControl_IN_Init:
      rtb_GOV_e_miCmd = CMD_INIT;

      /* During 'Init': '<S2>:5' */
      if ((InverterStartupControl_U.AMK_bSystemReady_R == 1.0) &&
          (InverterStartupControl_U.AMK_bSystemReady_L == 1.0) &&
          (InverterStartupControl_P.Constant11_Value == 0.0)) {
        /* Transition: '<S2>:6' */
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Run;

        /* Entry 'Run': '<S2>:1' */
        rtb_GOV_e_miCmd = CMD_STARTUP;
      }
      break;

     case InverterStartupControl_IN_Run:
      rtb_GOV_e_miCmd = CMD_STARTUP;

      /* During 'Run': '<S2>:1' */
      if (InverterStartupControl_U.AMK_bError_R == 1.0) {
        /* Transition: '<S2>:9' */
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupContro_IN_Error0;

        /* Entry 'Error0': '<S2>:8' */
        rtb_GOV_e_miCmd = ERR_RESET;
      } else if (InverterStartupControl_P.Constant11_Value == 1.0) {
        /* Transition: '<S2>:16' */
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupCont_IN_Shutdown;

        /* Entry 'Shutdown': '<S2>:15' */
        rtb_GOV_e_miCmd = CMD_SHUTDOWN;
      } else if (InverterStartupControl_U.AMK_bError_L == 1.0) {
        /* Transition: '<S2>:22' */
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupContro_IN_Error1;

        /* Entry 'Error1': '<S2>:21' */
        rtb_GOV_e_miCmd = ERR_RESET;
      }
      break;

     default:
      rtb_GOV_e_miCmd = CMD_SHUTDOWN;

      /* During 'Shutdown': '<S2>:15' */
      if (InverterStartupControl_P.Constant11_Value == 0.0) {
        /* Transition: '<S2>:19' */
        InverterStartupControl_DW.is_c1_InverterStartupControl =
          InverterStartupControl_IN_Init;

        /* Entry 'Init': '<S2>:5' */
        rtb_GOV_e_miCmd = CMD_INIT;
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* SignalConversion generated from: '<S3>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/APPS'
   */
  InverterStartupControl_B.VectorConcatenate[0] = InverterStartupControl_U.APPS;

  /* S-Function (sfix_udelay): '<S3>/Tapped Delay' */
  for (i = 0; i < 5; i++) {
    InverterStartupControl_B.VectorConcatenate[i + 1] =
      InverterStartupControl_DW.TappedDelay_X[i];
  }

  /* End of S-Function (sfix_udelay): '<S3>/Tapped Delay' */

  /* Sum: '<S3>/Sum of Elements' */
  tmp = -0.0;
  for (i = 0; i < 6; i++) {
    tmp += InverterStartupControl_B.VectorConcatenate[i];
  }

  /* Product: '<S3>/Divide' incorporates:
   *  Sum: '<S3>/Sum of Elements'
   */
  rtb_ManualSwitch1 = tmp / InverterStartupControl_ConstB.Width;

  /* ManualSwitch: '<S1>/Manual Switch' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (InverterStartupControl_P.ManualSwitch_CurrentSetting == 1) {
    tmp = InverterStartupControl_P.Constant_Value;
  } else {
    tmp = rtb_ManualSwitch1;
  }

  /* Chart: '<S4>/RIGHT_MOTOR' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  DataTypeConversion: '<S1>/Cast To Single'
   *  DataTypeConversion: '<S1>/Cast To Single1'
   *  DataTypeConversion: '<S1>/Cast To Single2'
   *  Inport: '<Root>/In10'
   *  Inport: '<Root>/In4'
   *  Inport: '<Root>/In6'
   *  Inport: '<Root>/In7'
   *  Inport: '<Root>/In8'
   *  Inport: '<Root>/In9'
   *  ManualSwitch: '<S1>/Manual Switch'
   *  Outport: '<Root>/AMK_TargetVelocity_R'
   *  Outport: '<Root>/AMK_TorqueLimitNegativ_R'
   *  Outport: '<Root>/AMK_TorqueLimitPositiv_R'
   *  Outport: '<Root>/AMK_bDcOn_R'
   *  Outport: '<Root>/AMK_bEnable_R'
   *  Outport: '<Root>/AMK_bErrorReset_R'
   *  Outport: '<Root>/AMK_bInverterOn_R'
   */
  InverterStartupContr_LEFT_MOTOR(rtb_GOV_e_miCmd,
    InverterStartupControl_U.AMK_bSystemReady_R,
    InverterStartupControl_U.AMK_bError_R,
    InverterStartupControl_U.AMK_bQuitDcOn_R,
    InverterStartupControl_U.AMK_bDcOn_R,
    InverterStartupControl_U.AMK_bQuitInverterOn_R,
    InverterStartupControl_U.AMK_bInverterOn_R, (real32_T)tmp, (real32_T)
    InverterStartupControl_P.Constant1_Value, (real32_T)
    InverterStartupControl_P.Constant2_Value, &MI_motorStatus,
    &InverterStartupControl_Y.AMK_bInverterOn_R,
    &InverterStartupControl_Y.AMK_bDcOn_R,
    &InverterStartupControl_Y.AMK_bEnable_R,
    &InverterStartupControl_Y.AMK_bErrorReset_R,
    &InverterStartupControl_Y.AMK_TargetVelocity_R,
    &InverterStartupControl_Y.AMK_TorqueLimitPositiv_R,
    &InverterStartupControl_Y.AMK_TorqueLimitNegativ_R,
    &InverterStartupControl_DW.sf_RIGHT_MOTOR);

  /* ManualSwitch: '<S1>/Manual Switch1' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  if (InverterStartupControl_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_ManualSwitch1 = InverterStartupControl_P.Constant5_Value;
  }

  /* Chart: '<S4>/LEFT_MOTOR' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   *  DataTypeConversion: '<S1>/Cast To Single3'
   *  DataTypeConversion: '<S1>/Cast To Single4'
   *  DataTypeConversion: '<S1>/Cast To Single5'
   *  Inport: '<Root>/In19'
   *  Inport: '<Root>/In21'
   *  Inport: '<Root>/In22'
   *  Inport: '<Root>/In23'
   *  Inport: '<Root>/In24'
   *  Inport: '<Root>/In25'
   *  ManualSwitch: '<S1>/Manual Switch1'
   *  Outport: '<Root>/AMK_TargetVelocity_L'
   *  Outport: '<Root>/AMK_TorqueLimitNegativ_L'
   *  Outport: '<Root>/AMK_TorqueLimitPositiv_L'
   *  Outport: '<Root>/AMK_bDcOn_L'
   *  Outport: '<Root>/AMK_bEnable_L'
   *  Outport: '<Root>/AMK_bErrorReset_L'
   *  Outport: '<Root>/AMK_bInverterOn_L'
   */
  InverterStartupContr_LEFT_MOTOR(rtb_GOV_e_miCmd,
    InverterStartupControl_U.AMK_bSystemReady_L,
    InverterStartupControl_U.AMK_bError_L,
    InverterStartupControl_U.AMK_bQuitDcOn_L,
    InverterStartupControl_U.AMK_bDcOn_L,
    InverterStartupControl_U.AMK_bQuitInverterOn_L,
    InverterStartupControl_U.AMK_bInverterOn_L, (real32_T)rtb_ManualSwitch1,
    (real32_T)InverterStartupControl_P.Constant6_Value, (real32_T)
    InverterStartupControl_P.Constant7_Value, &MI_motorStatus,
    &InverterStartupControl_Y.AMK_bInverterOn_L,
    &InverterStartupControl_Y.AMK_bDcOn_L,
    &InverterStartupControl_Y.AMK_bEnable_L,
    &InverterStartupControl_Y.AMK_bErrorReset_L,
    &InverterStartupControl_Y.AMK_TargetVelocity_L,
    &InverterStartupControl_Y.AMK_TorqueLimitPositiv_L,
    &InverterStartupControl_Y.AMK_TorqueLimitNegativ_L,
    &InverterStartupControl_DW.sf_LEFT_MOTOR);

  /* Update for S-Function (sfix_udelay): '<S3>/Tapped Delay' incorporates:
   *  Inport: '<Root>/APPS'
   */
  InverterStartupControl_DW.TappedDelay_X[0] =
    InverterStartupControl_DW.TappedDelay_X[1];
  InverterStartupControl_DW.TappedDelay_X[1] =
    InverterStartupControl_DW.TappedDelay_X[2];
  InverterStartupControl_DW.TappedDelay_X[2] =
    InverterStartupControl_DW.TappedDelay_X[3];
  InverterStartupControl_DW.TappedDelay_X[3] =
    InverterStartupControl_DW.TappedDelay_X[4];
  InverterStartupControl_DW.TappedDelay_X[4] = InverterStartupControl_U.APPS;
}

/* Model initialize function */
void InverterStartupControl_initialize(void)
{
  {
    int32_T i;
    MI_STATUSES MI_motorStatus;

    /* InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */
    for (i = 0; i < 5; i++) {
      InverterStartupControl_DW.TappedDelay_X[i] =
        InverterStartupControl_P.TappedDelay_vinit;
    }

    /* End of InitializeConditions for S-Function (sfix_udelay): '<S3>/Tapped Delay' */

    /* SystemInitialize for Chart: '<S4>/RIGHT_MOTOR' incorporates:
     *  Outport: '<Root>/AMK_TargetVelocity_R'
     *  Outport: '<Root>/AMK_TorqueLimitNegativ_R'
     *  Outport: '<Root>/AMK_TorqueLimitPositiv_R'
     *  Outport: '<Root>/AMK_bDcOn_R'
     *  Outport: '<Root>/AMK_bEnable_R'
     *  Outport: '<Root>/AMK_bErrorReset_R'
     *  Outport: '<Root>/AMK_bInverterOn_R'
     */
    InverterStartup_LEFT_MOTOR_Init(&MI_motorStatus,
      &InverterStartupControl_Y.AMK_bInverterOn_R,
      &InverterStartupControl_Y.AMK_bDcOn_R,
      &InverterStartupControl_Y.AMK_bEnable_R,
      &InverterStartupControl_Y.AMK_bErrorReset_R,
      &InverterStartupControl_Y.AMK_TargetVelocity_R,
      &InverterStartupControl_Y.AMK_TorqueLimitPositiv_R,
      &InverterStartupControl_Y.AMK_TorqueLimitNegativ_R);

    /* SystemInitialize for Chart: '<S4>/LEFT_MOTOR' incorporates:
     *  Outport: '<Root>/AMK_TargetVelocity_L'
     *  Outport: '<Root>/AMK_TorqueLimitNegativ_L'
     *  Outport: '<Root>/AMK_TorqueLimitPositiv_L'
     *  Outport: '<Root>/AMK_bDcOn_L'
     *  Outport: '<Root>/AMK_bEnable_L'
     *  Outport: '<Root>/AMK_bErrorReset_L'
     *  Outport: '<Root>/AMK_bInverterOn_L'
     */
    InverterStartup_LEFT_MOTOR_Init(&MI_motorStatus,
      &InverterStartupControl_Y.AMK_bInverterOn_L,
      &InverterStartupControl_Y.AMK_bDcOn_L,
      &InverterStartupControl_Y.AMK_bEnable_L,
      &InverterStartupControl_Y.AMK_bErrorReset_L,
      &InverterStartupControl_Y.AMK_TargetVelocity_L,
      &InverterStartupControl_Y.AMK_TorqueLimitPositiv_L,
      &InverterStartupControl_Y.AMK_TorqueLimitNegativ_L);
  }
}

/* Model terminate function */
void InverterStartupControl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
