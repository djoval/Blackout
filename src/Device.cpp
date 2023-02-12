#include "Device.h"

Device::Device()
{
}
Device::~Device()
{
}


void Device::setup()
{
    serial.setup();
    Serial.println(serial.getSetupMessage());
    battery.setup();
    Serial.println(battery.getSetupMessage());
    buzzer.setup();
    Serial.println(buzzer.getSetupMessage());
    pwm.setup();
    Serial.println(pwm.getSetupMessage());
    display.setup();
    Serial.println(display.getSetupMessage());
    network.setup();
    Serial.println(network.getSetupMessage());
    time.setup();
    Serial.println(time.getSetupMessage());

    lastPowerUp = time.getTimeStamp();
    lastPowerDown = lastPowerUp;

    logger.AddToLog(getSetupMessage());
    if(!time.isQuetTime()){
      buzzer.beep(100);
    }
    
}

void Device::loop()
{
  static uint64_t timeStamp = 0;
  if (millis() - timeStamp > 1000)
  {
    timeStamp = millis();
    
    checkPowerState();
    updateDisplayData();
    updateDateTime();
    setDisplayBrightness();


    serial.loop();
    battery.loop();
    pwm.loop();
    display.loop();
    network.loop();
    time.loop();

  };

  buzzer.loop();
}

void Device::updateDisplayData()
{
    if(battery.isBatteryCharhing()){
        String strTime = time.secToTime(lastPowerUp + POWER_ON_HOURS * 3600 - time.getTimeStamp());
        int color = TFT_DARKGREEN;
        display.setLastEvent(color, strTime);
    }else{
        String strTime = time.secToTime(lastPowerDown + POWER_OFF_HOURS * 3600 - time.getTimeStamp());
        int color = TFT_RED;
        display.setLastEvent(color, strTime);
    }
    display.setBatteryVoltage(battery.getBatteryVoltage());
    display.setCurrentTime(time.getCurrentTime());
}


Device *pointerToThisClass;

static void onAlarmHandler(void) { // define global handler
  pointerToThisClass->beforePowerDown(); // calls class member handler
}


void Device::onPowerUp()
{
  String state = "POW  ON " + time.getCurrentDateTime();  
  display.setLastChangedState(TFT_DARKGREEN, state);
  lastPowerUp = time.getTimeStamp(); // 0 is current
  //lastPowerOff = time.secToTime(lastPowerUp - lastPowerDown);
    if(!time.isQuetTime()){
      buzzer.beep(100);
    }

    time_t alarmTime = lastPowerUp + POWER_ON_HOURS * 3600 - BEEP_BEFORE_POWER_OFF_MIN * 60;
    pointerToThisClass = this;
    time.setAlarm(alarmTime, onAlarmHandler);
}



void Device::beforePowerDown(void)
{
  if(!time.isQuetTime()){
    buzzer.beep(1000);
  }
}


void Device::onPowerDown()
{
  String state = "POW OFF " + time.getCurrentDateTime();  
  display.setLastChangedState(TFT_RED, state);
  lastPowerDown = time.getTimeStamp(); // 0 is current
  if(!time.isQuetTime()){
    buzzer.beep(100);
  }
}

void Device::checkPowerState()
{
  if (battery.isBatteryCharhing() && !lastPowerState)
  { //  LOW-HIGH
    lastPowerState = true;
    onPowerUp();
  }
  if (!battery.isBatteryCharhing() && lastPowerState)
  { // HIGH-LOW
    lastPowerState = false;
    onPowerDown();
  }
}

void Device::setDisplayBrightness()
{
    if(time.isQuetTime()){
      pwm.setPwmLevel(LOW_BRIGHTNES_LEVEL);
    }else{
      pwm.setPwmLevel(HIGH_BRIGHTNES_LEVEL);
    };
}

void Device::updateDateTime()
{
  long curTime = lastPowerUp + 300ul - time.getTimeStamp();
  if (curTime == 0)
  {
    network.start();
    time.updateTimeFromNetwork();
    network.stop();
  }

}

String Device::getSetupMessage()
{
  return "Sytem started";
}

void Device::espDelay(int ms)
{
  esp_sleep_enable_timer_wakeup(ms * 1000);
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
  esp_light_sleep_start();
}

