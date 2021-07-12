const int numReadings = 10;  //配列の個数　平均値を出すための読み取るサンプルの個数
int readings[numReadings];      // 読み取る値を入れておく配列変数　要素は10個
int readIndex = 0;              // 配列を扱うときのインデックス用の変数
int total = 0;                  // 読み取り値平均を計算するための合計を入れておく変数
int average = 0;                // 平均値を入れる変数
int inputPin = A0;
int ledPin = 9;      
int threshold =100;

void setup() {
  pinMode(9, OUTPUT);
  // initialize serial communication with computer:
  Serial.begin(9600);
  // 読み取った値を入れる配列の中身を全て0で初期化
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
void loop() {
  // loop内で、配列の中身をセットしながら、そのときの配列の合計値、平均値も計算
  // 平均値 => 
  // （平均計算用の）合計値から前回の読み取り値を引く　subtract the last reading:
  total = total - readings[readIndex];
  // 現在のセンサー入力値を取得　read from the sensor:
  readings[readIndex] = analogRead(inputPin);
  // 入力値を合計値に加える　add the reading to the total:
  total = total + readings[readIndex];
  // 配列のインデックスを一つ進める　advance to the next position in the array:
  readIndex = readIndex + 1;
  // もし、配列の最後のインデックスになったら　if we're at the end of the array...
  if (readIndex >= numReadings) {
    // インデックスを最初の0にする　...wrap around to the beginning:
    readIndex = 0;
 
  }
  // 平均値を計算　合計値 / 配列の個数　calculate the average:
  average = total / numReadings;
  // デバッグ用にシリアルでPCに送信　send it to the computer as ASCII digits
  Serial.println(average);
  if (average <= threshold) { 
    digitalWrite(ledPin, HIGH);   // LEDをオンに 
  } else { 
    digitalWrite(ledPin, LOW);    // LEDをオフに 
    
  delay(1);        // delay in between reads for stability
}
}
