#include <Arduino.h>
#include <FastLED.h>

#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
//bouton du atom
#define MA_BROCHE_BOUTON 39
//CRGB keyPixel;
CRGB pixelAtom;

#include <M5_PbHub.h>
M5_PbHub myPbHub;
#define CANAL_KEY_UNIT 0
void setup() {
  FastLED.addLeds<WS2812, 27, GRB>(&pixelAtom, 1); 
  //FastLED.addLeds< WS2812, BROCHE_ATOM_FIL_JAUNE , GRB >(&keyPixel, 1);
  // initialise la touche du key unit
 // pinMode( BROCHE_ATOM_FIL_BLANC , INPUT_PULLUP );
  pinMode( MA_BROCHE_BOUTON , INPUT );
  pixelAtom = CRGB(250,250,250); // BLANC
  Wire.begin();
  myPbHub.begin();
  myPbHub.setPixelCount( CANAL_KEY_UNIT , 1);
}




void loop()

{
  //int maLectureKey = digitalRead(BROCHE_ATOM_FIL_BLANC);
  int maLectureKey =myPbHub.digitalRead( CANAL_KEY_UNIT );
  //keyPixel = CRGB(255, 255, 255); // BLANC
  
  if (maLectureKey == 1) {
    //keyPixel = CRGB(0, 0, 0);
    myPbHub.setPixelColor( CANAL_KEY_UNIT , 0 , 0,0,0);
    FastLED.show();
  } else {
    int rouge = random(0,128);
    int vert = random(0,256);
    //keyPixel = CRGB(rouge, vert, 0);
    myPbHub.setPixelColor( CANAL_KEY_UNIT , 0 ,rouge,vert,0 );
    FastLED.show();
  }

  int maLectureBouton = digitalRead(MA_BROCHE_BOUTON);
  pixelAtom = CRGB(255, 255, 255); // BLANC

  if (maLectureBouton == 1) {
    pixelAtom = CRGB(0, 0, 0);
    FastLED.show();
  } else {
    pixelAtom = CRGB(127, 255, 0);
    FastLED.show();
  }

  delay(20);
}