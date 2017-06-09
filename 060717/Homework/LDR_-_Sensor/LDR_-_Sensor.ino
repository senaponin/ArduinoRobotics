#include <Servo.h>

int sensorPin1 = A0;    // select the input pin for the potentiometer
int sensorPin2 = A1;    // select the input pin for the potentiometer
int sensorValue1 = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;  // variable to store the value coming from the sensor

Servo myservo; // create servo object to control a servo

void setup() {
  myservo.attach(9); // define pin used with servo motor
  Serial.begin(9600); // initialize Serial
}

void loop() {
  sensorValue1 = analogRead(sensorPin1); // update sensorValue1
  sensorValue2 = analogRead(sensorPin2); // update sensorValue2

  printSensorValues();

  // creating condition for servo to turn left or right following light
  if (sensorValue1 <= sensorValue2) {
    myservo.write(35);
    delay(1000);
  } else {
    myservo.write(150);
    delay(1000);
  }

}

void printSensorValues() {

  // print "Sensor 1:(sensorValue1)"
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);

  // print "Sensor 2:(sensorValue2)"
  Serial.print(" Sensor 2: ");
  Serial.print(sensorValue2);

  // print space to start new line on serial monitor
  Serial.println();

}

