#include <pic.h>

int count = 0;

void main(void)
{
    // Timer0 Initialization
    TMR0 = 0;   // Initialize Timer0
    T0CS = 0;   // Select Internal Clock
    PSA = 0;    // Prescaler Assigned to Timer0
    PS0 = 1;    // Prescaler bit 0 (1:256)
    PS1 = 1;    // Prescaler bit 1
    PS2 = 1;    // Prescaler bit 2

    // Configure Output Pin
    TRISB0 = 0; // Set RB0 as Output (LED)
    RB0 = 0;    // Turn OFF LED initially

    // Main loop
    while (1) {
        while (!T0IF);  // Wait for Timer Overflow
        T0IF = 0;       // Clear Timer Overflow Flag
        count++;        // Increment Count

        if (Count == 15) {  // When Count reaches 15 (Approx. 1 sec)
            RB0 = ~RB0;     // Toggle LED
            count = 0;      // Reset Count
        }
    }
}