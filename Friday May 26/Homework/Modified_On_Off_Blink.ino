/*
Based on a code by
Created by David Cuartielles
modified May 31, 2017
By Nino Panes
his example code is in the public domain.
http://www.arduino.cc/en/Tutorial/AnalogInput

Homework: Make LED turn on above a treshold, and turn off below a treshold. Make it blink in between the code.

*/

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //Initialize read for print
}

void loop() {
  Serial.println(sensorValue);
  // read the value from the sensor:


  sensorValue = analogRead(sensorPin);
  // turn the ledPin on

  if (sensorValue >= 400) {
    digitalWrite(ledPin, HIGH);
  }
  else if (sensorValue <= 130) {
    // turn the ledPin off:
    digitalWrite(ledPin, LOW); 
  }

  else {
    // blinking pattern
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin, LOW);
  }
}
