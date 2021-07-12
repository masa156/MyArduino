#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3C,16,2);

void setup() {
  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!!");
}

void loop(){
}
