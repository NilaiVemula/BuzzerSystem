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

//VARIABLE DECLARATIONS

//initializing pin numbers as constants
const int YELLOW_LED = 5;
const int GREEN_LED = 6;
const int RED_LED = 10;

const int YELLOW_SWITCH = 3;
const int GREEN_SWITCH = 7;
const int RED_SWITCH = 11;

//declaring triggered booleans
boolean yellowTriggered;
boolean greenTriggered;
boolean redTriggered;

void setup() {
  //initializing LED pins as outputs
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  //initially writing all LEDs as HIGH (turning them off)
  digitalWrite(YELLOW_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);

  //initializing switch pins as inputs with internal pull-up resistors
  pinMode(YELLOW_SWITCH, INPUT_PULLUP);
  pinMode(GREEN_SWITCH, INPUT_PULLUP);
  pinMode(RED_SWITCH, INPUT_PULLUP);

  //initializing all triggered booleans as false (LOW)
  yellowTriggered = LOW;
  greenTriggered = LOW;
  redTriggered = LOW;

}

void loop() {
  //resetting each boolean as LOW each time the loop runs
  boolean yellowTriggered = LOW;
  boolean greenTriggered = LOW;
  boolean redTriggered = LOW;
  
  //turning all the LEDs on
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
 
  //GREEN CODE
  if(digitalRead(GREEN_SWITCH) == LOW){    //If the switch is pressed, the switch pin is connected to GND and it is pulled to LOW.
    greenTriggered = HIGH;    //triggered boolean is set to HIGH
  }
  
  if(greenTriggered == HIGH){ //If triggered
    greenTriggered = LOW; //then reset triggered boolean
    //and then turn off all LEDs besides the one that was pressed
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    delay(5000); //wait 5 sec for the MC to manually reset/automatically reset after 5 sec
  }

 //RED CODE
 if(digitalRead(RED_SWITCH) == LOW){
    redTriggered = HIGH;
  }
  
  if(redTriggered == HIGH){
    greenTriggered = LOW;
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    delay(5000);
  }

  //YELLOW CODE 
  if(digitalRead(YELLOW_SWITCH) == LOW){
    yellowTriggered = HIGH;
  }
  
  if(yellowTriggered == HIGH){
    yellowTriggered = LOW;
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
    delay(5000);
  }

}
