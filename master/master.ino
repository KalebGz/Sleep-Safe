//#define ledPin 4
//
//int state = 0;
//
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
// // Controlling the LED
// if (state != 0) {
//  digitalWrite(ledPin, HIGH); // LED ON
// }
// else {
//  digitalWrite(ledPin, LOW); // LED OFF
//  
// }
//// Serial.println(state);
//
//// digitalWrite(ledPin, HIGH); // LED ON
//
// delay(3000);
//}

#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    150

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}

void loop() {
//  for(int i = 0; i < 150; i+=20)
//  {
//    leds[0+i] = CRGB(255, 0, 0);
//    FastLED.show();
//    delay(500);  
//    leds[1+i] = CRGB(0, 255, 0);
//    FastLED.show();
//    delay(500);
//    leds[i+2] = CRGB(0, 0, 255);
//    FastLED.show();
//    delay(500);
//    leds[i+5] = CRGB(150, 0, 255);
//    FastLED.show();
//    delay(500);
//    leds[i+9] = CRGB(255, 200, 20);
//    FastLED.show();
//    delay(500);
//    leds[i+14] = CRGB(85, 60, 180);
//    FastLED.show();
//    delay(500);
//    leds[i+19] = CRGB(50, 255, 20);
//    FastLED.show();
//    delay(500);
//  }

//  for(int i = 0; i < 150; i+=5)
//  {
//    leds[i] = CRGB(255, 0, 0);
//    FastLED.show();
////    delay(500);  
//    leds[i+1] = CRGB(0, 255, 0);
//    FastLED.show();
////    delay(500);
//    leds[i+2] = CRGB(0, 0, 255);
//    FastLED.show();
////    delay(500);
//    leds[i+3] = CRGB(150, 0, 255);
//    FastLED.show();
////    delay(500);
//    leds[i+4] = CRGB(255, 255, 0);
//    FastLED.show();
////    delay(500);
//
//  }

  for(int i = 0; i < 150; i++)
  {
    leds[i] = CRGB(255, 0, 0);
    FastLED.show();
  }
}
