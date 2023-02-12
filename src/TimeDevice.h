#ifndef __TIMEDEVICE_H__
#define __TIMEDEVICE_H__

#include "AbstractDevice.h"
#include "time.h"
#include "ESP32Time.h"

typedef void (*OnAlarmHandler_t)();

class TimeDevice : public AbstractDevice
{
private:
    const char *ntpServer = "pool.ntp.org";
    const long gmtOffset_sec = 2 * 3600; // GMT + 3
    const int daylightOffset_sec = 3600;
    ESP32Time rtc;
    bool isTimeSetOk;
    int beginQuetHour;
    int endQuetHour;

    bool isAlarmSetted;
    time_t alarmTime;
    OnAlarmHandler_t onAlarmHandler;

public:
    TimeDevice(int beginQuetHour, int endQuetHour);
    ~TimeDevice();
    void setup();
    void loop();
    String getSetupMessage();

    String secToTime(long sec);
    String getCurrentTime();
    String getCurrentDateTime();
    unsigned long getTimeStamp(); 
    bool isQuetTime();
    void updateTimeFromNetwork();
    void setAlarm(time_t alarmTime, OnAlarmHandler_t onAlarmHandler);


    bool getIsTimeSetOk() {
    	return this->isTimeSetOk;
    }
};

#endif // __TIMEDEVICE_H__

