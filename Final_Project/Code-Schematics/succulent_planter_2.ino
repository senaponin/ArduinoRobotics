class Wheel {
    //Class Member Variables
    //Initialized at startup

    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT );

    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT );


    analogWrite(3, 400);
    analogWrite(6, 400);

}

void setup() {
  // put your setup code here, to run once:

  int sensorPin1 = A0;    // select the input pin for the potentiometer
  int sensorPin2 = A1;    // select the input pin for the potentiometer
  int sensorPin3 = A2;    // select the input pin for the potentiometer
  int sensorPin4 = A3;    // select the input pin for the potentiometer
  int sensorValue1 = 0;  // variable to store the value coming from the sensor
  int sensorValue2 = 0;  // variable to store the value coming from the sensor
  int sensorValue3 = 0;  // variable to store the value coming from the sensor
  int sensorValue4 = 0;  // variable to store the value coming from the sensor



  Serial.begin(9600); // initialize Serial
  rightWheel


}

void loop() {
  // put your main code here, to run repeatedly:

  sensorValue1 = analogRead(sensorPin1); // update sensorValue1
  sensorValue2 = analogRead(sensorPin2); // update sensorValue2
  sensorValue3 = analogRead(sensorPin3); // update sensorValue1
  sensorValue4 = analogRead(sensorPin4); // update sensorValue2

  printSensorValues();


}
