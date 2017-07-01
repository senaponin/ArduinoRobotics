//Created by Nino Panes w/ the help of Michael Shiloh. Modified blink Code to turn on Motors


int sensorPin1 = A0;    // select the input pin for the potentiometer
int sensorPin2 = A1;    // select the input pin for the potentiometer
int sensorPin3 = A2;    // select the input pin for the potentiometer
int sensorPin4 = A3;    // select the input pin for the potentiometer
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor
int sensorValue3 = 0;  // variable to store the value coming from the sensor
int sensorValue4 = 0;  // variable to store the value coming from the sensor

const int buttonPin = 12;     // the number of the pushbutton pin

int buttonState = 0;          //Start out at zero



void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT );

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT );

  analogWrite(3, 200);
  analogWrite(6, 200);

  Serial.begin(9600); // initialize Serial

  pinMode(buttonPin, INPUT);

}

// the loop function runs over and over again forever
void loop() {

  //Reading sensor value for Light Sensor
  sensorValue1 = analogRead(sensorPin1); // update sensorValue1
  sensorValue2 = analogRead(sensorPin2); // update sensorValue2
  sensorValue3 = analogRead(sensorPin3); // update sensorValue1
  sensorValue4 = analogRead(sensorPin4); // update sensorValue2

  buttonState = digitalRead(buttonPin);

  printSensorValues();


  if (buttonState == HIGH) {  // Allows functions below to only work when trigger isn't connected
    // Top left ldr
    if ((sensorValue1 >= 100) && (sensorValue1 > sensorValue3) && (sensorValue1 > sensorValue4)) {
      left();
      delay (1000);
    }
    // Top right ldr
    else if ((sensorValue2 >= 100) && (sensorValue2 > sensorValue3) && (sensorValue2 > sensorValue4)) {
      right();
      delay (1000);

    }
    // Bottom left ldr
    else if ((sensorValue3 >= 100) && (sensorValue3 > sensorValue2) && (sensorValue3 > sensorValue4)) {
      backLeft();
      delay (1000);
    }
    // Bottom right ldr
    else if ((sensorValue4 >= 100) && (sensorValue4 > sensorValue2) && (sensorValue4 > sensorValue3)) {
      backRight();
      delay (1000);

    } else if ( sensorValue1 && sensorValue2 > sensorValue3 && sensorValue4 ) {
      forward();
      delay (1000);

    } else {
      pause();
      delay(1000);
    }
  } else {
    pause();
    delay(100);
  }

}


void printSensorValues() {

  // print "Sensor 1:(sensorValue1)"
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);

  // print "Sensor 2:(sensorValue2)"
  Serial.print(" Sensor 2: ");
  Serial.print(sensorValue2);

  // print "Sensor 3:(sensorValue3)"
  Serial.print(" Sensor 3: ");
  Serial.print(sensorValue3);

  // print "Sensor 2:(sensorValue2)"
  Serial.print(" Sensor 4: ");
  Serial.print(sensorValue4);

  // print "Sensor 2:(sensorValue2)"
  Serial.print(" Stop ");
  Serial.print(buttonState);

  // print space to start new line on serial monitor
  Serial.println();

}


void forward() {         //Create function forward
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);

  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
}


void left() {         //Create function forward
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);

}

void right() {         //Create function right
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void backRight() {         //Create function back right
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}


void backLeft() {         //Create function back left
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
}

void pause() {         //Create function pause
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
