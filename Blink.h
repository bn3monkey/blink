#ifndef __BLINK__
#define __BLINK__

class Blink
{
    public:
        Blink(int _pin);
        void on(int delay_time);
        void off(int delay_time);
    private:
        int pin;
}

#endif __BLINK__