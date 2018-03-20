#include "ds18b20.hpp"

#define ONE_WIRE_BUS D3

ds18b20 ds(D3,
        "HW60308QQNWEIL5S",
        "KT_WLAN_B7C5",
        "0000004c57");


void setup(void)
{
    Serial.begin(115200);
    ds.initiate();
}

void loop(void)
{
    ds.send(10);
}
