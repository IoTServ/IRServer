 /****************************************************************************
 * IRServer.ino 
 * Version 1.11 - Arduino Serial IR Server demonstration sketch.
 * For use with the Arduino (http://www.arduino.cc/), and Ken Shirriff's 
 * IRremote library (http://www.arcfn.com/).
 * 
 * Created by William North, October 16, 2012.
 * License: GPL
 *****************************************************************************
 * ArduinoServer.h is a part of the ArduinoServer project at:
 * https://github.com/WilliamNorth/ArduinoServer
 * 
 * IRServerApp.h is a part of the IRServer project at:
 * https://github.com/WilliamNorth/IRServer
 * 
 * IRremote.h is a part of the Arduino-IRremote project at:
 * https://github.com/shirriff/Arduino-IRremote
 * 
 * This is the Arduino Serial IR Server demonstration sketch "IRServer.ino".
 * Configure the Serial Monitor to send a 'Newline' when the [Enter] key is 
 * pressed or the 'Send' button is clicked, and set the rate to 115200 baud.
 * 
 * This Arduino Server Application is setup as an infrared remote control 
 * code transmitter.  An IR LED must be connected to Arduino PWM pin 3.
 ****************************************************************************/

#ifndef IRServer_ino
#define IRServer_ino

//Include Ken Shirriff's IRremote library.
#include "IRremote.h"

//Include the ArduinoServer.h module, it contains the getCommand() and runCommand() methods.
#include "ArduinoServer.h"

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

#endif  /* IRServer_ino */

