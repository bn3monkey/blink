#include <OneWire.h>
#include <DallasTemperature.h>

#define PRINT_ERROR(msg) Serial.println(msg);
#define PRINT_STATUS(msg) Serial.println(msg);

//#define USE_THINGSPEAK
#define USE_IFTTT

class ds18b20
{
    public:
    //Constructor
    ds18b20(int bus,const char* _apiKey = nullptr, const char* _ssid = nullptr, const char* _pwd = nullptr)
    {
        pWire = new OneWire(bus);
        pSensor = new DallasTemperature(pWire);
        apiKey = _apiKey;
        ssid = _ssid;
       pwd = _pwd;

    }
    
    //Destoryer
    ~ds18b20()
    {
        if(pWire != nullptr)
            delete pWire;
        if(pSensor != nullptr)
            delete pSensor;
    }

    //initiate Sensor and Connect Wifi
    // out : if success, return true. else, return false.
    bool initiate();
    // send temperature data to thingspeak server every 'sec' second
    bool send(int sec);

    private:
        //Server
        const char* server = "api.thingspeak.com";
        const char* apiKey;

        //Wifi
        const char* ssid;
        const char* pwd;

        OneWire* pWire;
        DallasTemperature* pSensor;

        //Connecting Wifi
        bool connectWifi();
        //Send Temperature
        bool sendTemperature(float temp);
};
