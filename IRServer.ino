/*
 * Arduino Serial IR Server demonstration sketch "IRServer.ino".
 * Version 1.00 Oct 16 2012 - by William North
 * License: GPL
 * 
 * This Arduino Server Application is setup as an infrared remote control code transmitter and uses the following library:
 * IRremote
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * For details, see http://arcfn.com/2009/08/multi-protocol-infrared-remote-library.htm
 * IRremote: sends IR codes via the Arduino
 * An IR LED must be connected to Arduino PWM pin 3.
 */

//Include the ArduinoServer.ino sketch, it contains the getCommand() and runCommand() methods.
#include <ArduinoServer.ino>

//Include the IRServerApp.ino sketch, it contains the methods used to send IR codes for vaious protocols.
#include <IRServerApp.ino>

String strCommand;
int intCommandSucceeded;

void setup()
{  
  //Serial.begin(9600);  
  Serial.begin(115200);

  //Display splash-screens.
  displayServerSplash();
  displayAppSplash();

  //Notify the host that the server is online and ready.
  Serial.println("Waiting for commands...\n");  
}

void loop () 
{    
  strCommand = "";
  intCommandSucceeded = 0;

  //Get the next command from the serial port buffer.
  strCommand = getCommand();

  //Clean, then execute the command.
  strCommand.toLowerCase();
  intCommandSucceeded = runCommand(strCommand);

  //Report the success of the command's execution.
  if (intCommandSucceeded)
  {
    Serial.println("Command successful\n");
  }
  else
  {
    Serial.println("Command not recognized or unsuccessful\n");
  }
}


