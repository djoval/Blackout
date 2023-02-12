#ifndef __PWMDEVICE_H__
#define __PWMDEVICE_H__

#include "AbstractDevice.h"
#include "esp32-hal-ledc.h"

class PwmDevice : public AbstractDevice
{
private:
    int pwmChanal;
    int pwmPin;
    int pwmLevel;

public:
    PwmDevice(int pwmChanal, int pwmPin, int pwmLevel);
    ~PwmDevice();
    void setup();
    void loop();
    String getSetupMessage();

    void setPwmLevel(int pwmLevel);
    int getPwmLevel();

};

#endif // __PWMDEVICE_H__

