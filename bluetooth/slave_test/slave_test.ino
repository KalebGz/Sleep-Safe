#define ledPin 4
int prev_state = 0;

int state;

 int SOUND_LEVEL = 1;
//#define SOUND_LEVEL 4
void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
// if(Serial.available() > 0){ // Checks whether data is comming from the serial port
//    state = Serial.read(); // Reads the data from the serial port
//
// }

  
SOUND_LEVEL++;
if (SOUND_LEVEL > 4) SOUND_LEVEL = 0;

 if (prev_state == 0) {
   Serial.write(SOUND_LEVEL); // Sends '1' to the master to turn on LED
   digitalWrite(ledPin, HIGH);
   delay(1000);
   prev_state = SOUND_LEVEL;
 }
 else {
   Serial.write(0);
   digitalWrite(ledPin, LOW);
   prev_state = 0;
   delay(6000); // delay for 6 seconds
 }  

 
}
