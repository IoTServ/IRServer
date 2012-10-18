/*
 * Arduino Serial IR Server Application "IRServerApp.ino".
 * License: GPL
 * 
 * This Arduino Server Application is setup as an infrared remote control code transmitter and uses the following library:
 * IRremote
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * For details, see http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html
 * and https://github.com/shirriff/Arduino-IRremote
 * IRremote: sends IR codes via the Arduino
 * An IR LED must be connected to Arduino PWM pin 3.
 */

//Include Ken Shirriff's IRremote library.
#include <IRremote.h>

#define APP_NAME       "IRServerApp"
#define APP_VERSION    0.43
#define APP_DATE       "2012-10-16"
#define APP_COPYRIGHT  "Copyright (C) 2012 William North"

void displayAppSplash()
{
  Serial.print(APP_NAME);
  Serial.print(" version ");
  Serial.print(APP_VERSION);
  Serial.print(" of ");
  Serial.print(APP_DATE);
  Serial.print(" ");
  Serial.println(APP_COPYRIGHT);
  Serial.println("This Arduino Server app is setup as an infrared remote control code transmitter.");
  Serial.println("Tested with the 20-bit SONY SIRC protocol, but should also work for the 12-bit and 15-bit versions as well.");
  Serial.println("The IRremote library from Ken Shirriff is used in this app.");
  Serial.println("For details, see http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html");
  Serial.println("Type 'help' for instructions\n");  
}

int displayAppHelpScreen() 
{
  Serial.println("Example: sendsirc20 0xa8b47");
  Serial.println("This command sends the HEX code 0xa8b47 using the ");
  Serial.println("SONY SIRC 20-bit protocol, which is the Power-toggle button ");
  Serial.println("for a SONY BDP-S390 Blu-Ray player.");
  Serial.println("To send 12-bit or 15-bit SIRC, use the sendsirc12 and sendsirc15 commands.");
  intCommandSucceeded = true;
  return intCommandSucceeded;
}

int sendnec(String strCommand) {
}

int sendsirc(String strCommand) 
{
  IRsend irsend;

  String strCode = "";
  int intCodeLength = 0;
  char *p, *charCode;
  unsigned long ulngCode = 0;
  int intBits = 0;  

  intCommandSucceeded = 0;

  //Load the code into the strCode variable.
  //Start from the twelfth charecter (position 11).
  strCode = strCommand.substring(11);
  
  //Get the code length.
  intCodeLength = strCode.length();

  //Validate intCodeLength
  if (intCodeLength < 1) {
    intCommandSucceeded = false;
  } 
  else {
    intCommandSucceeded = true;
  }

  //Create a char array big enough to hold the code.
  char charSIRCCode[(intCodeLength + 1)];

  //Determine the number of bits to transmit.
  if (strCommand.startsWith("sendsirc12")) {
    intBits = 12;
  }
  else if (strCommand.startsWith("sendsirc15")) {
    intBits = 15;
  }  
  else if (strCommand.startsWith("sendsirc20")) {
    intBits = 20;
  }
  else {
    intBits = 0; 
    intCommandSucceeded = false;
  }

  //Convert the HEX code string in the "strCode" variable to a char array and store in "charSIRCCode".
  strCode.toCharArray(charSIRCCode, (intCodeLength + 1));

  //Convert the char array containing the HEX code into an unsigned long integer so IRremote can use it.
  ulngCode = strtol(charSIRCCode, &p, 0);

  //Validate stuff, then execute:
  if ((ulngCode < 1) || (intBits < 12) || (intBits > 20)) 
  {
    intCommandSucceeded = false;
  }
  else 
  {
    //Validation succeeded, report what is about to occur... 
    Serial.print("Sending ");  
    Serial.print(ulngCode, HEX);  
    Serial.print(" as SONY ");
    Serial.print(intBits);  
    Serial.println("-bit SIRC... ");

    //Transmit the SONY SIRC (12-bit, 15-bit or 20-bit) code using the IRremote library...
    for (int i = 0; i < 3; i++) 
    {
      irsend.sendSony(ulngCode, intBits); 
      delay(40);
    }

    //If we got this far, it must have worked!  Tell the host...
    Serial.println("Code sent!");  
    intCommandSucceeded = true;
  }

  return intCommandSucceeded;
}

int sendrc5(String strCommand) {
}
int sendrc6(String strCommand) {
}
int senddish(String strCommand) {
}
int sendsharp(String strCommand) {
}
int sendpanasonic(String strCommand) {
}
int sendjvc(String strCommand) {
}
int sendsanyo(String strCommand) {
}
int sendmitsubishi(String strCommand) {
}

