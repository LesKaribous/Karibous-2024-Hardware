#include <Adafruit_NeoPixel.h>

#define PIN       6
#define NUMPIXELS 5
#define DELAYVAL 200

const int potarStrat = A0;
const int IHM01 = 2, IHM02 = 3, IHM03 = 4, IHM04 = 5;

int valueStrat = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pinMode(IHM01,INPUT_PULLUP);
  pinMode(IHM02,INPUT_PULLUP);
  pinMode(IHM03,INPUT_PULLUP);
  pinMode(IHM04,INPUT_PULLUP);

  pixels.begin();
  pixels.clear();
  pixels.setBrightness(10);

  for(int j=0; j<2; j++)
  {
    for(int i=0; i<NUMPIXELS; i++) 
    {
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));
      pixels.show();
      delay(DELAYVAL);
    }
    pixels.clear();
  }
  
  pixels.clear();

}

void loop() {
  
  if(digitalRead(IHM01)) pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  else pixels.setPixelColor(0, pixels.Color(150, 0, 0));
  if(digitalRead(IHM02)) pixels.setPixelColor(1, pixels.Color(0, 150, 0));
  else pixels.setPixelColor(1, pixels.Color(150, 0, 0));
  if(digitalRead(IHM03)) pixels.setPixelColor(3, pixels.Color(0, 150, 0));
  else pixels.setPixelColor(3, pixels.Color(150, 0, 0));
  if(digitalRead(IHM04)) pixels.setPixelColor(2, pixels.Color(0, 150, 0));
  else pixels.setPixelColor(2, pixels.Color(150, 0, 0));

  valueStrat = analogRead(potarStrat)/3;
  pixels.setPixelColor(4, pixels.Color(255-valueStrat, 0, valueStrat));

  pixels.show();
}
