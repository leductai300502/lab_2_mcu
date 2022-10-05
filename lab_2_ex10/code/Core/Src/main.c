/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "software_timer.h"
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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
	const int MAX_LED_MATRIX = 5;
	int index_led_matrix = 0;
	int bool=0;
	unsigned matrix_buffer[8] = {0xFEF7,0xFDEB,0xFBC1,0xF7DD,0xEFDD,0xDFDD,0xBFDD,0x7FDD};
	unsigned matrix_buffer1[8] = {0xFEEF,0xFDD7,0xFB83,0xF7BB,0xEFBB,0xDFDD,0xBFDD,0x7FDD};
	unsigned matrix_buffer2[8] = {0xFEDF,0xFDAF,0xFB07,0xF777,0xEF77,0xDFDD,0xBFDD,0x7FDD};
	unsigned matrix_buffer3[8] = {0xFEBF,0xFD5F,0xFB0F,0xF7EF,0xEFEF,0xDFDD,0xBFDD,0x7FDD};
	unsigned matrix_buffer4[8] = {0xFE7F,0xFDBF,0xFB1F,0xF7DF,0xEFDF,0xDFDD,0xBFDD,0x7FDD};
	unsigned matrix_buffer5[8] = {0xFEFF,0xFD7F,0xFB3F,0xF7BF,0xEFBF,0xDFDD,0xBFDD,0x7FDD};
	void updateLEDMatrix(int index ) {
		switch ( index ) {
		case 0:
			if(bool == 0)	GPIOB->ODR = matrix_buffer[index];
			if(bool == 1)	GPIOB->ODR = matrix_buffer1[index];
			if(bool == 2)	GPIOB->ODR = matrix_buffer2[index];
			if(bool == 3)	GPIOB->ODR = matrix_buffer3[index];
			if(bool == 4)	GPIOB->ODR = matrix_buffer4[index];
			if(bool == 5)	GPIOB->ODR = matrix_buffer5[index];
			break;

		case 1:
			if(bool == 0)	GPIOB->ODR = matrix_buffer[index];
			if(bool == 1)	GPIOB->ODR = matrix_buffer1[index];
			if(bool == 2)	GPIOB->ODR = matrix_buffer2[index];
			if(bool == 3)	GPIOB->ODR = matrix_buffer3[index];
			if(bool == 4)	GPIOB->ODR = matrix_buffer4[index];
			if(bool == 5)	GPIOB->ODR = matrix_buffer5[index];
			break;
		case 2:
			if(bool == 0)	GPIOB->ODR = matrix_buffer[index];
			if(bool == 1)	GPIOB->ODR = matrix_buffer1[index];
			if(bool == 2)	GPIOB->ODR = matrix_buffer2[index];
			if(bool == 3)	GPIOB->ODR = matrix_buffer3[index];
			if(bool == 4)	GPIOB->ODR = matrix_buffer4[index];
			if(bool == 5)	GPIOB->ODR = matrix_buffer5[index];
			break;
		case 3:
			if(bool == 0)	GPIOB->ODR = matrix_buffer[index];
			if(bool == 1)	GPIOB->ODR = matrix_buffer1[index];
			if(bool == 2)	GPIOB->ODR = matrix_buffer2[index];
			if(bool == 3)	GPIOB->ODR = matrix_buffer3[index];
			if(bool == 4)	GPIOB->ODR = matrix_buffer4[index];
			if(bool == 5)	GPIOB->ODR = matrix_buffer5[index];
			break;
		case 4:
			if(bool == 0)	GPIOB->ODR = matrix_buffer[index];
			if(bool == 1)	GPIOB->ODR = matrix_buffer1[index];
			if(bool == 2)	GPIOB->ODR = matrix_buffer2[index];
			if(bool == 3)	GPIOB->ODR = matrix_buffer3[index];
			if(bool == 4)	GPIOB->ODR = matrix_buffer4[index];
			if(bool == 5)	GPIOB->ODR = matrix_buffer5[index];
			break;
		case 5:
			if(bool == 0)	GPIOB->ODR = matrix_buffer[index];
			if(bool == 1)	GPIOB->ODR = matrix_buffer1[index];
			if(bool == 2)	GPIOB->ODR = matrix_buffer2[index];
			if(bool == 3)	GPIOB->ODR = matrix_buffer3[index];
			if(bool == 4)	GPIOB->ODR = matrix_buffer4[index];
			if(bool == 5)	GPIOB->ODR = matrix_buffer5[index];
			break;
		case 6:
			GPIOB->ODR = matrix_buffer[index];
			break;
		case 7:
			GPIOB->ODR = matrix_buffer[index];
			break;
		default :
			break ;
		}
	}
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer0(10);
  while (1)
  {
    /* USER CODE END WHILE */
	  if(timer0_flag == 1){
		  if(index_led_matrix >= MAX_LED_MATRIX){
			  index_led_matrix=0;
			  bool+=1;
			  if(bool > 5) bool =0;
		  }
		  updateLEDMatrix(index_led_matrix);
		  index_led_matrix++;
		  setTimer0(10);
	  }
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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
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
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, ENM0_Pin|ENM1_Pin|ENM2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           SEG2_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin ENM2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|ENM2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
 {



	 timer_run();
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