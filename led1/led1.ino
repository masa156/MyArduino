int ledPin = 8; // LED connected to digital pin 8
int inPin = 7; // pushbutton connected to digital pin 7
int val = 0;  // variable to store the read value

void setup()
{ 
pinMode(ledPin, OUTPUT);   //set OUTPUT
pinMode(inPin, INPUT);        //set INPUT   
}

void loop()
{ 
val = digitalRead(inPin);  // read the input pin 
digitalWrite(ledPin, val);  // sets the LED to the button's value
}
