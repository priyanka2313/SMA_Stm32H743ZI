# SMA_Stm32H743ZI

This repository cotains programs for implementing basic functions of signal generation, signal read, saving sensor data and plotting on an STM32H743ZI board.

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
