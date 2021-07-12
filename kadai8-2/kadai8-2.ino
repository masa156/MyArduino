void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop() {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  if (pinMode == 10) {
    digitalWrite(10, HIGH);
    delay(1000);
    digitalWrite(10, LOW);
    delay(1000);
    }
    else if(pinMode == 11){
      digitalWrite(11, HIGH);
      delay(250);
      digitalWrite(10, LOW);
      delay(250);
      }
      else if (pinMode == 12){
        delay(1500);
        digitalWrite(12, LOW);
        delay(1500);
        }
        else{
         randomSeed(analogRead(0));
        int i =random(1000);  
        delay(i);
        digitalWrite(13, LOW);
        delay(1000-i);
          }
  }
