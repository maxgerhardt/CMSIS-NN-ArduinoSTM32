# CMSIS-NN with ArduinoSTM32

CMSIS-NN library integrated with the STM32 Arduino core and PlatformIO

## Description

The neural networks implementation is aimed at all Cortex-M processors, but only really makes sense on Cortex-M4 and Cortex-M7 (and upwards) CPUs because of DSP (accelerates operations) and generally higher amounts of RAM and Flash which is found in microcontrollers incorporating this core.

The CMSIS DSP library found in the STM32Duino core is declared as a dependency and automatically included. 

## RTOS

Can also work in conjunction with other CMSIS components like CMSIS-RTOS2, as implemented in https://github.com/maxgerhardt/CMSIS-RTOS2-ArduinoSTM32.git. 

## Example project

Just use a `platformio.ini` like 

```
[platformio]
default_envs = nucleo_l476rg	

[env]
lib_deps = 
	CMSIS-NN=https://github.com/maxgerhardt/CMSIS-NN-ArduinoSTM32.git

; target a STM32L476rg chip
[env:nucleo_l476rg]
platform = ststm32
board = nucleo_l476rg
framework = arduino
```

and use the `.cpp` files from one of the examples. 
