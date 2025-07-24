
# MicroPython code for running a program
#
# The needed modules are found in tinyQV/pico-ice/micropython

from machine import UART, Pin
from run_tinyqv import execute
import time

def read_uart():

    rx_pin = Pin(17)
    uart = UART(0, baudrate=115200, tx=Pin(16), rx=rx_pin)
    time.sleep(0.001)

    print('Listening on UART RX', rx_pin)
    while True:
        data = uart.read()
        if data is not None:
            for d in data:
                if d > 0 and d <= 127:
                    print(chr(d), end="")


execute('example.bin')
read_uart()
