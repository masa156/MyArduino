#include "LPD8806.h"
#include "SPI.h" 


int nLEDs = 4;

int dataPin  = 2;   
int clockPin = 3;  

LPD8806 strip = LPD8806(nLEDs, dataPin, clockPin);

void setup() {

  
  strip.begin();

  strip.show();

  Serial.begin(9600);
}

void loop() {
    int i;
    int sw = Serial.read();
  // もしaという文字が送られてきたら
  if (sw == 'a') {
    for (i=0; i < strip.numPixels(); i++) {
    // ピクセル（1個のRGB LED）の色を設定する　：　strip.setPixelColor(LEDの番号, RGB色の設定）
    // RGB色は、strip.Color(Red, Green, Blue)で設定する　各色127段階で表す　
    // （通常neo pixel系では各色255段階が多いが、このテープLEDは127段階）
    // 127, 127, 127 : White
    // 127, 0, 0 : Red
    // 0, 127, 0 : Green
    // 0, 0, 127 : Blue
    strip.setPixelColor(i, strip.Color(127, 127, 127));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
  
   } else if (sw == 's') {
       for (i=0; i < strip.numPixels(); i++) {
    
      strip.setPixelColor(i, strip.Color(127, 0, 0));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
  
  } else if (sw == 'd') {
      for (i=0; i < strip.numPixels(); i++) {
  
      strip.setPixelColor(i, strip.Color(0, 127, 0));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
  
  } else if (sw == 'f') {
      for (i=0; i < strip.numPixels(); i++) {
    
      strip.setPixelColor(i, strip.Color(0, 0, 127));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
  
  } else if (sw == 'g') {
      for (i=0; i < strip.numPixels(); i++) {
  
      strip.setPixelColor(i, strip.Color(127, 0, 127));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
  
  } else if (sw == 'h') {
      for (i=0; i < strip.numPixels(); i++) {
   
      strip.setPixelColor(i, strip.Color(0, 127, 127));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
  
  } else if (sw == 'j') {
      for (i=0; i < strip.numPixels(); i++) {
 
      strip.setPixelColor(i, strip.Color(127, 127, 0));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
  
  } else if (sw == 'k') {
      for (i=0; i < strip.numPixels(); i++) {
        
      strip.setPixelColor(i, strip.Color(0, 0, 0));
   }
   strip.show();
  // 1000ミリ秒　プログラムが停止する
  delay(1000);
 }
} 
