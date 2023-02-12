#ifndef __DEVICE_H__
#define __DEVICE_H__



#include "Arduino.h"
#include "deviceConfig.h"
///////////////////////////////////////////

#include "BatteryDevice.h"
#include "BuzzerDevice.h"
#include "Network.h"
#include "PwmDevice.h"
#include "SerialPort.h"
#include "DisplayDevice.h"
#include "TimeDevice.h"
#include "Logger.h"

class Device
{
private:
    unsigned long lastPowerDown;
    unsigned long lastPowerUp;
    bool lastPowerState = false;
    bool lastQuetTimeState = false;

    void espDelay(int ms);
    void onPowerUp();
    void onPowerDown();
    void checkPowerState();
    void updateDateTime();
    void setDisplayBrightness();

    BatteryDevice battery = BatteryDevice(ADC_PIN, ADC_EN);
    BuzzerDevice buzzer = BuzzerDevice(BUZZER_PIN);
    Network network = Network(WIFI_SSID, WIFI_PASSWORD);
    PwmDevice pwm = PwmDevice(PWM_CHANAL, TFT_BL, HIGH_BRIGHTNES_LEVEL);
    SerialPort serial = SerialPort(SERIAL_SPEED);
    TimeDevice time = TimeDevice(BEGIN_QUET_HOUR, END_QUET_HOUR);
    DisplayDevice display = DisplayDevice();
    Logger logger = Logger(&time);

    void updateDisplayData();

public:
    Device();
    ~Device();
    void setup();
    void loop();
    String getSetupMessage();
    void beforePowerDown(void);
};

#endif // __DEVICE_H__

