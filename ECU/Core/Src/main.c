/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <pthread.h>
#include "string.h"
#include "globals.h"
#include "uart.h"
#include "printf.h"
#include "canal.h"
#include "adc.h"
#include "rtscheduler.h"
#include "canal_fc_messages.h"
#include "InverterStartupControl.h"
#include "rtwtypes.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MAX_ADC_VALUE (4096)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;


//initialized for each dif channel that STM supprts, CAN1, CAN2 + CAN3
CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;
CAN_HandleTypeDef hcan3;

SPI_HandleTypeDef hspi4;

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN1_Init(void);
static void MX_CAN2_Init(void);
static void MX_CAN3_Init(void);
static void MX_ADC1_Init(void);
static void MX_SPI4_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
void setControlSystemInputs(void*);
void getControlSystemOutputs(void*);
void transmitToAMKMotors(void*);

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;

UART_st debug_uart = {
	.uart_num = 3,
	.huart = &huart3,
	.bit_position = LSB_First,
	.baudrate = UART_115200,
	.mode = UART_TX_RX,
	.datasize = UART_Datasize_8,
};

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
RtScheduler_tasks tasks = {
	[eTASK1_5MS] = {
		setControlSystemInputs,
		InverterStartupControl_step,
		getControlSystemOutputs,
		transmitToAMKMotors,
	},
};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  //We are not using the regular STM CAN init functions. instead using our custom function canal_init()
  //MX_CAN1_Init();
  //MX_CAN2_Init();
  //MX_CAN3_Init();
  //MX_ADC1_Init();
  //MX_SPI4_Init();
  //MX_USART2_UART_Init();
  //MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */


  Printf_Init(&debug_uart);
  CanAL_Init(&pt1_can); //Powertrain CAN struct
  CanAL_Init(&veh_can); //Vehicle CAN struct
  ADC_Init(&adc1); 
  InverterStartupControl_initialize();

  RtScheduler_startRunning(tasks); //begin task scheduler

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ADC_SCAN_ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_10;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 1;
  hcan1.Init.Mode = CAN_MODE_SILENT_LOOPBACK;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = ENABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief CAN2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN2_Init(void)
{

  /* USER CODE BEGIN CAN2_Init 0 */

  /* USER CODE END CAN2_Init 0 */

  /* USER CODE BEGIN CAN2_Init 1 */

  /* USER CODE END CAN2_Init 1 */
  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = 1;
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = ENABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN2_Init 2 */

  /* USER CODE END CAN2_Init 2 */

}

/**
  * @brief CAN3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN3_Init(void)
{

  /* USER CODE BEGIN CAN3_Init 0 */

  /* USER CODE END CAN3_Init 0 */

  /* USER CODE BEGIN CAN3_Init 1 */

  /* USER CODE END CAN3_Init 1 */
  hcan3.Instance = CAN3;
  hcan3.Init.Prescaler = 1;
  hcan3.Init.Mode = CAN_MODE_NORMAL;
  hcan3.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan3.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan3.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan3.Init.TimeTriggeredMode = DISABLE;
  hcan3.Init.AutoBusOff = ENABLE;
  hcan3.Init.AutoWakeUp = DISABLE;
  hcan3.Init.AutoRetransmission = DISABLE;
  hcan3.Init.ReceiveFifoLocked = DISABLE;
  hcan3.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN3_Init 2 */

  /* USER CODE END CAN3_Init 2 */

}

/**
  * @brief SPI4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI4_Init(void)
{

  /* USER CODE BEGIN SPI4_Init 0 */

  /* USER CODE END SPI4_Init 0 */

  /* USER CODE BEGIN SPI4_Init 1 */

  /* USER CODE END SPI4_Init 1 */
  /* SPI4 parameter configuration*/
  hspi4.Instance = SPI4;
  hspi4.Init.Mode = SPI_MODE_MASTER;
  hspi4.Init.Direction = SPI_DIRECTION_2LINES;
  hspi4.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi4.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi4.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi4.Init.NSS = SPI_NSS_SOFT;
  hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi4.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi4.Init.CRCPolynomial = 7;
  hspi4.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi4.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI4_Init 2 */

  /* USER CODE END SPI4_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(IMU_SPI_CS_GPIO_Port, IMU_SPI_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DEBUG_LED_Pin|START_BUTTON_LED_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, BRAKE_LIGHT_EN_Pin|RTDS_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : IMU_SPI_CS_Pin */
  GPIO_InitStruct.Pin = IMU_SPI_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(IMU_SPI_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : DEBUG_LED_Pin START_BUTTON_LED_EN_Pin */
  GPIO_InitStruct.Pin = DEBUG_LED_Pin|START_BUTTON_LED_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BRAKE_LIGHT_EN_Pin RTDS_EN_Pin */
  GPIO_InitStruct.Pin = BRAKE_LIGHT_EN_Pin|RTDS_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : START_BUTTON_N_Pin */
  GPIO_InitStruct.Pin = START_BUTTON_N_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(START_BUTTON_N_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

// Step functions
void setControlSystemInputs(void *args) {
  ADC_Scan(&adc1);
  InverterStartupControl_U.APPS = Get_Single_Chan_Average(&adc1, APPS2_ADC_CHANNEL);
  InverterStartupControl_U.AMK_ActualVelocity_R = AMK1_ActualValues1.AMK_ActualVelocity;         
  InverterStartupControl_U.AMK_MagnetizingCurrent_R = AMK1_ActualValues1.AMK_MagnetizingCurrent;
  InverterStartupControl_U.AMK_TorqueCurrent_R = AMK1_ActualValues1.AMK_TorqueCurrent;          
  InverterStartupControl_U.AMK_bDcOn_R = AMK1_ActualValues1.AMK_bDcOn;                  
  InverterStartupControl_U.AMK_bDerating_R = AMK1_ActualValues1.AMK_bDerating;              
  InverterStartupControl_U.AMK_bError_R = AMK1_ActualValues1.AMK_bError;                 
  InverterStartupControl_U.AMK_bInverterOn_R = AMK1_ActualValues1.AMK_bInverterOn;            
  InverterStartupControl_U.AMK_bQuitDcOn_R = AMK1_ActualValues1.AMK_bQuitDcOn;              
  InverterStartupControl_U.AMK_bQuitInverterOn_R = AMK1_ActualValues1.AMK_bQuitInverterOn;        
  InverterStartupControl_U.AMK_bSystemReady_R = AMK1_ActualValues1.AMK_bSystemReady;           
  InverterStartupControl_U.AMK_bWarn_R = AMK1_ActualValues1.AMK_bWarn;                  
  InverterStartupControl_U.AMK_ErrorInfo_R = AMK1_ActualValues2.AMK_ErrorInfo;              
  InverterStartupControl_U.AMK_TempIGBT_R = AMK1_ActualValues2.AMK_TempIGBT;               
  InverterStartupControl_U.AMK_TempInverter_R = AMK1_ActualValues2.AMK_TempInverter;           
  InverterStartupControl_U.AMK_TempMotor_R = AMK1_ActualValues2.AMK_TempMotor;              
  InverterStartupControl_U.AMK_ActualVelocity_L = AMK0_ActualValues1.AMK_ActualVelocity;         
  InverterStartupControl_U.AMK_MagnetizingCurrent_L = AMK0_ActualValues1.AMK_MagnetizingCurrent;     
  InverterStartupControl_U.AMK_TorqueCurrent_L = AMK0_ActualValues1.AMK_TorqueCurrent;          
  InverterStartupControl_U.AMK_bDcOn_L = AMK0_ActualValues1.AMK_bDcOn;                  
  InverterStartupControl_U.AMK_bDerating_L = AMK0_ActualValues1.AMK_bDerating;              
  InverterStartupControl_U.AMK_bError_L = AMK0_ActualValues1.AMK_bError;                 
  InverterStartupControl_U.AMK_bInverterOn_L = AMK0_ActualValues1.AMK_bInverterOn;            
  InverterStartupControl_U.AMK_bQuitDcOn_L = AMK0_ActualValues1.AMK_bQuitDcOn;              
  InverterStartupControl_U.AMK_bQuitInverterOn_L = AMK0_ActualValues1.AMK_bQuitInverterOn;        
  InverterStartupControl_U.AMK_bSystemReady_L = AMK0_ActualValues1.AMK_bSystemReady;           
  InverterStartupControl_U.AMK_bWarn_L = AMK0_ActualValues1.AMK_bWarn;                  
  InverterStartupControl_U.AMK_ErrorInfo_L = AMK0_ActualValues2.AMK_ErrorInfo;              
  InverterStartupControl_U.AMK_TempIGBT_L = AMK0_ActualValues2.AMK_TempIGBT;               
  InverterStartupControl_U.AMK_TempInverter_L = AMK0_ActualValues2.AMK_TempInverter;           
  InverterStartupControl_U.AMK_TempMotor_L = AMK0_ActualValues2.AMK_TempMotor;              
}

void getControlSystemOutputs(void *args) {
  AMK1_SetPoints1.AMK_bInverterOn= InverterStartupControl_Y.AMK_bInverterOn_R;
  AMK1_SetPoints1.AMK_bDcOn= InverterStartupControl_Y.AMK_bDcOn_R;
  AMK1_SetPoints1.AMK_bEnable= InverterStartupControl_Y.AMK_bEnable_R;
  AMK1_SetPoints1.AMK_bErrorReset= InverterStartupControl_Y.AMK_bErrorReset_R;
  AMK1_SetPoints1.AMK_TargetVelocity= InverterStartupControl_Y.AMK_TargetVelocity_R;
  AMK1_SetPoints1.AMK_TorqueLimitPositiv= InverterStartupControl_Y.AMK_TorqueLimitPositiv_R;
  AMK1_SetPoints1.AMK_TorqueLimitNegativ= InverterStartupControl_Y.AMK_TorqueLimitNegativ_R;
  AMK0_SetPoints1.AMK_bInverterOn= InverterStartupControl_Y.AMK_bInverterOn_L;
  AMK0_SetPoints1.AMK_bDcOn= InverterStartupControl_Y.AMK_bDcOn_L;
  AMK0_SetPoints1.AMK_bEnable= InverterStartupControl_Y.AMK_bEnable_L;
  AMK0_SetPoints1.AMK_bErrorReset= InverterStartupControl_Y.AMK_bErrorReset_L;
  AMK0_SetPoints1.AMK_TargetVelocity= InverterStartupControl_Y.AMK_TargetVelocity_L;
  AMK0_SetPoints1.AMK_TorqueLimitPositiv= InverterStartupControl_Y.AMK_TorqueLimitPositiv_L;
  AMK0_SetPoints1.AMK_TorqueLimitNegativ= InverterStartupControl_Y.AMK_TorqueLimitNegativ_L;
}


//the main functions that call CAN transmit and receive
void transmitToAMKMotors(void* args) {
	CANAL_PRINT("TRANSMITTING\n\r");
	CanAL_Transmit(&pt1_can, AMK0_SETPOINTS1_CANAL_ID);
	CanAL_Transmit(&pt1_can, AMK1_SETPOINTS1_CANAL_ID);
}

//HAL's low level callback function
//this is the callback that will eventually dictate how we receive the data: Calling HAL_GetMessage
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) { //interrupt handler for receive - will be called when a message is sent, receives a LO on an idle line then it is called (i think)
	TeCanALRet ret = CanAL_Receive(&pt1_can);
	if (ret != CANAL_OK) {
		CANAL_PRINT("Could not recognize message\n\r");
	}
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  CANAL_PRINT("oh no! error handler\n\r");
	  HAL_GPIO_WritePin(DEBUG_LED_GPIO_Port, DEBUG_LED_Pin, true);
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
