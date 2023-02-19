#ifndef __DEVICECONFIG_H__
#define __DEVICECONFIG_H__

#include "secrets.h"
////////////////////////////////////////// Physical Device settings
#define TFT_BLACK 0x0000 // black
// TTGO T-Display pins
#define TFT_MOSI 19
#define TFT_SCLK 18
#define TFT_CS 5
#define TFT_DC 16
#define TFT_RST 23
#define TFT_BL 4

#define I2C_SDA 21 // SPI memory
#define I2C_SCL 22 // SPI memory

#define ADC_EN 14  // ADC_EN is the ADC detection enable port
#define ADC_PIN 34 // Power supply adc
#define BUTTON_1 35
#define BUTTON_2 0

#define BUZZER_PIN 21
#define PWM_CHANAL 1

#define SERIAL_SPEED 115200

////////////////////////////////////////// Logicacal Device settings
#define HIGH_BRIGHTNES_LEVEL 255
#define LOW_BRIGHTNES_LEVEL 10
#define BEGIN_QUET_HOUR 23
#define END_QUET_HOUR 10

#define POWER_OFF_HOURS 4
#define POWER_ON_HOURS 5
#define BEEP_BEFORE_POWER_OFF_MIN 15
//////////////////////////////////////////

#endif // __DEVICECONFIG_H__


