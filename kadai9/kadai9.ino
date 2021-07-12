int ledPin = 9; 

void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  for(int i=0;i<10;i++){
    digitalWrite(9, HIGH);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1000);
   }
   delay(3000);
}
