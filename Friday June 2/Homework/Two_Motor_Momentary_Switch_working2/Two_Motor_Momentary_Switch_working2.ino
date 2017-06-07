//Created by Nino Panes w/ the help of Michael Shiloh. Modified blink Code to turn on Motors
const int pushButton = 8;
int goForward = 0;

void setup() {
  // initialize digital pin output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT );

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

    //Continuously moves forward until button is pressed.
    goFor();


  } else {                    // Else allows it to change its actions briefly until its done then it goes to the original action.

    //Continuously moves backward as long as button is pressed.
    goBack();


  }
}

//Function for Forward
void goFor() {
  digitalWrite(4, HIGH);   // Move Forward for 1 second
  digitalWrite(5, LOW);

  digitalWrite(7, HIGH);
  digitalWrite(12, LOW);
  delay(1000);
}

//Function for Backward
void goBack() {
  digitalWrite(3, LOW);     //Move Backward for 1 second
  digitalWrite(4, HIGH);

  digitalWrite(7, LOW);
  digitalWrite(12, HIGH);
  delay(1000);
}



