#include "BatteryDevice.h"
BatteryDevice::BatteryDevice(int voltagePin, int enablePin)
{
    this->vref = 1100;
    this->batteryVoltage = 0;
    this->voltagePin = voltagePin;
    this->enablePin = enablePin;
}

BatteryDevice::~BatteryDevice()
{
}


void BatteryDevice::setup()
{
/*
  ADC_EN is the ADC detection enable port
  If the USB port is used for power supply, it is turned on by default.
  If it is powered by battery, it needs to be set to high level
  */
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);
  pinMode(voltagePin, INPUT);
}

void BatteryDevice::loop()
{

}  

String BatteryDevice::getSetupMessage()
{
  updateVoltage();
  String externalPower = "External power off";
  if(isBatteryCharhing()){
    externalPower = "External power on";
  }
  return "Battery started. voltage is " + String(batteryVoltage) + " " + externalPower;
}

bool BatteryDevice::isBatteryCharhing()
{
  updateVoltage();
  return batteryVoltage > 4.5;
}


float BatteryDevice::getBatteryVoltage()
{
  	updateVoltage();
    return this->batteryVoltage;
}

void BatteryDevice::updateVoltage()
{
  uint16_t v = analogRead(voltagePin);
  batteryVoltage = ((float)v / 4095.0) * 2.0 * 3.3 * (vref / 1000.0);
}
