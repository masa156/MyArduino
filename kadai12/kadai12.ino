int ledPin =  9;  //変数ledPinに9を代入（プログラムの全ての位置で使える変数）
int delayTime[5] = {100, 200, 300, 400, 500};
int i;

void setup() {
  pinMode(9, OUTPUT);   // 出力に設定
}

void loop() {
  for(int i=0;i<5;i++){
    digitalWrite(9, HIGH);
    delay(delayTime[i]);
    digitalWrite(9, LOW);
    delay(delayTime[i]);
    }
   delay(3000);                  // 3秒待つ
}
