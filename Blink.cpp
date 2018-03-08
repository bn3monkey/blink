#include "Arduino.h"
#include "Blink.h"

Blink::Blink(int _pin)
{
    pinMode(_pin, OUTPUT);
    pin = _pin;
}

void Blink::on(int delay_time)
{
   digitalWrite(pin , LOW);
   delay(delay_time);
}
void Blink::off(int delay_time)
{
    digitalWrite(pin, HIGH);
    delay(delay_time);  
}
