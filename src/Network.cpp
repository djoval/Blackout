#include "Network.h"

Network::Network(String ssid, String password)
{
    this->ssid = ssid;
    this->password = password;
}

Network::~Network()
{
}

void Network::setup()
{
  start();
}

void Network::loop()
{
}

void Network::start()
{
  
  setupMessage = "Connecting to " + ssid;
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  setupMessage = setupMessage + "\n\rWiFi connected, IP address: " + WiFi.localIP().toString();
}

void Network::stop(){
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  Serial.println("WiFi disconnected");
}

 String Network::getSetupMessage()
 {
    return setupMessage;
 }
 