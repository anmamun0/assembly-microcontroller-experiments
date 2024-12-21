#include <xc.h>
#include "dht11.h"  // Include DHT11 library (Make sure you have the library)

// Define configuration bits (modify as per your PIC model)
#pragma config FOSC = INTRC_NOCLKOUT  // Internal oscillator
#pragma config WDTE = OFF            // Watchdog timer off
#pragma config PWRTE = OFF           // Power-up timer off
#pragma config MCLRE = ON            // MCLR pin enabled

#define LED_PIN LATBbits.LATB0       // LED connected to PORTB pin 0
#define FAN_PIN LATBbits.LATB1       // FAN connected to PORTB pin 1

void delay_ms(int ms) {
    while(ms--) {
        __delay_ms(1);  // 1ms delay
    }
}
// DHT11 Sensor: তাপমাত্রা এবং আদ্রতা পড়া হচ্ছে।
//  MUC Sencor : Light

void main() {
    unsigned char temperature, humidity;
    unsigned int light_level; 

    TRISB = 0x00;  // Set all PORTB pins as output (for LED, FAN)
    TRISA = 0xFF;  // Set PORTA pins as input (for LDR)

    while(1) {
        // Read temperature and humidity from DHT11
        DHT11_Read(&temperature, &humidity); 

        // Read LDR value (light intensity)
        light_level = ADC_Read(0);  // Assuming LDR is connected to channel 0 of ADC
      
 

        // Control LED based on light intensity
        if(light_level < 200) {
            LED_PIN = 1;  // Turn on LED if light is low
        } else {
            LED_PIN = 0;  // Turn off LED if light is enough
        } 

        // Control FAN based on temperature
        if(temperature > 30) {
            FAN_PIN = 1;  // Turn on FAN if temperature is above 30°C
        } else {
            FAN_PIN = 0;  // Turn off FAN if temperature is below 30°C
        }

        // Control Humidifier based on humidity
        if(humidity < 40) {
            // Turn on humidifier (for example, we can set another pin for humidifier control)
            // You can add code to control a relay or an additional device here
        }

        delay_ms(1000);  // Wait for 1 second before reading the sensors again
    }
}
