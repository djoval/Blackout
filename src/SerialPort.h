#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__

#include "AbstractDevice.h"

class SerialPort : public AbstractDevice
{
private:
    int speed;
public:
    SerialPort(int speed);
    ~SerialPort();
    void loop();
    void setup();
    String getSetupMessage();

};

#endif // __SERIALPORT_H__
