/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

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
uint32_t ticks_last = 0;
float state_last = 0;
uint32_t count =0;
float state_now;
uint32_t count1 = 0;
uint32_t t;
uint8_t rx_msg[4];
uint8_t rx_data[8];
uint8_t tx_data[8] = {0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x00};
uint32_t transmit_box;

CAN_RxHeaderTypeDef rx_header;
CAN_TxHeaderTypeDef tx_header = {
  .StdId = 0x200,
  .ExtId = 0,
  .IDE = CAN_ID_STD,
  .RTR = CAN_RTR_DATA,
  .DLC = 8,
  .TransmitGlobalTime = DISABLE
};
CAN_FilterTypeDef filter_config ={
  .FilterIdHigh = 0x0000,
  .FilterIdLow = 0x0000,
  .FilterMaskIdHigh = 0x0000,
  .FilterMaskIdLow = 0x0000,
  .FilterFIFOAssignment = CAN_FILTER_FIFO0,
  .FilterBank = 0,
  .FilterMode = CAN_FILTERMODE_IDMASK,
  .FilterScale = CAN_FILTERSCALE_32BIT,
  .FilterActivation = ENABLE
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_TIM1_Init();
  MX_UART7_Init();
  MX_CAN1_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
  uint8_t tx_msg[] = "RoboMaster";
  HAL_UART_Receive_IT(&huart7, rx_msg, 1);

  HAL_CAN_ConfigFilter(&hcan1,&filter_config);

  HAL_CAN_Start(&hcan1);

  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);


  HAL_TIM_Base_Start_IT(&htim6);

  //HAL_TIM_Base_Start(&htim1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    //UART_1
    // HAL_UART_Transmit(&huart7,tx_msg,10,1000);
    // HAL_Delay(1000);
    //PWM && IWDG
    // uint32_t arr_value = __HAL_TIM_GET_AUTORELOAD(&htim1) +1;
    // uint32_t brightness = arr_value * sinf(4 * HAL_GetTick() / 1000.f) -1;
    // __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,brightness);
    //
    // if (HAL_GPIO_ReadPin(KEY_GPIO_Port,KEY_Pin) == GPIO_PIN_SET) {
    //   HAL_IWDG_Refresh(&hiwdg);
    // }
    // }




    // TIMer
    // if (__HAL_TIM_GET_COUNTER(&htim1) > __HAL_TIM_GET_AUTORELOAD(&htim1) / 2) {
    //   HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_SET);
    // }
    // else {
    //   HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_RESET);
    // }

    // Second test
    // uint32_t ticks_now = HAL_GetTick();
    // state_last = state_now;
    // state_now = HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin);
    // if (state_last == GPIO_PIN_RESET && state_now == GPIO_PIN_SET) {
    //   led = !led;
    // }
    //
    // if (led ==1) {
    //   if (ticks_now - ticks_last >= 50) {
    //     HAL_GPIO_TogglePin(LEDR_GPIO_Port, LEDR_Pin);
    //     ticks_last = ticks_now;
    //     }
    //   }
    // else {
    //   if (ticks_now - ticks_last >= 50) {
    //     HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
    //     ticks_last = ticks_now;
    //   }
    // }

    // First test
    // if (state_now - state_last == GPIO_PIN_RESET) {
    //   state_last = state_now;
    // }
    // if (filter_state == GPIO_PIN_SET) {
    //   if (ticks_now - ticks_last >= 500) {
    //     HAL_GPIO_TogglePin(LEDR_GPIO_Port, LEDR_Pin);
    //     ticks_last = ticks_now;
    //   }
    // }
    // else {
    //   if (ticks_now - ticks_last >= 500) {
    //     HAL_GPIO_TogglePin(LEDG_GPIO_Port, LEDG_Pin);
    //     ticks_last = ticks_now;
    //   }
    // }

    }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
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
#ifdef USE_FULL_ASSERT
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
