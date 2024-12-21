#include <xc.h>

// Define the configuration bits (this depends on your PIC model)
#pragma config FOSC = INTRC_NOCLKOUT  // Internal oscillator
#pragma config WDTE = OFF            // Watchdog timer off
#pragma config PWRTE = OFF           // Power-up timer off
#pragma config MCLRE = ON            // MCLR pin enabled

// Delay function for 1ms
void delay_ms(int ms) {
    while(ms--) {
        __delay_ms(1);  // 1ms delay
    }
}

void main() {
    TRISB.F0 = 0;  // Set PORTB pin 0 as output for LED
    TRISB.F1 = 0;  // Set PORTB pin 1 as output for Motor

    while(1) {
        // Turn on the LED and Motor
        PORTB.F0 = 1;   // LED ON
        PORTB.F1 = 1;   // Motor ON
        delay_ms(1000); // Wait for 1 second

        // Turn off the LED and Motor
        PORTB.F0 = 0;   // LED OFF
        PORTB.F1 = 0;   // Motor OFF
        delay_ms(1000); // Wait for 1 second
    }
}
