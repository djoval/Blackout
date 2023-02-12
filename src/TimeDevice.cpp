#include "TimeDevice.h"

TimeDevice::TimeDevice(int beginQuetHour, int endQuetHour)
{
    this->beginQuetHour = beginQuetHour;
    this->endQuetHour = endQuetHour;
    this->isTimeSetOk = false;
    this->isAlarmSetted = false;
}

void TimeDevice::loop(){
  if(isAlarmSetted && getTimeStamp() >= alarmTime){
      isAlarmSetted = false;
      onAlarmHandler();
  }
}


TimeDevice::~TimeDevice()
{
}

void TimeDevice::setup(){
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  updateTimeFromNetwork();
}

bool TimeDevice::isQuetTime()
{
  return (rtc.getHour(true) >= beginQuetHour || rtc.getHour(true) < endQuetHour);
}


String TimeDevice::secToTime(long sec)
{
  String sign = " ";
  if (sec < 0)
  {
    sign = "-";
    sec = -sec;
  }

  int timeHours = (sec / 3600ul);       
  int timeMins = (sec % 3600ul) / 60ul; 
  int timeSecs = (sec % 3600ul) % 60ul; 
  char TextBuffer[12];
  sprintf(TextBuffer, "%02d:%02d:%02d", timeHours, timeMins, timeSecs);
  return sign + String(TextBuffer);
}

String TimeDevice::getCurrentDateTime()
{
  return rtc.getTime("%d-%m-%Y %H:%M:%S");
}

String TimeDevice::getCurrentTime()
{
  return rtc.getTime("%H : %M : %S");
}



unsigned long TimeDevice::getTimeStamp()
{
  return rtc.getLocalEpoch();
}

void TimeDevice::updateTimeFromNetwork()
{
  struct tm timeinfo;
  if (getLocalTime(&timeinfo))
  {
    rtc.setTimeStruct(timeinfo);
    isTimeSetOk = true;
  }else{
    isTimeSetOk = false;
  }
}

void TimeDevice::setAlarm(time_t alarmTime, OnAlarmHandler_t onAlarmHabdler)
{
  this->alarmTime = alarmTime;
  this->onAlarmHandler = onAlarmHabdler;
  this->isAlarmSetted = true;
}

String TimeDevice::getSetupMessage(){
  if(isTimeSetOk){
    return "Time is set ok, current system time: " + getCurrentDateTime();
  }else{
    return "Unable to obtine time from " + String(ntpServer);
  }
  
}
