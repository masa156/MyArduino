int ledPin = 9;

void setup() {                        //一回だけ実行する
  pinMode(9, OUTPUT);        //LEDを接続した13番ピンを出力用に設定する
}
void loop() {                          //{}内を無限ループで実行する
  for(int i=0;i<10;i++){           //iが0から1ずつ増加し{}内を3回繰り返す
        digitalWrite(9, HIGH);  //LEDが接続された9番ピンをHIGH(5V)にする
        delay(1000);                //1000ms(1秒)LEDを点灯した状態で止める
        digitalWrite(9, LOW);  //LEDが接続された9番ピンをLOW(0V)にする
        delay(1000);                //1秒LEDを消灯した状態で止める
  }
 delay(3000);                       //for文終了後3秒LEDを消灯した状態で止める
}
