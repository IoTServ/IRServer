/*
 ArduinoServer.h version 0.30 - Arduino Custom Command Server (via the virtual serial port).
 For use with the Arduino (http://www.arduino.cc/)
 
 Created by William North, October 14, 2012.
 License: GPL
 
 ArduinoServer.h is a part of the ArduinoServer project at:
 https://github.com/WilliamNorth/ArduinoServer
 
 IRServerApp.h is a part of the IRServer project at:
 https://github.com/WilliamNorth/IRServer
 
 IRremote.h is a part of the Arduino-IRremote project at:
 https://github.com/shirriff/Arduino-IRremote
 
 * This is the ArduinoServer module "ArduinoServer.h".
 * Configure the Serial Monitor to send a 'Newline' when the [Enter] key is pressed 
 * or the 'Send' button is clicked, and set the rate to 115200 baud.
 * 
 * This server is setup to run the IRServer application "IRServerApp.h".
 */

#ifndef ArduinoServer_h
#define ArduinoServer_h
#include "Arduino.h"

//Include the IRServerApp module
#include "IRServerApp.h"

#define SERVER_NAME       "Arduino Custom Command Server"
#define SERVER_VERSION    0.30
#define SERVER_DATE       "2012-10-27"
#define SERVER_COPYRIGHT  "Copyright (C) 2012 My Mother"

void displayServerSplash()
{
  Serial.println(SERVER_NAME);
  Serial.print("Version ");
  Serial.print(SERVER_VERSION);
  Serial.print(" of ");
  Serial.println(SERVER_DATE);
  Serial.println(SERVER_COPYRIGHT); 
  Serial.print("\n");
}

int displayServerHelpScreen() 
{
  int intCommandSucceeded;

  Serial.println("Type a command (case insensitive), then press [Enter].");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int displayAllHelpScreens() 
{
  int intCommandSucceeded;

  displayServerHelpScreen(); 
  displayAppHelpScreen(); 
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

String getCommand()
{
  int intReadByte = 0;
  String strReadData = "";

  //As long as the byte just read is not a line-feed or CR...
  while ((intReadByte != 10) && (intReadByte != 13))
  {
    //...and the serial port buffer has data, read a byte from it.
    if (Serial.available()) 
    {
      intReadByte = Serial.read(); 

      //If the byte just read is not a line-feed or CR...
      if ((intReadByte != 10) && (intReadByte != 13))
      {
        //...then add it to the string.
        strReadData.concat(char(intReadByte)); 
      }
    }
  }

  //Return the string
  return strReadData;
}

int runCommand(String strCommand)
{
  int intCommandSucceeded;

  Serial.print("Executing command: ");
  Serial.println(strCommand);

  if (strCommand.equals("help")) {
    intCommandSucceeded = displayAllHelpScreens();
  }
  else if (strCommand.startsWith("sendnec")) {
    intCommandSucceeded = sendIRnec(strCommand);
  }
  else if (strCommand.startsWith("sendsirc")) {
    intCommandSucceeded = sendIRsirc(strCommand);
  }
  else if (strCommand.startsWith("sendrc5")) {
    intCommandSucceeded = sendIRrc5(strCommand);
  }
  else if (strCommand.startsWith("sendrc6")) {
    intCommandSucceeded = sendIRrc6(strCommand);
  }
  else if (strCommand.startsWith("senddish")) {
    intCommandSucceeded = sendIRdish(strCommand);
  }
  else if (strCommand.startsWith("sendsharp")) {
    intCommandSucceeded = sendIRsharp(strCommand);
  }
  else if (strCommand.startsWith("sendpanasonic")) {
    intCommandSucceeded = sendIRpanasonic(strCommand);
  }
  else if (strCommand.startsWith("sendjvc")) {
    intCommandSucceeded = sendIRjvc(strCommand);
  }
  else if (strCommand.startsWith("sendsanyo")) {
    intCommandSucceeded = sendIRsanyo(strCommand);
  }
  else if (strCommand.startsWith("sendmitsubishi")) {
    intCommandSucceeded = sendIRmitsubishi(strCommand);
  }
  else {
    intCommandSucceeded = false;
  }

  //Return the success or failure of this command.
  return intCommandSucceeded;
}

#endif




