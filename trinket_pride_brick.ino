#include <Adafruit_NeoPixel.h>

#define NEO_PIN 0
#define NUM_PIXELS 6
#define DELAY 100

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

// reused from Adafruit_Neopixel example
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// reused from Adafruit_Neopixel example
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  rainbowCycle(DELAY);
}
