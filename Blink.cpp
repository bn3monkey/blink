#include "Arduino.h"
#include "Blink.h"

Blink::Blink(int _pin)
{
    pinMode(pin, OUTPUT);
    _pin = pin;
}

void Blink::on(int delay)
{

}
void Blink::off(int delay)
{
    
}