#ifndef __NETWORK_H__
#define __NETWORK_H__

#include "AbstractDevice.h"
#include "WiFi.h"

class Network : public AbstractDevice
{
private:
    String ssid;
    String password; 
    String setupMessage;  
public:
    Network(String ssid, String password);
    ~Network();
    void setup();
    void loop();
    String getSetupMessage();
    void start();
    void stop();
};

#endif // __NETWORK_H__

