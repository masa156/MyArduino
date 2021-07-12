#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// コンパイル時にヘッダーファイルが適切に編集されていない場合に
// "Height incorrect, please fix Adafruit_SSD1306.h!"
// というエラーを表示するための記述
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// RSTピンがない互換品を使用するので-1を指定
Adafruit_SSD1306 display(-1);

void setup() {
  // I2Cアドレスは使用するディスプレイに合わせて変更する
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  // 画面表示をクリア
  display.clearDisplay();

  // 画面の左側に長方形(塗りつぶしなし)を描画
  // display.drawRect(左上x, 左上y, 幅, 高さ, 線の色)
  display.drawRect(10, 10, 44, 44, WHITE);

  // 画面の右側に長方形(塗りつぶしあり)を描画
  // display.fillRect(左上x, 左上y, 幅, 高さ, 線の色)
  display.fillRect(74, 10, 44, 44, WHITE);

  // 描画バッファの内容を画面に表示
  display.display();

  delay(1000);
}
