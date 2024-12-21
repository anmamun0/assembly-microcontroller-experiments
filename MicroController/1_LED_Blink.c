#include<util/delay.h>
#include <avr/io.h>


int main()
{
    DDRB = 0x01; // Data Direction Register for Port PB0 = Output, বাকিগুলো Input
    PORTB = 0x02; // Port Output Register for PortPB1 = Pull-up Enabled, PB0 = Low (LED OFF)

    while(1):
    {
        // if((PINB & 0X02) == 0){}
        // Toggle PB0 (LED blink)
        PORTB ^= 0x01;
        _delay_ms(500);
    }

    return 0;
}