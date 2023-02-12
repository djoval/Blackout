#include "BuzzerDevice.h"

BuzzerDevice::BuzzerDevice(int buzzerPin)
{
    this->buzzerPin = buzzerPin;
}

BuzzerDevice::~BuzzerDevice()
{
}

void BuzzerDevice::setup()
{
   pinMode(buzzerPin, OUTPUT); 
}

void BuzzerDevice::loop()
{
  if (millis() - timeStarted > ms)
  {
    digitalWrite(buzzerPin, LOW);
  };
}

void BuzzerDevice::beep(int ms)
{
    this->ms = ms;
    this->timeStarted = millis();
    digitalWrite(buzzerPin, HIGH);
}

String BuzzerDevice::getSetupMessage()
{
    return "Buzzer started";
}
