#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3c,16,2);

 
// 秒を表現するLED関連(緑色LED)
#define SC_LED 12 // 秒を表現する青色LEDの端子番号
#define SC_ON  50 // 秒を表現するLEDをつけている時間 (単位:ミリ秒)
#define SC_OFF 1000 - SC_ON // 秒を表現するLEDを消している時間 (単位:ミリ秒)
 
// 残り時間を表現するLED関連(青色、黄色、赤色LED)
const int bluePin = 8; // 青色LEDの端子番号
const int yellowPin = 6; // 黄色LEDの端子番号
const int redPin = 4; // 赤色LEDの端子番号

 
// スタートスイッチ関連
#define SWITCH 5   // スイッチを接続している端子番号
#define SWITCH_OFF 1 // スイッチOFFの時のdigitalReadの値
#define SWITCH_ON  0 // スイッチONの時のdigitalReadの値
 
// タイマー時間設定(単位:秒)
#define TIMER_SC 30
 
// 残り時間を表現するLEDの制御時間
#define yellow_SC 10
#define red_SC   20
 
// アラーム音関連
#define SPEAKER 11  // スピーカーの端子番号
#define ALARM   880 // アラーム音の音程(単位:Hz)
 
 
void setup() {
  
  // 端子の設定
  pinMode(SC_LED,   OUTPUT);   // 緑色LED接続端子設定
  pinMode(bluePin, OUTPUT);   // 青色LED接続端子設定
  pinMode(yellowPin,  OUTPUT);   // 黄色LED接続端子設定
  pinMode(redPin, OUTPUT);   // 赤色LED接続端子設定
  pinMode(SWITCH, INPUT_PULLUP); // スイッチ接続端子の設定
 
  // 秒のLED(緑LED)を点灯する
  digitalWrite(SC_LED, HIGH);

  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
 
  // スイッチが押されるまで待つ
  while(digitalRead(SWITCH) == SWITCH_OFF) {
  }
 
  // タイマー開始時に青色LEDを点灯
  setColor(255, 0, 255);
  
}
 
 
void loop() {
  
  // for文で回数を数えるために使用する変数
  uint8_t count;
 
  // TIMER_JIKAN分の回数を数える
  for( count=0; count<TIMER_SC; count++) {
 
    // 残り時間表現用LEDの制御
    if( count == yellow_SC ) {
      setColor(0, 255, 255);
    }
 
    if( count == red_SC ) {
      setColor(255, 255, 0);
    }
 
    // 1秒に1回緑色LEDを点滅する
    digitalWrite(SC_LED, HIGH);
    delay(SC_ON);
    digitalWrite(SC_LED, LOW);
    delay(SC_OFF);
     
  }
 
  // 時間になったので秒のLED(緑色LED)を点灯する
  digitalWrite(SC_LED, HIGH);
 
  // アラーム音を3回鳴らす
  for( count=0; count<3; count++) {
    // ピ
    tone(SPEAKER, ALARM);
    delay(60);
    noTone(SPEAKER);
    delay(60);
 
    // ピ
    tone(SPEAKER, ALARM);
    delay(60);
    noTone(SPEAKER);
    delay(60);
 
    // ピーッ
    tone(SPEAKER, ALARM);
    delay(100);
    noTone(SPEAKER);
    delay(600);
 
  }
 
  // 何もしないで待つ
  while( true ) {
     
  }
 
}

void setColor(int red, int yellow, int blue) {
  analogWrite(redPin, red);
  analogWrite(yellowPin, yellow);
  analogWrite(bluePin, blue);
}
