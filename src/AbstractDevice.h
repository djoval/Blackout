#ifndef __ABSTRACTDEVICE_H__
#define __ABSTRACTDEVICE_H__
#include "Arduino.h"
class AbstractDevice
{
private:
    /* data */
public:
    virtual void setup() = 0;
    virtual void loop() = 0;
    virtual String getSetupMessage() = 0;
};

#endif // __ABSTRACTDEVICE_H__



