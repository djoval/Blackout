#include "SerialPort.h"

SerialPort::SerialPort(int speed)
{
    this->speed = speed;
}

SerialPort::~SerialPort()
{
}

void SerialPort::setup()
{
  Serial.begin(speed);
  Serial.println("Starting...");
}

String SerialPort::getSetupMessage()
{
  return "Serial started";
}

void SerialPort::loop()
{
}