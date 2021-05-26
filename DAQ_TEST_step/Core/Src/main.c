/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "math.h"
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

DAC_HandleTypeDef hdac1;

TIM_HandleTypeDef htim6;

/* USER CODE BEGIN PV */

uint32_t square_values[]={3730, 3730, 3730, 3730, 0, 0, 0, 0};
//uint32_t values[128];
uint32_t sine_values[]={291,345,403,465,531,600,673,749,828,910,995,1083,1172,1264,1358,1453,1550,1648,1747,1847,1948,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465,531,600,673,749,828,910,995,1083,1172,1264,1358,1453,1550,1648,1747,1847,1948,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465,531,600,673,749,828,910,995,1083,1172,1264,1358,1453,1550,1648,1747,1847,1948,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465,531,600,673,749,828,910,995,1083,1172,1264,1358,1453,1550,1648,1747,1847,1948,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465,531,600,673,749,828,910,995,1083,1172,1264,1358,1453,1550,1648,1747,1847,1948,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465,531,600,673,749,828,910,995,1083,1172,1264,1358,1453,1550,1648,1747,1847,1948,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242};
//uint32_t sinval[]={2048,2148,2248,2348,2447,2545,2642,2737,2831,2923,3013,3100,3185,3267,3346,3423,3495,3565,3630,3692,3750,3804,3853,3898,3939,3975,4007,4034,4056,4073,4085,4093,4095,4093,4085,4073,4056,4034,4007,3975,3939,3898,3853,3804,3750,3692,3630,3565,3495,3423,3346,3267,3185,3100,3013,2923,2831,2737,2642,2545,2447,2348,2248,2148,2048,1947,1847,1747,1648,1550,1453,1358,1264,1172,1082,995,910,828,749,672,600,530,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465,530,600,672,749,828,910,995,1082,1172,1264,1358,1453,1550,1648,1747,1847,1947};
//uint32_t siner[]={512,537,562,587,612,636,661,684,708,731,753,775,796,817,837,856,874,891,908,923,938,951,964,975,985,994,1002,1009,1014,1018,1022,1023,1024,1023,1022,1018,1014,1009,1002,994,985,975,964,951,938,923,908,891,874,856,837,817,796,775,753,731,708,684,661,636,612,587,562,537,512,487,462,437,412,388,363,340,316,293,271,249,228,207,187,168,150,133,116,101,86,73,60,49,39,30,22,15,10,6,2,1,0,1,2,6,10,15,22,30,39,49,60,73,86,101,116,133,150,168,187,207,228,249,271,293,316,340,363,388,412,437,462,487,512,537,562,587,612,636,661,684,708,731,753,775,796,817,837,856,874,891,908,923,938,951,964,975,985,994,1024,1074,1124,1174,1224,1273,1321,1369,1416,1462,1507,1550,1593,1634,1674,1712,1748,1783,1816,1846,1875,1902,1927,1950,1970,1988,2004,2017,2028,2037,2043,2047,2048,2047,2043,2037,2028,2017,2004,1988,1970,1950,1927,1902,1875,1846,1816,1783,1748,1712,1674,1634,1593,1550,1507,1462,1416,1369,1321,1273,1224,1174,1124,1074,1024,974,924,874,824,775,727,679,632,586,541,498,455,414,374,336,300,265,232,202,173,146,121,98,78,60,44,31,20,11,5,1,0,1,5,11,20,31,44,60,78,98,121,146,173,202,232,265,300,336,374,414,455,498,541,586,632,679,727,775,824,874,924,974,1024,1074,1124,1174,1224,1273,1321,1369,1416,1462,1507,1548,1624,1700,1775,1850,1924,1997,2070,2140,2210,2278,2344,2408,2470,2530,2588,2643,2695,2745,2791,2835,2876,2913,2947,2978,3006,3029,3050,3066,3079,3089,3094,3096,3094,3089,3079,3066,3050,3029,3006,2978,2947,2913,2876,2835,2791,2745,2695,2643,2588,2530,2470,2408,2344,2278,2210,2140,2070,1997,1924,1850,1775,1700,1624,1548,1472,1396,1321,1246,1172,1099,1026,956,886,818,752,688,626,566,508,453,401,351,305,261,220,183,149,118,90,67,46,30,17,7,2,0,2,7,17,30,46,67,90,118,149,183,220,261,305,351,401,453,508,566,626,688,752,818,886,956,1026,1099,1172,1246,1321,1396,1472,1548,1624,1700,1775,1850,1924,1997,2048,2148,2248,2348,2447,2545,2642,2737,2831,2923,3013,3100,3185,3267,3346,3423,3495,3565,3630,3692,3750,3804,3853,3898,3939,3975,4007,4034,4056,4073,4085,4093,4095,4093,4085,4073,4056,4034,4007,3975,3939,3898,3853,3804,3750,3692,3630,3565,3495,3423,3346,3267,3185,3100,3013,2923,2831,2737,2642,2545,2447,2348,2248,2148,2048,1947,1847,1747,1648,1550,1453,1358,1264,1172,1082,995,910,828,749,672,600,530,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465};
uint32_t sinerise_values[]={256,269,281,294,306,318,330,342,354,365,377,388,398,408,418,428,437,446,454,462,469,476,482,487,493,497,501,504,507,509,511,512,512,512,511,509,507,504,501,497,493,487,482,476,469,462,454,446,437,428,418,408,398,388,377,365,354,342,330,318,306,294,281,269,256,243,231,218,206,194,182,170,158,147,135,124,114,104,94,84,75,66,58,50,43,36,30,25,19,15,11,8,5,3,1,0,0,0,1,3,5,8,11,15,19,25,30,36,43,50,58,66,75,84,94,104,114,124,135,147,158,170,182,194,206,218,231,243,512,537,562,587,612,636,661,684,708,731,753,775,796,817,837,856,874,891,908,923,938,951,964,975,985,994,1002,1009,1014,1018,1022,1023,1024,1023,1022,1018,1014,1009,1002,994,985,975,964,951,938,923,908,891,874,856,837,817,796,775,753,731,708,684,661,636,612,587,562,537,512,487,462,437,412,388,363,340,316,293,271,249,228,207,187,168,150,133,116,101,86,73,60,49,39,30,22,15,10,6,2,1,0,1,2,6,10,15,22,30,39,49,60,73,86,101,116,133,150,168,187,207,228,249,271,293,316,340,363,388,412,437,462,487,768,806,843,881,918,955,991,1027,1062,1096,1130,1163,1195,1225,1255,1284,1311,1337,1362,1385,1407,1427,1445,1462,1478,1491,1503,1513,1521,1528,1532,1535,1536,1535,1532,1528,1521,1513,1503,1491,1478,1462,1445,1427,1407,1385,1362,1337,1311,1284,1255,1225,1195,1163,1130,1096,1062,1027,991,955,918,881,843,806,768,730,693,655,618,581,545,509,474,440,406,373,341,311,281,252,225,199,174,151,129,109,91,74,58,45,33,23,15,8,4,1,0,1,4,8,15,23,33,45,58,74,91,109,129,151,174,199,225,252,281,311,341,373,406,440,474,509,545,581,618,655,693,730,1024,1074,1124,1174,1224,1273,1321,1369,1416,1462,1507,1550,1593,1634,1674,1712,1748,1783,1816,1846,1875,1902,1927,1950,1970,1988,2004,2017,2028,2037,2043,2047,2048,2047,2043,2037,2028,2017,2004,1988,1970,1950,1927,1902,1875,1846,1816,1783,1748,1712,1674,1634,1593,1550,1507,1462,1416,1369,1321,1273,1224,1174,1124,1074,1024,974,924,874,824,775,727,679,632,586,541,498,455,414,374,336,300,265,232,202,173,146,121,98,78,60,44,31,20,11,5,1,0,1,5,11,20,31,44,60,78,98,121,146,173,202,232,265,300,336,374,414,455,498,541,586,632,679,727,775,824,874,924,974,1280,1343,1405,1468,1530,1591,1652,1711,1770,1827,1883,1938,1991,2042,2092,2140,2185,2228,2269,2308,2344,2378,2409,2437,2463,2485,2505,2522,2535,2546,2554,2558,2560,2558,2554,2546,2535,2522,2505,2485,2463,2437,2409,2378,2344,2308,2269,2228,2185,2140,2092,2042,1991,1938,1883,1827,1770,1711,1652,1591,1530,1468,1405,1343,1280,1217,1155,1092,1030,969,908,849,790,733,677,622,569,518,468,420,375,332,291,252,216,182,151,123,97,75,55,38,25,14,6,2,0,2,6,14,25,38,55,75,97,123,151,182,216,252,291,332,375,420,468,518,569,622,677,733,790,849,908,969,1030,1092,1155,1217,1536,1611,1687,1761,1836,1909,1982,2053,2124,2193,2260,2326,2389,2451,2510,2568,2622,2674,2723,2770,2813,2853,2891,2925,2955,2982,3006,3026,3042,3055,3065,3070,3072,3070,3065,3055,3042,3026,3006,2982,2955,2925,2891,2853,2813,2770,2723,2674,2622,2568,2510,2451,2389,2326,2260,2193,2124,2053,1982,1909,1836,1761,1687,1611,1536,1461,1385,1311,1236,1163,1090,1019,948,879,812,746,683,621,562,504,450,398,349,302,259,219,181,147,117,90,66,46,30,17,7,2,0,2,7,17,30,46,66,90,117,147,181,219,259,302,349,398,450,504,562,621,683,746,812,879,948,1019,1090,1163,1236,1311,1385,1461,1792,1880,1968,2055,2142,2227,2312,2396,2478,2558,2637,2713,2788,2859,2929,2995,3059,3120,3177,3231,3282,3329,3372,3412,3448,3479,3507,3530,3550,3565,3575,3582,3584,3582,3575,3565,3550,3530,3507,3479,3448,3412,3372,3329,3282,3231,3177,3120,3059,2995,2929,2859,2788,2713,2637,2558,2478,2396,2312,2227,2142,2055,1968,1880,1792,1704,1616,1529,1442,1357,1272,1188,1106,1026,947,871,796,725,655,589,525,464,407,353,302,255,212,172,136,105,77,54,34,19,9,2,0,2,9,19,34,54,77,105,136,172,212,255,302,353,407,464,525,589,655,725,796,871,947,1026,1106,1188,1272,1357,1442,1529,1616,1704,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242,291,345,403,465,531,600,673,749,828,910,995,1083,1172,1264,1358,1453,1550,1648,1747,1847,1948,2048,2148,2249,2349,2448,2546,2643,2738,2832,2924,3013,3101,3186,3268,3347,3423,3496,3565,3631,3693,3751,3805,3854,3899,3940,3976,4008,4035,4057,4074,4086,4094,4095,4094,4086,4074,4057,4035,4008,3976,3940,3899,3854,3805,3751,3693,3631,3565,3496,3423,3347,3268,3186,3101,3013,2924,2832,2738,2643,2546,2448,2349,2249,2148,2048,1948,1847,1747,1648,1550,1453,1358,1264,1172,1083,995,910,828,749,673,600,531,465,403,345,291,242,197,156,120,88,61,39,22,10,2,0,2,10,22,39,61,88,120,156,197,242};


uint32_t i=0,j=0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DAC1_Init(void);
static void MX_TIM6_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
//Uncomment this section to generate rising sine signal
	if(i<1130)
	{
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sinerise_values[i]);
		i++;
	}
	if(i>=1130)
	{
		i=1130;
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sine_values[j]);
		j++;

	}

	if(j>=512)
		{j=0;
		//i=0;
		}
// Uncomment this section to genrate sine values and also the variable sinval[]
//	if(i>=8)
//	{
//		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sinval[i]);
//		i=0;
//	}
//	i++;

	// Uncomment this section to genrate squarewave values and also the variable square_values[]
	//	if(i>=128)
	//	{
	//		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, square_values[i]);
	//		i=0;
	//	}
	//	i++;

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
  MX_DAC1_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_Base_Start_IT(&htim6);

//  get_sineval();
//  HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, sqval, 100, DAC_ALIGN_12B_R);

  //sine wave freq 100. to cgange freq change the samples
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

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 12;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 4096;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief DAC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_DAC1_Init(void)
{

  /* USER CODE BEGIN DAC1_Init 0 */

  /* USER CODE END DAC1_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC1_Init 1 */

  /* USER CODE END DAC1_Init 1 */
  /** DAC Initialization
  */
  hdac1.Instance = DAC1;
  if (HAL_DAC_Init(&hdac1) != HAL_OK)
  {
    Error_Handler();
  }
  /** DAC channel OUT1 config
  */
  sConfig.DAC_SampleAndHold = DAC_SAMPLEANDHOLD_DISABLE;
  sConfig.DAC_Trigger = DAC_TRIGGER_T6_TRGO;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  sConfig.DAC_ConnectOnChipPeripheral = DAC_CHIPCONNECT_DISABLE;
  sConfig.DAC_UserTrimming = DAC_TRIMMING_FACTORY;
  if (HAL_DAC_ConfigChannel(&hdac1, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC1_Init 2 */

  /* USER CODE END DAC1_Init 2 */

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 0;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 4095;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

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
