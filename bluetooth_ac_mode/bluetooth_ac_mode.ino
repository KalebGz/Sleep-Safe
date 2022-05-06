/*
AUTHOR: Kaleb Gezahegn, Joel Binu Hazim Bitar (techbitar)
DATE: Aug 29, 2013, May 04 2022
Notes: 
- Make sure tr and rx pins are flipped
- When powering on, hold onto hc-05 button next to EN pin
  - Verify red led on hc-05 is flashing every 2 seconds to check if it's in AC mode
*/


#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX

void setup()
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
}

void loop()
{

/* AT Commands
 *  General
 *    AT: Return 'OK' if communicating with module
 *    AT-UART?: Return configured baud rate
 *    AT-Role?: 0-Slave, 1-Master
      //    TODO: Check if the role of slave and master can be reversed to have multiple slaves
 *  Slave 
 *    AT-ADDR?: Return bluetooth Address
 *  Master
 *    AT+CMODE=0 : Set connection mode to a fixed address
 *    AT+BIND={slave bluetooth address} : Pair master to salve
 */

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
