#include "Arduino.h"
#include "Blink.h"

Blink::Blink(int _pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void Blink::on(int delay_time)
{
    digitalWrite(pin , HIGH);
    delay(delay_time);
}
void Blink::off(int delay_time)
{
    digitalWrite(pin, LOW);
    delay(delay_time);
}