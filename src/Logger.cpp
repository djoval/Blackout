#include "Logger.h"

Logger::Logger(TimeDevice* time)
{
    this->time = time;
}

Logger::~Logger()
{
}


void Logger::AddToLog(String message)
{
  String levelStr = "";
  Serial.println(time->getCurrentDateTime() + " : " + levelStr + " : " + message);
}
