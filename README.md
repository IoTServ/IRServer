IRServer
============

This project allows you to send infrared remote-control commands to the Arduino via the virtual serial port, to be transmitted by an IR LED on pin3.

By default, commands are terminated by an LF (line-feed) and/or CR (carriage-return), but you can specify any other delimiter with a minor change.

I have only tested this project under Windows XP, with version 1.0.1 of the Arduino IDE, on an Arduino UNO R3.

An IR LED must be connected to Arduino PWM pin 3.  You will need the IRremote library from Ken Shirriff.  For details, see http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html and https://github.com/shirriff/Arduino-IRremote

The project consists of four files:
ArduinoServer.ino
IRServer.ino
IRServerApp.ino
README

ArduinoServer.h:
This is a customized ArduinoServer that contains the getCommand() and runCommand() methods; the server splash and help screens; and a list of custom IR commands to parse.  More info on the ArduinoServer project can be found at https://github.com/WilliamNorth/ArduinoServer.

IRServer.ino:
A sample Arduino IRServer sketch containing the setup() and loop() methods.  Configure the Serial Monitor to send a 'Newline' when the [Enter] key is pressed or the 'Send' button is clicked, and set the rate to 115200 baud.

IRServerApp.h:
The IRServer application containing the IR commands (custom procedures called by the parser "ArduinoServer.h").  I have only tested the 20-bit SONY SIRC protocol, but it should work for the 12-bit and 15-bit versions as well.  More protocols and a front-end to be added soon.

README.md:
This file.
