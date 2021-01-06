/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
const uint16_t COUNTER_PERIOD = 20000 - 1; //Global Maximum number that the stm32 will count to before resetting

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
//static void MX_TIM2_Init(void);
//static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */
static void MX_TIM2_Init(uint32_t prescaler, uint8_t Channel_1, uint8_t Channel_2, uint8_t Channel_3, uint8_t Channel_4);
static void MX_TIM1_Init(uint32_t prescaler, uint8_t Channel_1, uint8_t Channel_2, uint8_t Channel_3, uint8_t Channel_4);
static void Timer_Init_base(uint8_t timer, uint16_t period, uint8_t doTriggerISR, uint8_t Channel_1, uint8_t Channel_2, uint8_t Channel_3, uint8_t Channel_4);
uint32_t Calculate_prescaler(uint16_t period);
static void PWM_Init(uint8_t timer, uint8_t channel, uint8_t duty_cycle);
uint16_t Calculate_DutyCycle(uint8_t duty_cycle);
static void PWM_Stop(uint8_t timer,uint8_t channel);
static void Timer_Stop(uint8_t timer);

//Macro definitions
#define Timer_Init(...) var_Timer_Init((Timer_Init_args){__VA_ARGS__});
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//Setting up the default variables
typedef struct
{
	uint8_t timer;
	uint16_t period;
	uint8_t doTriggerISR;
	uint8_t Channel_1;
	uint8_t Channel_2;
	uint8_t Channel_3;
	uint8_t Channel_4;
}Timer_Init_args;


//Wrapper function that return default variables
static void var_Timer_Init(Timer_Init_args in)
{
	uint8_t timer_out = in.timer;
	uint16_t period_out = in.period;
	uint8_t doTriggerISR_out = in.doTriggerISR ? in.doTriggerISR :2;
	uint8_t Channel_1_out = in.Channel_1 ? in.Channel_1 :2;
	uint8_t Channel_2_out = in.Channel_2 ? in.Channel_2 :2;
	uint8_t Channel_3_out = in.Channel_3 ? in.Channel_3 :2;
	uint8_t Channel_4_out = in.Channel_4 ? in.Channel_4 :2;
	Timer_Init_base(timer_out,period_out,doTriggerISR_out,Channel_1_out,Channel_2_out,Channel_3_out,Channel_4_out);
}


int _write(int file, char *ptr, int len) //printf to SWV ITM
{
	int i = 0;
	for(i = 0 ; i<len ; i++)
	{
		ITM_SendChar((*ptr++));
	}
	return len;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) //ISR triggered by timer overflow
{
    if (htim == &htim1)
    {
       /*Timer 1*/
    	HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);

    }
    else if(htim == &htim2)
    {
        /*Timer 2*/
    	HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
    }
    else
    {
    	//very unlikely to see this error message
        printf("Error triggering correct ISR by timer overflow. Check HAL_TIM_PeriodElapsedCallback() function.\n");
    }
}

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


  /* USER CODE BEGIN 2 */
  Timer_Init(1, 500);
  Timer_Init(2, 1000);
  PWM_Init(2,1,50);
  PWM_Init(2,2,75);
  PWM_Init(1,1,50);
  PWM_Init(1,2,75);

  //HAL_Delay(10000);
  //Timer_Init(2, 1000, 1, 1, 1, 1, 1);


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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM1 Initialization Function
  * @param Prescaler, Channel 1 init, Channel 2 init, Channel 3 init, Channel 4 init,
  * @retval None
  */
static void MX_TIM1_Init(uint32_t prescaler, uint8_t Channel_1, uint8_t Channel_2, uint8_t Channel_3, uint8_t Channel_4)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */
  htim1.Init.Prescaler = prescaler;
  htim1.Init.Period = COUNTER_PERIOD;
  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = prescaler;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = COUNTER_PERIOD;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  /*if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }*/
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  //Channel configuration
  if (Channel_1==2)
  {
	  HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1);
  }
  if (Channel_2==2)
  {
  	  HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2);
  }
  if (Channel_3==2)
  {
  	  HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3);
  }
  if (Channel_4==2)
  {
  	  HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4);
  }

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param Prescaler, Channel 1 init, Channel 2 init, Channel 3 init, Channel 4 init,
  * @retval None
  */
static void MX_TIM2_Init(uint32_t prescaler, uint8_t Channel_1, uint8_t Channel_2, uint8_t Channel_3, uint8_t Channel_4)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */
  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = prescaler;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = COUNTER_PERIOD;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  /*if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }*/
  /* USER CODE BEGIN TIM2_Init 2 */

  //Channel configuration
  if (Channel_1==2)
  {
	  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1);
  }
  if (Channel_2==2)
  {
	  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2);
  }
  if (Channel_3==2)
  {
	  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3);
  }
  if (Channel_4==2)
  {
	  HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4);
  }
  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(EXT_LED_GPIO_Port, EXT_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LD1_Pin LD3_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : EXT_LED_Pin */
  GPIO_InitStruct.Pin = EXT_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(EXT_LED_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
/**
  * @brief Initialize timer n on channel m for s milli seconds with ISR
  * @param Timer number, period (milliseconds), Trigger the Interrupt Service Routine(2=True 1=False), Channel 1 init, Channel 2 init, Channel 3 init, Channel 4 init
  * @retval None
  */
static void Timer_Init_base(uint8_t timer, uint16_t period, uint8_t doTriggerISR, uint8_t Channel_1, uint8_t Channel_2, uint8_t Channel_3, uint8_t Channel_4)
{
	if (period > 0 && period <65536)
	{
		uint32_t prescaler = Calculate_prescaler(period); //max period value is 2^16-1

		switch (timer)
		{
			case (1):
				MX_TIM1_Init(prescaler,Channel_1,Channel_2,Channel_3,Channel_4);
				if(doTriggerISR==2)
				{
					HAL_TIM_Base_Start_IT(&htim1);
				}
				break;
			case (2):
				MX_TIM2_Init(prescaler,Channel_1,Channel_2,Channel_3,Channel_4);
				if(doTriggerISR==2)
						{
							HAL_TIM_Base_Start_IT(&htim2);
						}
				break;
			default:
				printf("Invalid Timer argument. Should be either '1' or '2'.\n");

		}
	}

	else
	{
		printf("Invalid Period argument. Should be >0 and <65536");
	}
}

/**
  * @brief Calculate the prescaler necessary to operate desired PWM
  * @param period
  * @retval prescaler
  */
uint32_t Calculate_prescaler(uint16_t period)
{
	uint32_t prescaler = ((HAL_RCC_GetSysClockFreq()*(float)period)/(COUNTER_PERIOD+1))-1;
	prescaler /= 1000;
	return prescaler;
}

/**
  * @brief Take initialized timer, channel and desired duty cycle and initialize PWM
  * @param Timer, channel, duty cycle
  * @retval None
  */
static void PWM_Init(uint8_t timer, uint8_t channel, uint8_t duty_cycle)
{

	TIM_HandleTypeDef* desired_timer;
	uint32_t desired_channel;

	//Calculate the pulse
	uint16_t ticks_percycle = Calculate_DutyCycle(duty_cycle);

	//Find desired timer
	switch(timer)
	{
		case(1):
			desired_timer = &htim1;
			break;
		case(2):
			desired_timer = &htim2;
			break;
		default:
			printf("Invalid Timer argument. Should be either '1' or '2'.\n");
	}

	//Find desired channel
	switch(channel)
	{
		case(1):
			desired_channel = TIM_CHANNEL_1;
			break;
		case(2):
			desired_channel = TIM_CHANNEL_2;
			break;
		case(3):
			desired_channel = TIM_CHANNEL_3;
			break;
		case(4):
			desired_channel = TIM_CHANNEL_4;
			break;
		default:
			printf("Invalid Channel argument. Should be an integer within range [1,4].\n");
	}

	//Initiate the PWM and desired duty cycle
    HAL_TIM_PWM_Start(desired_timer, desired_channel);
    __HAL_TIM_SET_COMPARE(desired_timer, desired_channel, ticks_percycle);
}

/**
  * @brief Calculate the duty cycle in ticks
  * @param duty cycle
  * @retval Ticks per cycle
  */
uint16_t Calculate_DutyCycle(uint8_t duty_cycle)
{
	uint16_t ticks_percycle;
	//CHECK TO MAKE SURE DUTY CYCLE IS WITHIN [0,100]
	if (duty_cycle>=0 && duty_cycle <=100)
	{
		ticks_percycle = (duty_cycle*COUNTER_PERIOD)/100;
	}

	else
	{
		ticks_percycle = 0; //Default value
		printf("Invalid Duty Cycle argument. Should be within range [0,100].\n");
	}
	return ticks_percycle;
}

/**
  * @brief Stop PWM signal from timer n on channel m
  * @param Timer, channel
  * @retval None
  */
static void PWM_Stop(uint8_t timer, uint8_t channel)
{
	TIM_HandleTypeDef* desired_timer;
	uint32_t desired_channel;

	//Find timer
	switch(timer)
	{
		case(1):
			desired_timer = &htim1;
			break;
		case(2):
			desired_timer = &htim2;
			break;
		default:
			printf("Invalid Timer argument. Should be either '1' or '2'.\n");
	}

	//Find channel
	switch(channel)
	{
		case(1):
			desired_channel = TIM_CHANNEL_1;
			break;
		case(2):
			desired_channel = TIM_CHANNEL_2;
			break;
		case(3):
			desired_channel = TIM_CHANNEL_3;
			break;
		case(4):
			desired_channel = TIM_CHANNEL_4;
			break;
		default:
			printf("Invalid Channel argument. Should be an integer within range [1,4].\n");
	}

	//Stop PWM signal
	HAL_TIM_PWM_Stop(desired_timer, desired_channel);
}

/**
  * @brief Stop timer n
  * @param Timer
  * @retval None
  */
static void Timer_Stop(uint8_t timer)
{
	TIM_HandleTypeDef* desired_timer;

	//Find timer
	switch(timer)
	{
		case(1):
			desired_timer = &htim1;
			break;
		case(2):
			desired_timer = &htim2;
			break;
		default:
			printf("Invalid Timer argument. Should be either '1' or '2'.\n");
	}

	//Stop timer
	HAL_TIM_Base_Stop(desired_timer);
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
