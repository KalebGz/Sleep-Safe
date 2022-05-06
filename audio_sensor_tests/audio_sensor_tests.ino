/*Adapted from https://arduino-tutorials.net/tutorial/drawing-sound-sensor-data-on-serial-plotter */
const int OUT_PIN = 7;
const int SAMPLE_TIME = 20;
unsigned long millisCurrent;
unsigned long millisLast = 0;
unsigned long millisElapsed = 0;

int sampleBufferValue = 0;

void setup() {
  Serial.begin(9600);

  
//  Fix Y Axis to 800 ticks range for first serial monitor window(for constant audio range visualations)
//  Serial.print(800); 
//  Serial.print(" ");

}

void loop() {

  millisCurrent = millis();
  millisElapsed = millisCurrent - millisLast;

  if (digitalRead(OUT_PIN) == LOW) { 
    sampleBufferValue++;
  }

  if (millisElapsed > SAMPLE_TIME) {
    Serial.println(sampleBufferValue);
//    delay(5);
    sampleBufferValue = 0;
    millisLast = millisCurrent; 
  }
}

/* KY-078 Sensor code*/ 
//// Declaration and initialization of input pins
//int Analog_In = A0; // Analog output of the sensor
//int Digital_Input = 12; // Digital output of the sensor
//  
//void setup  ( )
//{
//  pinMode (Analog_In, INPUT);
//  pinMode (Digital_Input, INPUT);
//       
//  Serial.begin (9600) ;  //  Serial output with 9600 bps
//}
//  
////  The program reads the current values of the input pins
//// and outputs it on the serial output
//void loop  ( )
//{
//  float  AnalogÂ;
//  int Digital;
//    
//  //Current values are read out, converted to the voltage value...
//  Analog =  analogRead (Analog_In)   *  (5.0 / 1023.0); 
//  Digital = digitalRead (Digital_Input) ;
//    
//  //...  and issued at this point
//  Serial.print  ("Analog voltage value:");  Serial.print (Analog,  4) ;   Serial.print  ("V, ");
//  Serial.print ("Limit value:") ;
//  
//  if  (Digital==1) 
//  {
//      Serial.println ("reached");
//  }
//  else
//  {
//      Serial.println (" not yet reached");
//  }
//  Serial.println  ( " ----------------------------------------------------------------") ;
//  delay (200) ;
//} 
