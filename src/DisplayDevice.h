#ifndef __TFTDEVICE_H__
#define __TFTDEVICE_H__

#include "AbstractDevice.h"
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

#include "fonts/TekoMedium24.h"
#include "fonts/TekoMedium36.h"
#include "fonts/TekoMedium72.h"

#define AA_FONT_SMALL TekoMedium24
#define AA_FONT_MEDIUM TekoMedium36
#define AA_FONT_LARGE TekoMedium72

class DisplayDevice : public AbstractDevice 
{
private:
    TFT_eSPI tft = TFT_eSPI(); // Invoke library, pins defined in User_Setup.h
    String lastChangedState;
    int lastChangedStateColor;
    float batteryVoltage;
    String lastEventTime;
    int lastEventColor;
    String currentTime;
    bool isDisplayOff;

public:
    DisplayDevice(/* args */);
    ~DisplayDevice();
    void setup();
    void loop();
    String getSetupMessage();


    void setLastChangedState(int lastChangedStateColor, String lastChangedState);
    void setLastEvent(int lastEventColor, String lastEventTime);
    void turnOffDisplay();


    void setBatteryVoltage(float batteryVoltage) {
    	this->batteryVoltage = batteryVoltage;
    }

    void setCurrentTime(String currentTime) {
    	this->currentTime = currentTime;
    }
};

#endif // __TFTDEVICE_H__
