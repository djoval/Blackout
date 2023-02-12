#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "Arduino.h"
#include "TimeDevice.h"

class Logger
{

private:
    TimeDevice* time;
public:
    Logger(TimeDevice* time);
    ~Logger();
    void AddToLog(String message);
};

#endif // __LOGGER_H__

