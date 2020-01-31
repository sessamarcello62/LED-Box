#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN            6


#define NUMPIXELS      10

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int x;
int y;
int z;
int r;
int g;
int b;
void setup() {
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  r = analogRead(3) / 4;
  g = analogRead(2) / 4;
  b = analogRead(1) / 4;
  x = analogRead(5);
  y = x / 126;
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.print(r);
  Serial.print("\t");
  Serial.print(g);
  Serial.print("\t");
  Serial.println(b);

  for (z = 0; z < 8; z++) {

      pixels.setPixelColor(z, pixels.Color(r, g, b));
  
  }


  pixels.show();
  delay(50);

}
//pixels.setPixelColor(7, pixels.Color(0, 255, 0));
