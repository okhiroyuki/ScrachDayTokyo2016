#include <Wire.h>
#include <Adafruit_MPR121.h>
Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

int i;

void setup()
{
  cap.begin(0x5A);

  Serial.begin(9600);

}


void loop()
{
  currtouched = cap.touched();
  for (i = 0; i <= 3; i++) {
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i))) {
      Serial.print(i);
      break;

    }
  }
  delay(10);
  lasttouched = currtouched;

}