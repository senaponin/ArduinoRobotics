### Final Project

#### Materials

- 4x LDR Sensor
- 2x DC Motor
- 1x H-bridge
- 2x Wheels


#### Objective
The goal of this project is to create a succulent planter that will move closer to the light in an office or room environment. This is at first a proof of concept that will evolve into many more interactive features. My goal is to create an oasis at CCA by putting plants more around school that will either self regulate itself or allow it to manuever around corners.

With the succulent planter, the first itirations allow for four light sensors that detect which part of the room ( which is usually four cornered ) is receiving the most light from a window. This is not the problem however.

The problem is having accurate distance sensors that will allow it to manuever at higher precision. I worked with the deistance sensor that was available for use and it was not accurate enough to save my robot from stopping before it fell off from the table. Something like this would be what I would use: http://www.migatron.com/high-accuracy-sensor/

The other problem was that how do I make sure it goes back to the original place from where it is placed? A robot knowing its sense of location is one of the hardest things to do. As well as controlling the dc motor itself. I saw this robot commercial that did things I was hoping my robot could do: https://www.youtube.com/watch?v=m6j2cLEwRsY 

Perhaps I can add a homing beacon to the dock that will allow my robot to find its way back.

https://learn.adafruit.com/adafruit-10-dof-imu-breakout-lsm303-l3gd20-bmp180 finishing it off w/ a 9DOF can allow me to control the robot's wheel w/ more accuracy giving it some statements where it should keep going on one only if it is a certain angle.
