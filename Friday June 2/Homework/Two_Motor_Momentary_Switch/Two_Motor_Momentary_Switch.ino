//Created by Nino Panes w/ the help of Michael Shiloh. Modified blink Code to turn on Motors
const int pushButton = 8;
void setup() {
  // initialize digital pin output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT );

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT );


  analogWrite(6, 430);
  analogWrite(2, 430);

}

// the loop function runs over and over again forever
void loop() {

  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(1);
  if (buttonState == HIGH) {

    digitalWrite(3, HIGH);   // Move Forward for 1 second
    digitalWrite(4, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(12, LOW);
    delay(1000);
  } else {

    digitalWrite(3, LOW);     //Move Backward for 1 second
    digitalWrite(4, HIGH);

    digitalWrite(7, LOW);
    digitalWrite(12, HIGH);
    delay(1000);

  }
}
