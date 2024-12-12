# displays

## Overview
* This is using Arduino for building a quick prototype to create a display driver for the SSD1331.
* Since I am designing a generic display driver, I am implementing one for SSD1331 to get a good idea \
on approaching for a generic interface for display drivers.
* Going to be making a few drivers for STM32F4, and the Arduino boards.
* Developing display drivers to the SSD1331 and the


## Goal
* Developing SSD1331 Display for Arduino, and then will take a look into developing the display \
    foir STM32F429I-DISC

## Serial Communicatoin Review
Overview examples --- use SPI when speed is crucial, I2C when you need to connect multiple devices over short distances, UART for simple point-to-point communication, and CAN for automotive applications requiring robustness and reliability.

UART (Universal Asynchronous Receiver/Transmitter):

    Data Handling: UART transmits data asynchronously using two wires (TX for transmission, RX for reception). It sends data in serial form, one bit at a time, without a clock signal.
    Purpose: Designed for point-to-point, low-speed, simple serial communication.
    Use Cases: Commonly used for communication between a computer and its peripherals, like a mouse or keyboard.
    Visual Example: Imagine sending a letter where each word is sent one after another through a single mail slot.
    Board Support: Look for TX and RX pin labels on the board.

SPI (Serial Peripheral Interface):

    Data Handling: SPI operates in full-duplex mode using four wires (MISO, MOSI, SCK, SS) allowing simultaneous data transmission and reception.
    Purpose: Suited for high-speed data transfer in short distances.
    Use Cases: Often used in SD cards and display modules.
    Visual Example: Picture a two-way road where cars (data) can travel in both directions at the same time.
    Board Support: Check for pins labeled MISO, MOSI, SCK, and SS.

I2C (Inter-Integrated Circuit):

    Data Handling: I2C uses two wires (SDA for data, SCL for clock) and supports multiple masters and slaves in a shared bus system.
    Purpose: Aimed at communication between chips on a PCB.
    Use Cases: Used in RTC modules and temperature sensors.
    Visual Example: Think of a train system with multiple trains (masters) and stations (slaves) along the same track.
    Board Support: Identify SDA and SCL pins on the board.

CAN (Controller Area Network):

    Data Handling: CAN sends messages with identifiers that dictate message priority in a multi-master system.
    Purpose: Developed for robust, reliable communication in automotive environments.
    Use Cases: dominant in-vehicle networks for connecting ECUs.
    Visual Example: Imagine a postal service where packages are sorted and delivered based on priority tags.
    Board Support: Usually integrated into automotive-focused microcontrollers or available as separate CAN controller modules.