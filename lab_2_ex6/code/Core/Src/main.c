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
int hour = 15 , minute = 8 , second = 50;
int led_buffer[4] = {1 , 2 , 3 , 4};
void updateClockBuffer(){
	// if hour <10 , 7seg1 = 0 , 7seg2 = hour
     if(hour < 10 ){
    	 led_buffer[0] = 0;
    	 led_buffer[1] = hour;
     }
     if(hour %10 == 0){
    	 led_buffer[0] = hour/10;
    	 led_buffer[1] = 0;
     }
     else{
    	 led_buffer[0]= hour/10;
    	 led_buffer[1]= hour%10;
     }
     //
     if(minute < 10 ){
         led_buffer[2] = 0;
         led_buffer[3] = minute;
      }
     if(minute %10 == 0){
         led_buffer[2] = minute/10;
         led_buffer[3] = 0;
       }
      else{
         led_buffer[2]= minute/10;
         led_buffer[3]= minute%10;
       }
}
//--------------------------
void digital_clock(){
 // Display the first 7 SEG with led_buffer [0]
	 if(led_buffer[0] == 0){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
	 	 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
	 	 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
	 	 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
 		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
 		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
 		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, SET);
	 }
	 if(led_buffer[0] == 1){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, SET);;
	 }
	 if(led_buffer[0] == 2){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
	 }
	 if(led_buffer[0] == 3){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
	 }
	 if(led_buffer[0] == 4){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
	 }
	 if(led_buffer[0] == 5){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
	 }
	 if(led_buffer[0] == 6){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
	 }
	 if(led_buffer[0] == 7){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, SET);
	 }
	 if(led_buffer[0] == 8){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
	 }
	 if(led_buffer[0] == 9){
		 HAL_GPIO_WritePin(SEG1_A_GPIO_Port, SEG1_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_B_GPIO_Port, SEG1_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_C_GPIO_Port, SEG1_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_D_GPIO_Port, SEG1_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_E_GPIO_Port, SEG1_E_Pin, SET);
		 HAL_GPIO_WritePin(SEG1_F_GPIO_Port, SEG1_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG1_G_GPIO_Port, SEG1_G_Pin, RESET);
	 }
 // Display the second 7 SEG with led_buffer [1]
	 if(led_buffer[1] == 0){
		 HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
		 HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
		 HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
		 HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, RESET);
		 HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, RESET);
		 HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, RESET);
		 HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, SET);
	 	 }
	 	 if(led_buffer[1] == 1){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, SET);
	 	 }
	 	 if(led_buffer[1] == 2){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, RESET);
	 	 }
	 	 if(led_buffer[1] == 3){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, RESET);
	 	 }
	 	 if(led_buffer[1] == 4){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, RESET);
	 	 }
	 	 if(led_buffer[1] == 5){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, RESET);
	 	 }
	 	 if(led_buffer[1] == 6){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, RESET);
	 	 }
	 	 if(led_buffer[1] == 7){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, SET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, SET);
	 	 }
	 	 if(led_buffer[1] == 8){
	 		HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, RESET);
	 		HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, RESET);
	 	 }
	 	 if(led_buffer[1] == 9){
	 		 HAL_GPIO_WritePin(SEG2_A_GPIO_Port, SEG2_A_Pin, RESET);
	 		 HAL_GPIO_WritePin(SEG2_B_GPIO_Port, SEG2_B_Pin, RESET);
	 		 HAL_GPIO_WritePin(SEG2_C_GPIO_Port, SEG2_C_Pin, RESET);
	 		 HAL_GPIO_WritePin(SEG2_D_GPIO_Port, SEG2_D_Pin, RESET);
	 		 HAL_GPIO_WritePin(SEG2_E_GPIO_Port, SEG2_E_Pin, SET);
	 		 HAL_GPIO_WritePin(SEG2_F_GPIO_Port, SEG2_F_Pin, RESET);
	 		 HAL_GPIO_WritePin(SEG2_G_GPIO_Port, SEG2_G_Pin, RESET);
	 	 };

 // Display the third 7 SEG with led_buffer [2]
	    	if(led_buffer[2] == 0){
	    		 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	    		 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	    		 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	    		 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, RESET);
	    		 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, RESET);
	    		 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, RESET);
	    		 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, SET);
	 		 }
	 		 if(led_buffer[2] == 1){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, SET);
	 		 }
	 		 if(led_buffer[2] == 2){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, RESET);
	 		 }
	 		 if(led_buffer[2] == 3){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, RESET);
	 		 }
	 		 if(led_buffer[2] == 4){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, RESET);
	 		 }
	 		 if(led_buffer[2] == 5){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, RESET);
	 		 }
	 		 if(led_buffer[2] == 6){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, RESET);
	 		 }
	 		 if(led_buffer[2] == 7){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, SET);
	 		 }
	 		 if(led_buffer[2] == 8){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, RESET);
	 		 }
	 		 if(led_buffer[2] == 9){
	 			 HAL_GPIO_WritePin(SEG3_A_GPIO_Port, SEG3_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_B_GPIO_Port, SEG3_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_C_GPIO_Port, SEG3_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_D_GPIO_Port, SEG3_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_E_GPIO_Port, SEG3_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG3_F_GPIO_Port, SEG3_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG3_G_GPIO_Port, SEG3_G_Pin, RESET);
	 		 }

 // Display the forth 7 SEG with led_buffer [3]
	 		if(led_buffer[3] == 0){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, SET);
	 		}
	 		if(led_buffer[3] == 1){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, SET);
	 		}
	 		if(led_buffer[3] == 2){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, RESET);
	 		}
	 		if(led_buffer[3] == 3){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, RESET);
	 		}
	 		if(led_buffer[3] == 4){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, RESET);
	 		}
	 		if(led_buffer[3] == 5){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, RESET);
	 		}
	 		if(led_buffer[3] == 6){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, RESET);
	 		}
	 		if(led_buffer[3] == 7){
	 			 HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			 HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, SET);
	 			 HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, SET);
	 		}
	 		if(led_buffer[3] == 8){
	 			HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, RESET);
	 		}
	 		if(led_buffer[3] == 9){
	 			HAL_GPIO_WritePin(SEG4_A_GPIO_Port, SEG4_A_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_B_GPIO_Port, SEG4_B_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_C_GPIO_Port, SEG4_C_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_D_GPIO_Port, SEG4_D_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_E_GPIO_Port, SEG4_E_Pin, SET);
	 			HAL_GPIO_WritePin(SEG4_F_GPIO_Port, SEG4_F_Pin, RESET);
	 			HAL_GPIO_WritePin(SEG4_G_GPIO_Port, SEG4_G_Pin, RESET);
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
  setTimer0(1000);
  while (1)
  {
    /* USER CODE END WHILE */
	  if( timer0_flag == 1) {
	  		  HAL_GPIO_TogglePin( LED_RED_GPIO_Port , LED_RED_Pin ) ;
	  		  setTimer0(2000);
	  	  }
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
	  	  updateClockBuffer () ;
	  	  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	  	  digital_clock();
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
  HAL_GPIO_WritePin(GPIOA, SEG1_A_Pin|SEG1_B_Pin|SEG1_C_Pin|SEG1_D_Pin
                          |SEG1_E_Pin|SEG1_F_Pin|SEG1_G_Pin|SEG2_A_Pin
                          |SEG2_B_Pin|SEG2_C_Pin|SEG2_D_Pin|SEG2_E_Pin
                          |SEG2_F_Pin|SEG2_G_Pin|EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG3_A_Pin|SEG3_B_Pin|SEG3_C_Pin|SEG4_D_Pin
                          |SEG4_E_Pin|SEG4_F_Pin|SEG4_G_Pin|LED_RED_Pin
                          |DOT_Pin|SEG3_D_Pin|SEG3_E_Pin|SEG3_F_Pin
                          |SEG3_G_Pin|SEG4_A_Pin|SEG4_B_Pin|SEG4_C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SEG1_A_Pin SEG1_B_Pin SEG1_C_Pin SEG1_D_Pin
                           SEG1_E_Pin SEG1_F_Pin SEG1_G_Pin SEG2_A_Pin
                           SEG2_B_Pin SEG2_C_Pin SEG2_D_Pin SEG2_E_Pin
                           SEG2_F_Pin SEG2_G_Pin EN_Pin */
  GPIO_InitStruct.Pin = SEG1_A_Pin|SEG1_B_Pin|SEG1_C_Pin|SEG1_D_Pin
                          |SEG1_E_Pin|SEG1_F_Pin|SEG1_G_Pin|SEG2_A_Pin
                          |SEG2_B_Pin|SEG2_C_Pin|SEG2_D_Pin|SEG2_E_Pin
                          |SEG2_F_Pin|SEG2_G_Pin|EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG3_A_Pin SEG3_B_Pin SEG3_C_Pin SEG4_D_Pin
                           SEG4_E_Pin SEG4_F_Pin SEG4_G_Pin LED_RED_Pin
                           DOT_Pin SEG3_D_Pin SEG3_E_Pin SEG3_F_Pin
                           SEG3_G_Pin SEG4_A_Pin SEG4_B_Pin SEG4_C_Pin */
  GPIO_InitStruct.Pin = SEG3_A_Pin|SEG3_B_Pin|SEG3_C_Pin|SEG4_D_Pin
                          |SEG4_E_Pin|SEG4_F_Pin|SEG4_G_Pin|LED_RED_Pin
                          |DOT_Pin|SEG3_D_Pin|SEG3_E_Pin|SEG3_F_Pin
                          |SEG3_G_Pin|SEG4_A_Pin|SEG4_B_Pin|SEG4_C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback( TIM_HandleTypeDef * htim )
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
