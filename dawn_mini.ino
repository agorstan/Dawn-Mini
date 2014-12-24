#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 

#define NUM_LEDS 4       // How many leds are in the strip?
#define DATA_PIN 0       // Data pin that led data will be written out over
#define SWITCH_PIN 2   // the number of the orientation switch pin
#define LED_PIN 1     // the number of the onboard LED pin

int buttonState = 0;

CRGB leds[NUM_LEDS];     // This is an array of leds.  One item for each led in your strip.


void setup() {
   // initialize the LED pin as an output:
    pinMode(LED_PIN, OUTPUT);      
    // initialize the pushbutton pin as an input:
    pinMode(SWITCH_PIN, INPUT);     
    // initialize the LED strip
    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
}

// This function runs over and over, and is where you do the magic to light
// your leds.
void loop() {
  
  // Move a single white led 
  for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
    // Turn our current led on to white, then show the leds
    leds[whiteLed] = CRGB::White;

    // Show the leds (only one of which is set to white, from above)
    FastLED.setBrightness(isOn() ? 255 : 0 );
    FastLED.show();

    // Wait a little bit
    delay(100);

    // Turn our current led back to black for the next loop around
    leds[whiteLed] = CRGB::Black;
  }
}

bool isOn(){
  return (digitalRead(SWITCH_PIN)==HIGH) ? 1 : 0;
}
