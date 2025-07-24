
#include <uart.h>
#include <gpio.h>

#define CLOCK_HZ 14000000

void busy_wait_cycles(uint32_t cycles) {
    for (uint32_t i = 0; i < cycles; i++) {
        __asm__ volatile ("nop");
    }
}

void uart_tx_enable(void) {
	uint32_t gpio_sel = get_gpio_sel();
	//gpio_sel |=  0b10000000;
	gpio_sel &= ~0b00000001; // UART on GPIO0
	set_gpio_sel(gpio_sel);
}

void main(void) {

    set_gpio_sel(0xFFFFFFFF); // set all pins to GPIO mode initially
    uart_tx_enable();

    int counter = 0;
    while (1) {
        set_outputs(0x00000000);
        // XXX: this results in blinking approx once per 4 seconds
        busy_wait_cycles(CLOCK_HZ/10);
        set_outputs(0xFFFFFFFF);
        busy_wait_cycles(CLOCK_HZ/10);

        uart_printf("hello world %d\n", counter++);
    }

}
