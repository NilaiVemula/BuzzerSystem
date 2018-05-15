# BuzzerSystem
/*
 * Buzzer Code
 * 
 * By Nilai Vemula
 * 5/14/18
 * 
 * This is the code for a buzzer system. Conceptually based on: https://www.iliketomakestuff.com/make-quiz-game-buttons/
 * Objective: The buzzers all light up and then wait for someone to press one of the buzzers. When one is pressed, all of other buzzers stop lighting up.
 * 
 * Wiring:
 * There are three buttons (yellow, green, and red). Each button has four terminals: two for the switch and two for the LED).
 * Each button had four wires coming to it (black, red, yellow, and green). Black was wired up to GND and red was wired to 5V. Yellow and green were connected to digital I/O on the arduino.
 * The switch pins on the button were connected to black and yellow wires. The LED pins were connected to red and green with the cathode on red.
 * When the button is pressed, the switch is closed and the yellow wire is pulled to GND. The LED lights up when the green wire is set to LOW and current flows from the red wire to the green wire and sinks to the Arduino.
 * The whole set-up is powered through USB (5V and GND). The Arduino (Nano) is powered through its (mini)-B USB port. A mini-USB cable is wired to the power input through its red and black wires.
 * 
 */
