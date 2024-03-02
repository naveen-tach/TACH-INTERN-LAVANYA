/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "string.h"
#include "result_format.h"
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
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
UART_HandleTypeDef huart1;

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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

//  uint8_t model[]="PI1-05 P\n";
//  uint8_t company[]="-01-001 Ver.1.0\n";
//  Vaccum_test_result_title(model,company);
//  uint8_t company_name[] = "\n";
//  uint8_t location[]="\n";
//  uint8_t test_date[]="23/02/2024\n";
//  uint8_t test_start_time[] = "12:22:20\n";
//  uint8_t test_end_time []= "27:33:02\n";
//  uint8_t user_name[]="\n";
//
//  Vaccum_test_result_report(company_name,location,test_date,test_start_time,test_end_time,user_name);
//
//  uint8_t prod_name[]="\n";
//  uint8_t prod_no[]="\n";
//  uint8_t batch_no[]="\n";
//  uint8_t batch_size[]="\n";
//  uint8_t sample_qty[]="\n";
//  uint8_t package_type[] ="\n";
//  uint8_t tolerance[] ="\n";
//
//  User_prod_details(prod_name,prod_no,batch_no,batch_size,sample_qty,package_type,tolerance);
//
//  uint8_t set_vaccum[]="060 mm/Hg\n";
//  uint8_t act_vaccum[]="060 mm/Hg\n";
//  uint8_t set_pressure[]="0.0799 bar\n";
//  uint8_t act_pressure[]="0.0799 bar\n";
////  uint8_t test_duration[]="0005 sec\n";
//
//
//  Test_settings(set_vaccum,act_vaccum,set_pressure,act_pressure);

//  uint8_t test_duration[] ="\n";
//  uint8_t test_sample_no[] ="\n";
//  uint8_t weight_before_test[] ="\n";
//  uint8_t weight_after_test[] ="\n";
//  uint8_t difference[]="\n";
//  uint8_t test_result[]="\n";

//  Test_result(test_duration,test_sample_no,weight_before_test,weight_after_test,difference,test_result);

//  uint8_t performed_by[]="\n";
//  uint8_t test_status[]="\n";
//  uint8_t verified_by[]="\n";
//  uint8_t sign[]="\n";

//  Test_status(test_status,performed_by,verified_by,sign);

// uint8_t date[]="23/02/2024 ";
// uint8_t time[]="19:22:33\n";
// Printred_on(date,time);

//Validation function calling...

  uint8_t model[]="PI1-05 P\n";
  uint8_t company[]="-01-001 Ver.1.0\n";

  Vaccum_test_result_title(model,company);

  uint8_t company_name[]="\n";
  uint8_t location[]="\n";
  uint8_t test_date[]="\n";
  uint8_t test_start_time[]="\n";
  uint8_t test_end_time[]="\n";

  Validation_report_start(company_name,location,test_date,test_start_time,test_end_time);

  uint8_t prod_name[]="\n";
  uint8_t prod_no[]="\n";

  Validation_report_product_details(prod_name,prod_no);

  uint8_t test_number[]="\n";
  uint8_t input[]="\n";
  uint8_t maintained[]="\n";
  uint8_t meter[]="\n";
  uint8_t difference[]="\n";
  uint8_t results[]="\n";

  Validation_report_results(test_number,input,maintained,meter,difference,results);
  uint8_t performed_by[]="\n";
  uint8_t verified_by[]="\n";
  uint8_t sign[]="\n";
  Validation_report_end(performed_by,verified_by,sign);

  uint8_t date[]="23/02/2024 ";
  uint8_t time[]="19:22:33\n";
  Printred_on(date,time);




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

//  uint8_t data2[] = "Package Integrity tester\n";
  while (1)
  {
//	  HAL_UART_Transmit(&huart1,&data1, strlen(data1), HAL_MAX_DELAY);
//	  HAL_UART_Transmit(&huart1, &data, strlen(data), HAL_MAX_DELAY);
//	  HAL_Delay(1000);
//	  HAL_UART_Transmit(&huart1, &data2, strlen(data2), HAL_MAX_DELAY);

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
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
