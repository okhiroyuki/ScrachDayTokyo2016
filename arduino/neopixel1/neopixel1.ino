#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16,12,NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin();

  pixels.setBrightness(50);

}


void loop()
{
  pixels.setPixelColor(0,pixels.Color(0,255,0));
  pixels.setPixelColor(1,pixels.Color(255,0,0));
  pixels.setPixelColor(2,pixels.Color(0,255,0));
  pixels.setPixelColor(3,pixels.Color(255,0,0));
  pixels.setPixelColor(4,pixels.Color(0,255,0));
  pixels.setPixelColor(5,pixels.Color(255,0,0));
  pixels.setPixelColor(6,pixels.Color(0,255,0));
  pixels.setPixelColor(7,pixels.Color(255,0,0));
  pixels.setPixelColor(8,pixels.Color(0,255,0));
  pixels.setPixelColor(9,pixels.Color(255,0,0));
  pixels.setPixelColor(10,pixels.Color(0,255,0));
  pixels.setPixelColor(11,pixels.Color(255,0,0));
  pixels.show();

}