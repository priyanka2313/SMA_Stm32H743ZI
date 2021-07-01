# SMA_Stm32H743ZI

This repository contains programs for implementing basic functions of signal generation, signal read, saving sensor data and plotting on an STM32H743ZI board.

## Getting Started

### Prerequisites
1. Digitally signed USB driver for ST-Link/V2, ST-Link/V2-1 and STLINK-V3 on Windows7, Windows8 and Windows10, 32 and 64 bits.
   - To install the driver, run 'stlink_winusb_install.bat' in administrator mode, before connecting any ST-Link to the PC.
2. STM32Cubeide
   - To be downloaded from the ST website.
   - Run 'st-stm32cubeide_1.5.1_9029_20201210_1234_x86_64.exe' file to install.
   
## DAC 
### DAC Settings
DAC 
- OUT1 - only to external pin.
- Normal Mode
- Output Buffer - Enable
- Trigger - Timer 6 Triggr Out Event (In the given codes, timer6 is used. This section can be changed according to the timers being used)
- NVIC Settings - TIM6 global interrupt enabled.

Timer (Timer 6)
- Prescaler - 0
- Counter Period - 4095
- Trigger Event Selection - Update Event

[DAC_TEST_Step]() 
- This file generates signals from a lookuptable. 
- To get a given signal uncomment the required section of code and variables mentioned in main.

[Random_signal_test]()
- This program allows to generate random signals

## [ADC Read] (https://drive.google.com/drive/folders/1jR2dddmhVlRCe3YemqBflgYDhnIt6Tlr?usp=sharing)
### ADC Settings
ADC
- ADC1- INP15
- Conversion data management - DMA Circular
- External trigger conversion source - Timer 3 trigger out event
- DMA settings mentioned in the main file

Timer (Timer 3, 100Mhz)
- Clock source - Internal clock
- Channel 1 - Output compare no output
- Prescalar - 10-1 (10Mhz)
- Counter Period - 10-1 (1Mhz)
- Trigger Event Selection - Update Event

Connectivity - Usart3 

### Serial output in STM32Cubeide
- Open console -> Command shell console 
- Select ISO-8859-1 and give a connection name.
