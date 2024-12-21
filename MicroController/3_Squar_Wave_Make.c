#include <xc.h>

void main() 
{
  
    TRISB.F0 = 0;  // Set PORTB pin 0 as output
    while(1) 
    {
        PORTB.F0 = 1;  // Set PORTB pin 0 high (Turn on the square wave)
        delay_ms(1);   // Delay for 1ms (High phase)
        PORTB.F0 = 0;  // Set PORTB pin 0 low (Turn off the square wave)
        delay_ms(1);   // Delay for 1ms (Low phase)
    }
}