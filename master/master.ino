#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    150
CRGB leds[NUM_LEDS];

//Sound Levels 
//const int SILENT =  0;
//#define SILENT 0
//#define QUIET 1
//#define AUDIBLE 2
//#define LOUD 3
//#define USER_AWAKE 4

const int SILENT = 0;
const int QUIET = 1;
const int AUDIBLE = 2;
const int LOUD = 3;
const int USER_AWAKE = 4;

int sound_state = 0; // var represeting current sound level  
int prev_state = -1;

const int DEBUG_PIN = 4;

void setup() {
  Serial.begin(9600); // default baud rate of HC-05
  
  pinMode(DEBUG_PIN, OUTPUT);
  digitalWrite(DEBUG_PIN, LOW);
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  

//  Serial.print("SILENT: ");
//  Serial.println(SILENT);
}

void loop() {

    // read data from serial port
   if(Serial.available() > 0){ 
      sound_state = Serial.read(); 
//      sound_state = Serial.readString().toInt();

//      if(sound_state == USER_AWAKE){
//        Serial.println("BUTTON Press Transmitted");
//        digitalWrite(DEBUG_PIN, HIGH);
//        delay(400);
//        digitalWrite(DEBUG_PIN, LOW);
//      }


      for(int i = 0; i < sound_state; i++){
        digitalWrite(DEBUG_PIN, HIGH);
        delay(1000);
        digitalWrite(DEBUG_PIN, LOW);
      }
//      sound_state = USER_AWAKE;
//      Serial.println("DATA FOUND");
//      Serial.println(sound_state);
   }

//        Serial.println(sound_state);
//        Serial.println(USER_AWAKE);


      // Flash all LEDS red, Priority Check
    if(sound_state == USER_AWAKE)
    {
      for(int i = 0; i < 2; i+=1)
      {
          // flash on and off
          for(int i = 0; i < 150; i+=1)
          {
            
            leds[i] = CRGB(255, 0, 0);
            FastLED.show();
          }
          for(int i = 150; i >= 0; i-=1)
          {
            leds[i] = CRGB(0, 0, 0);
            FastLED.show();
          }
      }
      sound_state = SILENT; // reset 
    }
    
  
  // Update Led's when state changes
  if(sound_state != prev_state )// || sound_state >= AUDIBLE )
  {
    
    
      // Turn all LEDS off
      if(sound_state == SILENT)
      { 
        for(int i = 0; i < 150; i+=1)
        {
          leds[i] = CRGB(0, 0, 0);
          FastLED.show();
          //delay(100);  
        }
      }
      
      
      // Keep Left LEDS on at Green
      if(sound_state == QUIET)
      {
        for(int i = 0; i < 60; i+=1)
        {
          leds[i] = CRGB(0, 255, 0);
          FastLED.show();  
          
        }
        delay(1000);
      }
      
      // Flash Middle Edge with Blue Leds
      if(sound_state == AUDIBLE)
      {
        for(int i = 0; i < 30; i+=1)
        {
          // flash on and off
          leds[60+i] = CRGB(0, 0, 0); 
//          delay(200);
          leds[60+i] = CRGB(0, 0, 255);
          FastLED.show();
        }
      }
      
      // Flash Right Edge with RED Leds at a faster rate
      if(sound_state == LOUD)
      {
        for(int i = 0; i < 60; i+=1)
        {
          // flash on and off
          leds[90+i] = CRGB(0, 0, 0); 
//          delay(200);
          leds[90+i] = CRGB(255, 0, 0);
          FastLED.show();
        }
      }

  }

  prev_state = sound_state;

}
