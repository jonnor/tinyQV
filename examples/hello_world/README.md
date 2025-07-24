
# TinyQV hello world in C


## Prerequisites

You will need the [tinyQV-sdk](https://github.com/MichaelBell/tinyQV-sdk),
including the custom GCC toolchain.

TinyQV must be running on pico-ice (ICE40),
with MicroPython set up on the RP2040.

You must have the run_tinyqv.py and flash_prog.py modules on the RP2040.

You need the `mpremote` tool for communicating with MicroPython.

## Building

To build the program.

```
make RISCV_TOOLCHAIN=../../toolchain/riscv/ TINYQV_SDK=../../tinyQV-sdk
```

Adjust the paths if the pieces are elsewhere.

## Running

To build program and run on the tinyQV.

```
make run RISCV_TOOLCHAIN=../../toolchain/riscv/ TINYQV_SDK=../../tinyQV-sdk
```

The output should be something like.

```
mpremote cp example.bin :
cp example.bin :
mpremote run run_program.py
ff ef 17 
*****.--.
Program done
Verify done
6f 00 00 05 6f 00 80 06 24 f0 73 25 20 34 93 74 
........................................

```

The program should write "Hello World" on UART every few seconds, and toggle the GPIO pins.
The UART is on GPIO0, with baudrate 115200.

