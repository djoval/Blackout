#ifndef __BATTARYDEVICE_H__
#define __BATTARYDEVICE_H__
#include "AbstractDevice.h"

class BatteryDevice : public AbstractDevice
{
private:
    int voltagePin;
    int enablePin;
    int vref;
    float batteryVoltage;
    
    
public:
    BatteryDevice(int voltagePin, int enablePin);
    ~BatteryDevice();
    void setup();
    void loop();
    String getSetupMessage();
    bool isBatteryCharhing();
    float getBatteryVoltage();
    void updateVoltage();
};

#endif // __BATTARYDEVICE_H__

