
#include <uart.h>
#include <gpio.h>

#define CLOCK_HZ 14000000

void busy_wait_cycles(uint32_t cycles) {
    for (uint32_t i = 0; i < cycles; i++) {
        __asm__ volatile ("nop");
    }
}

void main(void) {

    // set all pins to GPIO mode
    // TODO: enable UART pins
    set_gpio_sel(0xFFFFFFFF);

    while (1) {
        set_outputs(0x00000000);
        // XXX: this results in blinking approx once per 4 seconds
        busy_wait_cycles(CLOCK_HZ/20);
        set_outputs(0xFFFFFFFF);
        busy_wait_cycles(CLOCK_HZ/20);
    }

    //uart_printf("hello world %d", 111);
}
