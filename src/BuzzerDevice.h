#ifndef __BUZZERDEVICE_H__
#define __BUZZERDEVICE_H__

#include "AbstractDevice.h"

class BuzzerDevice : public AbstractDevice
{
private:
    int buzzerPin;
    int ms;
    uint64_t timeStarted;
public:
    BuzzerDevice(int buzzerPin);
    ~BuzzerDevice();
    void setup();
    void loop();
    void beep(int ms);
    String getSetupMessage();
};

#endif // __BUZZERDEVICE_H__
