/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  InverterStartupControl_step();

  /* Get model outputs here */
  __disable_irq();
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main1(void)
{
  float modelBaseRate = 0.005;
  float systemClock = 216;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#ifndef USE_RTX
#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  __disable_irq();

#endif

  ;
  stm32f7xx_init_board();
  SystemCoreClockUpdate();
  rtmSetErrorStatus(InverterStartupControl_M, 0);
  InverterStartupControl_initialize();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel = rtmGetErrorStatus(InverterStartupControl_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(InverterStartupControl_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Terminate model */
  InverterStartupControl_terminate();

#ifndef USE_RTX

  (void)systemClock;

#endif

  ;
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
