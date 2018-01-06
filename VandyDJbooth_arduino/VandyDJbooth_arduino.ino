/* VandyDJbooth_arduino
 *  
 * Created by: Ward Rushton '20
 * Date Created: 01/04/2018
 * 
 * Description: Bass-reactive LED code for a DJ booth
 * This setup uses an analog Low-pass filter to pass only bass signal to arduino
 * Large changes in amplitude of bass signal trigger a change of LED mode
 * 
 */

int inputPin = 1; // Pin for the music input. Only use one channel (i.e. left or right) or mono sound
int sensPin = 2; // Pin attached to sensitivity potentiometer
int ledPin = 2; 
int sensitivity;
int intensity;
int timer = 75; // Adjust to appropriate value emperically
int modeNum = 0;
int pixelCount = 150; // Change if chaining together serial data lines
bool justActivated = false; // Avoid "double sensing" the same beat

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(pixelCount, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  intensity = analogRead(inputPin);
  sensitivity = analogRead(sensPin);
  sensitivity = map(sensitivity, 0, 1023, 0, 40); // Args 2&3 are found for each pot. Args 4&5 are arbitary

  if (intensity > sensitivity & justActivated == false)
  beatEvent();

  else
  justActivated = false; // Determine if testing will require additional time delay  

  mode(modeNum);
}

void beatEvent(){ // Value changes when sound envelope surpasses threshold sensitivity
 modeNum = random(1,5); // Change this value for the number of modes created
 justActivated = true;
}

void mode(int modeNum){ // Consider "strip.SetPixelColor(color)"
  switch(modeNum){
    case 0: colorWipe(strip.Color(0, 0, 0), 50); // Off
        break;
    case 1: colorWipe(strip.Color(255, 0, 0), 50);  // Red
        break;
    case 2: colorWipe(strip.Color(0, 255, 0), 50);  // Green
        break;
    case 3: colorWipe(strip.Color(0, 0, 255), 50);  // Blue
        break;
    case 4: colorWipe(strip.Color(255, 0, 255), 50); // Magenta
       break;
    case 5: colorWipe(strip.Color(255, 255, 255), 50); // White
       break;
  }
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
