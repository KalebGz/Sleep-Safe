//#define ledPin 7
//int prev_state = 0;
//
//int state;
//
//void setup() {
//  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, LOW);
//  Serial.begin(9600); // Default communication rate of the Bluetooth module
//}
//
//void loop() {
// if(Serial.available() > 0){ // Checks whether data is comming from the serial port
//    state = Serial.read(); // Reads the data from the serial port
// }
//
// if (prev_state == 0) {
//   Serial.write(1); // Sends '1' to the master to turn on LED
//   digitalWrite(ledPin, HIGH);
//   prev_state = 1;
// }
// else {
//   Serial.write(0);
//   digitalWrite(ledPin, LOW);
//   prev_state = 0;
// }  
//
// delay(1000); // delay for 10 seconds
//}

// Declaration and initialization of input pins
int Analog_In = A0; // Analog output of the sensor
int Digital_Input = 12; // Digital output of the sensor
  
void setup  ( )
{
  pinMode (Analog_In, INPUT);
  pinMode (Digital_Input, INPUT);
       
  Serial.begin (9600) ;  //  Serial output with 9600 bps
}
  
//  The program reads the current values of the input pins
// and outputs it on the serial output
void loop  ( )
{
  float  AnalogÂ;
  int Digital;
    
  //Current values are read out, converted to the voltage value...
  Analog =  analogRead (Analog_In)   *  (5.0 / 1023.0); 
  Digital = digitalRead (Digital_Input) ;
    
  //...  and issued at this point
  Serial.print  ("Analog voltage value:");  Serial.print (Analog,  4) ;   Serial.print  ("V, ");
  Serial.print ("Limit value:") ;
  
  if  (Digital==1) 
  {
      Serial.println ("reached");
  }
  else
  {
      Serial.println (" not yet reached");
  }
  Serial.println  ( " ----------------------------------------------------------------") ;
  delay (200) ;
} 
