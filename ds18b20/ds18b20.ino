#include "ds18b20.hpp"

#define ONE_WIRE_BUS D3

ds18b20 ds(D3,
        "HW60308QQNWEIL5S",
        "SK_WiFiGIGA6D64",
        "1701004268");


void setup(void)
{
    Serial.begin(115200);
    ds.initiate();
}

void loop(void)
{
    ds.send(10);
}
