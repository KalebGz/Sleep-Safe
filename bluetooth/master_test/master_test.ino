#define ledPin 4
#define onePin 9
#define twoPin 10
#define threePin 11
int state = 0;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(onePin, OUTPUT);
  pinMode(twoPin, OUTPUT);
  pinMode(threePin, OUTPUT);
  digitalWrite(ledPin, 0);
  digitalWrite(onePin, 0); //blue
  digitalWrite(twoPin, 0); //green
  digitalWrite(threePin, 0); //red
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
//    state = Serial.read(); // Reads the data from the serial port

      state = Serial.readString().toInt();

        
        if(state == 1){
          digitalWrite(onePin, HIGH);
            delay(300);
            digitalWrite(onePin, LOW);
        }else if (state == 2){
              digitalWrite(twoPin, HIGH);
            delay(300);
            digitalWrite(twoPin, LOW);
        }else if (state == 3){
          digitalWrite(threePin, HIGH);
            delay(300);
            digitalWrite(threePin, LOW);
        }else //(state == 4) or 0
        {
            digitalWrite(ledPin, HIGH);
            delay(300);
            digitalWrite(ledPin, LOW);
        }
//        
//        for(int i = 0; i < state; i++){
//        digitalWrite(ledPin, HIGH);
//        delay(300);
//        digitalWrite(ledPin, LOW);
//        delay(300);
//          }
//      delay(1000);
 }
 
// // Controlling the LED
// if (state != 0) {
//  digitalWrite(ledPin, HIGH); // LED ON
//  delay(200); // keep LED on for a little longer
// }
// else {
//  digitalWrite(ledPin, LOW); // LED OFF
//  
// }

 
// Serial.println(state);

// digitalWrite(ledPin, HIGH); // LED ON

// delay(1000);
}
