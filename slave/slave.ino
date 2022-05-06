/* Authors: Kaleb Gezahegn, Joel Binu, Bas van Dijk
 * Sampling Adapted from https://arduino-tutorials.net/tutorial/drawing-sound-sensor-data-on-serial-plotter 
*/
const int DEBUG_PIN = 4;
const int SOUND_PIN = 7;
const int SAMPLE_RATE = 20; // 20ms
const int AVERAGE_RATE = 2000; //  2seconds

unsigned long current_ms;
unsigned long last_ms;
unsigned long elapsed_ms;

unsigned long last_avg_ms;
unsigned long elapsed_avg_ms;

const int BUTTON_PIN = 2;     // the number of the pushbutton pin
const int BUTTON_LED_PIN =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

//Sound Levels 
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

int button_state = 6; // hard coding button state value transmitted to debug
int sound_state = 0;

int max_sound_state = 0;

int avg_sample_count = 0;

int sample_buffer = 0; // value that is incremented every 10ms based on sound sensor data

int average_buffer = 0; // value representig ratio of sounds ticks per 2 seconds
int average_ratio = 0;

void setup() {
  Serial.begin(9600);
    
  pinMode(DEBUG_PIN, OUTPUT);
  digitalWrite(DEBUG_PIN, LOW);

  
//  Fix Y Axis to 800 ticks range for first serial monitor window(for  sample buffer range visualations,)
//  Serial.print(800); 
//  Serial.print(" ");

    // initialize the LED pin as an output:
  pinMode(BUTTON_LED_PIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_PIN, INPUT);

}

void loop() {
  current_ms = millis();
  elapsed_ms = current_ms - last_ms;
  elapsed_avg_ms = current_ms - last_avg_ms;

  //  USER_AWAKE Button sequence 
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(BUTTON_LED_PIN, HIGH);
    max_sound_state = 6;
//    Serial.write(button_state);
//    delay(300); // simple debouncing

    // reset samples because of the interupt
    avg_sample_count = 0;
    sample_buffer = 0; 
    average_buffer = 0;
    average_ratio = 0;
    last_avg_ms = current_ms;
    last_ms = current_ms;
  } else {
    // turn LED off:
    digitalWrite(BUTTON_LED_PIN, LOW);
  }


  if (digitalRead(SOUND_PIN) == 0) {
    sample_buffer+=1;
    
  }


  if (elapsed_ms > SAMPLE_RATE) {
//    Serial.println(sample_buffer); //Debugging tip: best visualized using the Serial Plotter
      if(sample_buffer == 0)
      {
        sound_state = SILENT;
      }else if(sample_buffer <= 150)
      {
        sound_state = QUIET;
        
      }else if(sample_buffer <= 400)
      {
       sound_state = AUDIBLE;
        
      }else{
       
        sound_state = LOUD;
      }
      
      if(sound_state != SILENT){
        avg_sample_count+=1;
      }
      average_buffer += sound_state;

      if(sound_state > max_sound_state){
        max_sound_state = sound_state;
      }
      
//      Serial.println(sample_buffer);
//      delay(300); // delays > sampling rate significantly degrade sampling data
    sample_buffer = 0;
    last_ms = current_ms; 
//    max_sound_state = 0;
  }

// Calculate sound level
  if (elapsed_avg_ms > AVERAGE_RATE) {
    Serial.println(max_sound_state);
    Serial.write(max_sound_state);
    
//    Reset 
    max_sound_state = 0;
    avg_sample_count = 0;
    average_buffer = 0;
    last_avg_ms = current_ms; 
  }

  
//// Calculate sound level
//  if (elapsed_avg_ms > AVERAGE_RATE) {
//    average_ratio = average_buffer/avg_sample_count;
//
// 
//    Serial.print("average_buffer "); Serial.println(average_buffer);
//    Serial.print("avg_sample_count "); Serial.println(avg_sample_count);
//    Serial.print("average_ratio "); Serial.println(average_ratio);
//    delay(1000);
////    if(average_ratio == 0)
////    {
////      Serial.write(SILENT);
////    }else if(average_ratio <= 30)
////    {
////      Serial.write(QUIET);
////    }else if(average_ratio <= 60)
////    {
////      Serial.write(AUDIBLE);
////    }else{
////      Serial.write(LOUD);
////    }
////
////      Serial.write(sound_state);
////    Serial.println(sound_state);
////    for(int i = 0; i < sound_state; i++)
////    {
////      digitalWrite(DEBUG_PIN, HIGH); 
////      delay(200);
////      digitalWrite(DEBUG_PIN, LOW); 
////      delay(200);
////    }
//    
////    Reset 
//    avg_sample_count = 0;
//    average_buffer = 0;
//    last_avg_ms = current_ms; 
//  }
  

}
