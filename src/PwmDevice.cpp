#include "PwmDevice.h"


PwmDevice::PwmDevice(int pwmChanal, int pwmPin, int pwmLevel)
{
    this->pwmChanal     = pwmChanal;
    this->pwmPin        = pwmPin;
    this->pwmLevel      = pwmLevel;
}

PwmDevice::~PwmDevice()
{
}

void PwmDevice::setup()
{
    ledcSetup(pwmChanal, 5000, 8);
    ledcAttachPin(pwmPin, pwmChanal);
    setPwmLevel(pwmLevel);
}

void PwmDevice::loop()
{
    
}

String PwmDevice::getSetupMessage()
{
    return "PWM started";
}

void PwmDevice::setPwmLevel(int pwmLevel) {
    if(this->pwmLevel != pwmLevel){
        ledcWrite(pwmChanal, pwmLevel);
        this->pwmLevel = pwmLevel;
    }
}
