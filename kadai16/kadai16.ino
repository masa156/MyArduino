/*State change detection (edge detection)*/

const int  buttonPin = 2;    // 定数 the pin that the pushbutton is attached to
const int ledPin = 13;       // 定数 the pin that the LED is attached to
int buttonPushCounter = 0;   // 変数 ボタン押下の回数カウンター
int buttonState = 0;         // 変数 現在の ボタンの状態　初期値0(LOW)
int lastButtonState = 0;     // 変数 過去の（loop()1回前の）ボタンの状態　初期値0(LOW)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // initialize the button pin as a input:
  pinMode(ledPin, OUTPUT);  // initialize the LED as an output:
  Serial.begin(9600); // initialize serial communication:
}
void loop() {
  buttonState = digitalRead(buttonPin);  // ボタン入力ピンを読み取り　状態を格納
  if (buttonState != lastButtonState) { // 1回前のボタンの状態と今回の状態を比較
    //変化ありのとき
    if (buttonState == HIGH) {  // 変化あり　かつ　ボタン on
      buttonPushCounter++;  //ボタン押した　カウントアップ
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {    //その他　ボタン変化あり　かつ　ボタン off　→　ボタンを離したとき
      Serial.println("off");
    }
    delay(50);  // 少し待つ　ボタンの2度押し（チャタリング）除去のため
  }
  lastButtonState = buttonState;  // 現在の状態 を次の繰り返しに備えて　lastStateに格納
  // ボタン4回押した毎にLEDをonにする　演算子%は、割った余りを計算する
  if (buttonPushCounter % 2 == 0) { //ボタン押下カウンターを4で割った余りが0のとき
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
