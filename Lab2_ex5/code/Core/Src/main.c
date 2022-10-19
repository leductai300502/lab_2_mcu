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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
//----------------------------------
void display7SEG(int num){
	if(num == 0){
	GPIOB->ODR = 0xC0; //Displaying 0
	}
	if(num == 1){
	GPIOB->ODR = 0xF9; //Displaying 1
	}
	if(num == 2){
	GPIOB->ODR = 0xA4; //Displaying 2
	}
	if(num == 3){
	GPIOB->ODR = 0xB0; //Displaying 3
	}
	if(num == 4){
	GPIOB->ODR = 0x99; //Displaying 4
	}
	if(num == 5){
	GPIOB->ODR = 0x92; //Displaying 5
	}
	if(num == 6){
	GPIOB->ODR = 0x82; //Displaying 6
	}
	if(num == 7){
	GPIOB->ODR = 0xF8; //Displaying 7
	}
	if(num == 8){
	GPIOB->ODR = 0x80; //Displaying 8
	}
	if(num == 9){
	GPIOB->ODR = 0x90; //Displaying 9
	}
}
//----------------------------------
int hour = 15 , minute = 8 , second = 50;
int led_buffer[4] = {1 , 2 , 3 , 4};
int index_led =0;
int MAX_LED =4;
void updateClockBuffer(){


	    	 led_buffer[0] = hour/10;
	    	 led_buffer[1] = hour%10;

	         led_buffer[2]= minute/10;
	         led_buffer[3]= minute%10;

}
//--------------------------
void update7SEG ( int index ){
 switch ( index ) {
 case 0:
 // Display the first 7 SEG with led_buffer [0]
	 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	 display7SEG(led_buffer[index]);
 break ;
 case 1:
 // Display the second 7 SEG with led_buffer [1]
	 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	 display7SEG(led_buffer[index]);
 break ;
 case 2:
 // Display the third 7 SEG with led_buffer [2]
	 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	 display7SEG(led_buffer[index]);
 break ;
 case 3:
 // Display the forth 7 SEG with led_buffer [3]
	 HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	 HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	 HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	 HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	 display7SEG(led_buffer[index]);
 break ;
 default :
 break ;
 }
}
//---------------------------
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

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  if(index_led >= MAX_LED) index_led =0;
	  updateClockBuffer () ;
	  update7SEG(index_led);
	  index_led++;
	  second ++;
	  if ( second >= 60) {
		  second = 0;
		  minute ++;
	  }
	  if( minute >= 60) {
		  minute = 0;
		  hour ++;
	  }
	  if( hour >=24) {
		  hour = 0;
	  }
	  HAL_Delay(1000);
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
  HAL_GPIO_WritePin(GPIOA, DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                          |SEG4_Pin|SEG5_Pin|SEG6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DOT_Pin LED_RED_Pin EN0_Pin EN1_Pin
                           EN2_Pin EN3_Pin */
  GPIO_InitStruct.Pin = DOT_Pin|LED_RED_Pin|EN0_Pin|EN1_Pin
                          |EN2_Pin|EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin SEG3_Pin
                           SEG4_Pin SEG5_Pin SEG6_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin
                          |SEG4_Pin|SEG5_Pin|SEG6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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