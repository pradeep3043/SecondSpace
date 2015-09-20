// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

int toggle;
  int red = 0;
  int green = 0;
  int blue = 0;
  int br;



// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int x=0;
int delayval = 10; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
pinMode(PIN, OUTPUT);
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
   
  
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
if (Serial.available() > 0)
  { 
   toggle = Serial.parseInt(); // parses numeric characters after the comma
    red = Serial.parseInt(); // parses numeric characters after the comma
    green = Serial.parseInt(); // parses numeric characters after the comma
    blue = Serial.parseInt(); // parses numeric characters after the comma
    br = Serial.parseInt(); // parses numeric characters after the comma2255
    
     Serial.println(toggle);
     Serial.println(red);
     Serial.println(green);
     Serial.println(blue);
     Serial.println(br);
     Serial.println(x);
     
    for(int i=0;i<NUMPIXELS;i++){
      
    if ( toggle==0)
    {      
    pixels.setBrightness (0);       
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
    //pixels.Color takes RGB values, from 0,0,0 up to 255,255,255 and br brightness 0-255
    else if(red==0&&green==0&&blue==0) 
    return;    
    else {
    pixels.setPixelColor(i, pixels.Color(red,green,blue)); // Changes the color
    pixels.setBrightness (br);    //This will set intensity of the light
    
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).
    }
  }
  
  }
  x++;

}
