#include "DisplayDevice.h"

DisplayDevice::DisplayDevice(/* args */)
{

}

DisplayDevice::~DisplayDevice()
{
}

void DisplayDevice::setLastChangedState(int lastChangedStateColor, String lastChangedState)
{
    this->lastChangedStateColor = lastChangedStateColor;
    this->lastChangedState = lastChangedState;
}

void DisplayDevice::setLastEvent(int lastEventColor, String lastEventTime)
{
    this->lastEventColor = lastEventColor;
    this->lastEventTime = lastEventTime;
}

void DisplayDevice::setup()
{
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  isDisplayOff = false;
}

void DisplayDevice::loop()
{
  //Secreen size TTGO T Display    W135 H240
  String voltage = String(batteryVoltage, 1) + "v";

  tft.loadFont(AA_FONT_MEDIUM);
  tft.setCursor(0, 0);
  tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
  tft.print(currentTime + " ");
  tft.setTextColor(TFT_DARKGREY, TFT_BLACK, true);
  tft.setCursor(180, 0);
  tft.print(voltage + " ");
  tft.unloadFont();

  tft.loadFont(AA_FONT_SMALL);
  tft.setCursor(0, 40);
  tft.setTextColor(lastChangedStateColor, TFT_BLACK, true);
  tft.print(lastChangedState + " ");
  tft.unloadFont();

  tft.setCursor(0, 70);
  tft.loadFont(AA_FONT_LARGE);
  tft.setTextColor(lastEventColor, TFT_BLACK, true);
  tft.print(lastEventTime + " ");
  tft.unloadFont();
  
  //tft.setTextSize(4);
  

  isDisplayOff = false;
}

String DisplayDevice::getSetupMessage()
{
  return "Display started";
}

void DisplayDevice::turnOffDisplay()
{
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("Press again to wake up",  tft.width() / 2, tft.height() / 2 );
  delay(6000);
  tft.writecommand(TFT_DISPOFF);
  tft.writecommand(TFT_SLPIN);
  isDisplayOff = true;
}