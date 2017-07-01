#### Homework

+ Read the three resources about functions [here](https://github.com/michaelshiloh/resourcesForClasses#functions)
+ Add the distance measuring sensor to your robot, and write a program to help your robot avoid obstacles. Document as before (picture, video, code with excellent comments). Also describe (in README.md or another .md file) any difficulties you encountered and how you overcame them, and anything interesting you discovered.

#### Advanced challenge:
+ Mount the distance measuring sensor on the servo motor. Use some sort of extension to the pins, do not solder wires to the pins
+ Write a program to make your robot go in the direction where there is the most space.
+ Document as before (picture, video, code with excellent comments, and discussion (in README.md or other .md file)).
+ As a treat, here is an example of what you can do with two servo motors (and a Theremin)

``` Javascript
// defining constant variables for distance measuring sensor pins
const int trigPin = 7;
const int echoPin = 9;

// setup function runs once at the beginning
void setup() {
  // initialize digital pins for motors as an output
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (12, OUTPUT);

  // control motor speed by using analog write 
  analogWrite (6, 200);
  analogWrite (12, 200);

  // intialize Serial
  Serial.begin (9600);

  // initialize trigPin and echoPin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// create loop function for sequence
void loop() {

  long duration, distance;

  // Drive trigger pin LOW, HIGH, LOW to send the pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // low for 2 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // high for 10 microseconds
  digitalWrite(trigPin, LOW);

  // the pulseIn command waits for a given pin to go HIGH, and then
  // reports how long it waited until that happened
  duration = pulseIn(echoPin, HIGH); // measure the time to the echo

  // Convert to centimeters
  distance = (duration / 2) / 29.1; // calculate the distance in cm

  // Discard readings that are too large or too small to be reasonable
  // It's pretty common for some sensors to give occasional bad readings
  // and a good program must take that into account
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range; reading invalid");
  } else {
    // anything left should be a valid distance
    Serial.print(distance);
    Serial.println(" cm");
  }

  // create if condition for robot to move forward as long as distance is >= 20 cm
  if (distance >= 20) {

    // make robot move forward for half a second (500 miliseconds)
    digitalWrite (2, HIGH);
    digitalWrite (4, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (10, LOW);
    delay(1000);
  }

  // create if condition for robot to move stop and turn when distance is < 20 cm
  else {

    // make robot stop before turning
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);

    // make robot turn right
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (10, LOW);
    delay(500);

    // make robot stop after making a turn
    digitalWrite (2, LOW);
    digitalWrite (4, LOW);
    digitalWrite (8, LOW);
    digitalWrite (10, LOW);
    delay(500);
  }
}
```
