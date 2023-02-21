Atmega32 Drivers Library

This repository contains a collection of drivers for various AVR microcontroller peripherals, including:

    Digital Input/Output (DIO)
    Analog-to-Digital Converter (ADC)
    Liquid Crystal Display (LCD)
    Keypad
    EEPROM 
    Timer/Counter 0
    Pulse Width Modulation (PWM)
    Universal synchronous Asynchronous Receiver-Transmitter (USART)
    Serial Peripheral Interface (SPI)
    Inter-Integrated Circuit (I2C)
   

Requirements

    AVR microcontroller
    avr/io.h header file
    avr/delay.h header file
    stdtypes.h and macros.h header files (included in the library)

   

To use this library, you will need:

    A computer with a C compiler, such as GCC
    A microcontroller that supports the AVR instruction set or any Emulation software that supports AVR microcontrollers.
    A way to transfer the compiled code to your microcontroller, such as a programmer

Using the Library

    To use the library in your project, you will need to include the appropriate header files in your code and link the compiled object files.

    For example, to use the DIO driver, you would include the following line in your code:

    #include "dio.h"

    You would then need to link the compiled DIO object file to your project.

    kindly notice It is imperative that you edit the configuration files before using the software. Failure to do so may result in unexpected behavior and incorrect results.
   
-Each driver has its own header file and implementation file, with detailed documentation included in the header file.

-This repository includes additional documents that you may find helpful, and I will be continuously updating it.

If you encounter any difficulties in comprehending this, have any other questions or need further assistance, please do not hesitate to reach me out. <uosefelbandrawy@gmail.com>.
