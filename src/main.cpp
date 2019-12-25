#include "Arduino.h"

// Sound parameters
int play=4;                     // define the sound interface

// Eyes parameters
int led = 9;                    // define LED Interface, needs to be a pwm enabled pin
int brightness = 0;             // how bright the LED is
int fadeAmount = 2;             // how many points to fade the LED by
int delayAmount = 150;

// tilt sensor parameters
int buttonpin = 3;              // define the tilt switch sensor interfaces
int val;                        // define numeric variables val

void setup() {
  Serial.begin(9600);
  
  pinMode (led, OUTPUT);        // define LED as output interface
  pinMode(play,OUTPUT);         // define play as sound output interface
  pinMode (buttonpin, INPUT);   //define the output interface tilt switch sensor

  digitalWrite(play,LOW);       // off by default
}

void eyesOn() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // stop fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    brightness = 255;
  }
  delay(delayAmount);
}

void eyesOff() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness - fadeAmount;  

  // stop fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    brightness = 0;
  }
  delay(30);
}

void loop() {
  val = digitalRead (buttonpin);  // digital interface will be assigned a value of 3 to read val
  if (val == HIGH) {              // When the tilt sensor detects a signal when the switch, LED flashes
    eyesOn();
    digitalWrite(play,HIGH);
  } else {
    eyesOff();
    digitalWrite(play,LOW);
  }
}