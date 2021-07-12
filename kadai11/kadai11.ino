int ledPin =  9;  //変数ledPinに9を代入（プログラムの全ての位置で使える変数）
int var = 0;

void setup() {
  pinMode(9, OUTPUT);   // 出力に設定
}

void loop() {
  var = 0;
  while(1){ 
   digitalWrite(9, HIGH);   // LEDをオン
   delay(1000);                  // 1秒待つ
   digitalWrite(9, LOW);    // LEDをオフ
   delay(1000);
   var++;
  }
  delay(3000);
}
