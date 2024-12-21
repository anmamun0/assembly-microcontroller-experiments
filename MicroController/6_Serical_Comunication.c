#include<xc.h>

void main()
{
    char received_data;

    // Set up UART
    init_uart();

    // Main loop
    while(1) {
        // Send a message to the PC
        uart_write('H');
        uart_write('e');
        uart_write('l');
        uart_write('l');
        uart_write('o');
        uart_write('\r');
        uart_write('\n');

        // Read a byte of data from the PC
        received_data = uart_read();
        
        // Echo the received data back to the PC
        uart_write(received_data);

        __delay_ms(1000);  // Delay for 1 second
    }
}