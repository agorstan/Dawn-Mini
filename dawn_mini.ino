#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// Move a white dot along the strip of leds.  This program simply shows how to configure the leds,
// and then how to turn a single pixel white and then off, moving down the line of pixels.
// 

#define NUM_LEDS 4       // How many leds are in the strip?
#define LED_PIN 0       // Data pin that led data will be written out over
#define SWITCH_PIN 2   // the number of the orientation switch pin
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define UPDATES_PER_SECOND 40

CRGB leds[NUM_LEDS];     // This is an array of leds.  One item for each led in your strip.

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

//extern CRGBPalette16 myRedWhiteBluePalette;
//extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

void setup() {
    
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    
    SetupPurpleAndGreenPalette();
    currentBlending = BLEND;
    
}

void loop() {
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  FillLEDsFromPaletteColors( startIndex);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 255;
  
  for( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 90;
  }
}

void SetupPurpleAndGreenPalette()
{
  CRGB purple = CHSV( HUE_PURPLE, 255, 255);
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB black  = CRGB::Black;
  
  currentPalette = CRGBPalette16(CRGB::White,  CRGB::Cyan,  CRGB::White,  CRGB::Purple, CRGB::Green);
    
    //,
    //CRGB::White, CRGB::Cyan, CRGB::White,  CRGB::Green,
    //CRGB::Cyan,  CRGB::White,  CRGB::Purple,  CRGB::White,
    //CRGB::Green, CRGB::White, CRGB::White, CRGB::Pink
}
