

#include "ds18b20.hpp"
#include <string>
#include <ESP8266WiFi.h>

//public function 
bool ds18b20::initiate()
{
    if(pSensor == nullptr)
    {
        PRINT_ERROR(String("sensor is not initialized\n"));
    }
    if(apiKey == nullptr)
    {
        PRINT_ERROR(String("apiKey doesn't exist!\n"));
    }
    if(ssid == nullptr)
    {
        PRINT_ERROR(String("SSID doesn't exist!\n"));
    }
     if(pwd == nullptr)
    {
        PRINT_ERROR(String("PWD doesn't exist!\n"));
    }

    pSensor->begin();
    if(!connectWifi())
        return false;

    return true;
}

bool ds18b20::send(int sec)
{
    pSensor->requestTemperatures();
    float temperature = pSensor->getTempCByIndex(0);
    //PRINT_STATUS(String("temperature : ") + String(temperature));
    
    if(WiFi.status() == WL_CONNECTED)
        sendTemperature(temperature);
    else
    {
        PRINT_ERROR("Wifi DisConnection")
        connectWifi();
    }
    
    while(sec--)
        delay(1000);
}

//private method
bool ds18b20::connectWifi()
{
    PRINT_STATUS(String("Connecting to ") + String(this->ssid) + String("/") + String(this->pwd));
    WiFi.begin(this->ssid, this->pwd);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("");

    PRINT_STATUS("Connected\n");

    return true;
    
}

bool ds18b20::sendTemperature(float temp)
{
    WiFiClient client;
    String post = String(apiKey);
    post += "&field1=";
    post += String(temp);
    post += "\r\n\r\n";

    if(client.connect(server, 80))
    {
        PRINT_STATUS("WiFi Client connected");
        PRINT_STATUS(post);

        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: " + String(apiKey) + "\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(post.length());
        client.print("\n\n");
        client.print(post);
        delay(1000);
    }

    client.stop();
}
