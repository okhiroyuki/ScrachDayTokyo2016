#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16,12,NEO_GRB + NEO_KHZ800);

int i;

void setup()
{
  pixels.begin();

  pixels.setBrightness(50);

}


void loop()
{
  for (i = 0; i <= 12; i++) {
    pixels.setPixelColor(i,pixels.Color(255,102,102));
    pixels.show();
    delay(100);
  }
  for (i = 12; i >= 0; i--) {
    pixels.setPixelColor(i,pixels.Color(255,0,0));
    pixels.show();
    delay(100);
  }
  for (i = 6; i >= 0; i--) {
    pixels.setPixelColor((i * 2),pixels.Color(51,102,255));
    pixels.show();
    delay(100);
  }
  for (i = 0; i <= 5; i++) {
    pixels.setPixelColor((i * 2 + 1),pixels.Color(255,255,153));
    pixels.show();
    delay(100);
  }

}