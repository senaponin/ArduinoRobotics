Arduino Robotics - [Summer Class](https://github.com/michaelshiloh/ArduinoRoboticsSummer2017)

# ArduinoRobotics
Arduino Robotics at the California College of the Arts, Summer 2017


# HW 1 - how to use a sensor
#### May 24, 2017
```Javascript
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
```

# HW 1 - analog write(): Controlling speed or brightness
#### May 24, 2017
```Javascript
/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
```
# HW 1 - Controlling speed or brightness (EXTRA)
#### May 24, 2017 


```Javascript
/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

int led = 11;           // the PWM pin the LED is attached to
int led2 = 10;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  Serial.begin(9600); //Initialize read for print
}

// the loop routine runs over and over again forever:
void loop() {

  Serial.println(brightness);
  // set the brightness of pin 11:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(40);


   // set the brightness of pin 11:
  analogWrite(led2, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(40);

  
}
```

# HW 1 - Optional 2 LED
#### May 24, 2017 - Optional: Can you figure out how to connect two LEDs to your Arduino and how to make them blink?


```Javascript
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(11, OUTPUT); // Initialize PinMode
  pinMode(10, OUTPUT); //Don't forget to put pinMode or else it will be very dim lighting.
}

// the loop function runs over and over again forever. Change this to alter the blinking patterns.
void loop() {
  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second 
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```

# HW 2 -  [Analog Input tutorial](https://www.arduino.cc/en/Tutorial/AnalogInput)
#### May 26, 2017 - Read and do the Arduino AnalogInput tutorial. Use your LDR and not a potentiometer. Make notes in your "journal" (your README.md file) of any interesting things you discover or any problems that you run into.

##### Encountered Problem
Using the code from the website only gave me the value "0" when I added a print.ln and created a serial port. Trying another program from the example given by arduino, I was able to make it work. But why is the code that was given from the website not working? (code below) I attached an extra LED light to the existing built in LED pin 13 and when I cover the LDR the blinking goes faster? How does this work?

```Javascript
/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

 */

int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
```

##### Fix to problem above
I placed sensorValue onto [Serial.println(sensorValue);] and I was able to come up with the desired values.(code below)

```Javascript
/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/AnalogInput

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
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
```
##### Resource used for this week's assignment
+ http://www.instructables.com/id/Auotmatic-Street-lights-control-using-LDR-and-Ardu/
+ https://www.arduino.cc/en/Tutorial/ifStatementConditional

##### Encountered Problem
I was able to make the built in LED work however when I added an external LED it was behaving differently from my conditionals that I placed. 

##### Problem Solve
Make sure the 13 pin goes into ground instead of connecting it to 5V. When this connection is made from 13 Pin > 5V instead of Ground, you will create the opposite effect of the conditional making the external LED light up when it's suppose to be low then off when it's suppose to be high.

# In Class Motor Example
#### May 26, 2017

```Javascript
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT );

  //digitalWrite(6, HIGH);
  analogWrite(6, 230);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

  digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(4, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

}
```

# For and While Explanation
#### May 30, 2017

While() - Keep doing coinditioin as long as it is true. It will never check the sensor again.
For() - Keep a task going for a finite amount of time.

``` Javascript
for( int count = 0; count < 7 ; count++){
HIGH
DELAY()
LOW
DELAY()
}
```
# HW 2 - Problems Encountered
#### June 2, 2017

+ Problem # 1: Right motor won't ober completely the commands I have given it. Course of action will be to change the wires if that doesn't work change the H bridge. The left one works fine. If that still doesn't work I will look at the code once more and ask Michael this weekend on how to fix the problem.
+ Problem # 2: Based on the weight of the robot the motors need to work harder. Something that I noticed. Not really a problem now but this will need to be taken into account when building future motors. Make sure it can handle the weight. 


# HW 2 - Problem Solve
#### June 5, 2016

I changed the pins in which it was located. At first I was using pins 2,3, and 4 but changed it to 2, 4, and 5. And that made the difference.

``` Javascript
//Created by Nino Panes w/ the help of Michael Shiloh. Modified blink Code to turn on Motors
const int pushButton = 8;
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

    digitalWrite(4, HIGH);   // Move Forward for 1 second
    digitalWrite(5, LOW);

    digitalWrite(7, HIGH);
    digitalWrite(12, LOW);
    delay(1000);
    
  } else {                    // Else allows it to change its actions briefly until its done then it goes to the original action.

    digitalWrite(3, LOW);     //Move Backward for 1 second
    digitalWrite(4, HIGH);

    digitalWrite(7, LOW);
    digitalWrite(12, HIGH);
    delay(1000);

  }
}
```

# HW 4 - Problems Encountered/solved
#### June 7, 2017

I couldn't figure out why my LDR weren't responding correctly but then realized that I was using two different resistors therefore it was giving me different results when I was looking at serial monitor. Make sure to have similar resistors for LDR's


# Array
#### June 9, 2017
In class Array example

+ int ( whole numbers )
+ float ( decimal points )
+ Long ( 2 Billion / Large numbers )


##### Without Array
``` Javascript
const int ledPin = 9;
const int ledPin = 4;

const int ledPin = 7;


void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

##### With Array
``` Javascript
//const int ledPin = 9;
//const int ledPin = 4;
//
//const int ledPin = 7;

//Initialize Array
const int ledPins[] = { 9, 4, 7, 2, 3, 5, 6, 8, 12, 11};       //You dont need to write [10] because you already have the numbers
//or write it this way
//const int ledPins[10];

void setup() {
  // put your setup code here, to run once:

  //  pinMode(ledPins, OUTPUT);
  //  pinMode(ledPins, OUTPUT);
  //  pinMode(ledPins, OUTPUT);

  for (int i = 0; i < 10; i++);  //i++ = i = 1+1
  {
    pinMode(ledPins[1], OUTPUT);
    Serial.println(ledPins[1]);
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}
```

##### Simple Class Smoothing Ex.


``` Javascript

/*
 * simpleClassExample: A very simple example showing how to create and use a class
 * 
 * The class in this example assumes a sensor attached to an analog input. 
 * The class provides the ability to take multiple readings
 * and then to report their average
 * 
 * This example code is in the public domain
 * 
 * 8 June 2017 - Michael Shiloh - Created
 */
 
const int SENSOR_1_PIN = A0;
const int SENSOR_2_PIN = A1;

// This is how many readings will be taken
const int NUM_SENSOR_READINGS = 10;

class Sensor {

    // Member variables
    int pinNumber;
    int readings[NUM_SENSOR_READINGS];

  public:

    // The function with the same name as the class is a special function called the "constructor".
    // You can think of it as the "Setup" function for the object
    // The constructor takes one argument, which is the pin number of this particular sensor
    Sensor(int x) {
      pinNumber = x;

      pinMode(pinNumber, INPUT);
    } // end of constructor

    void takeReadings() {
      for (int i = 0; i < NUM_SENSOR_READINGS; i++) {
        readings[i] = analogRead(pinNumber);
        delay(1); // pause after each analogRead() to allow it to do its work
      }
    } // end of takeReadings

    int getAverage() {
      int sum = 0;
      int average;

      for (int i = 0; i < NUM_SENSOR_READINGS; i++) {
        sum = sum + readings[i];
      }
      average = sum / NUM_SENSOR_READINGS;
      return average;

    } // end of getAverage
}; // end of class Sensor


// Create two objects using the Sensor class
Sensor sensor1(SENSOR_1_PIN);
Sensor sensor2(SENSOR_2_PIN);

void setup () {
  Serial.begin(9600);
}

void loop() {

  // Take multiple readings from the two sensors represented by these objects
  sensor1.takeReadings();
  sensor2.takeReadings();

  // Print the average values of those readings
  Serial.print("Sensor 1: ");
  Serial.print(sensor1.getAverage());
  
  Serial.print(" Sensor 2: ");
  Serial.print(sensor2.getAverage());
  Serial.println();

  delay(500);
}
```
