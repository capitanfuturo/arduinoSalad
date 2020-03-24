/*
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 *
 * Utilizzo di un servo motore Tower Pro SG90 guidato da un potenziometro 
 * con l'ausilio della libreria standard Servo. 
 */
#include <Servo.h>

const unsigned int SERVO_PIN = 9; // pin di comando del servo motore
const unsigned int POT_PIN = 0; // pin di letture del potenziometrp

Servo servo;
int potVal; // valore del potenziometro
int servoVal; // valore da inviare al servo motore

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(0); // porto in posizione iniziale il servo motore
  delay(2000);
}

void loop() {
  potVal = analogRead(POT_PIN); // leggo il valore de lpotenziomentro tra 0 e 1023
  servoVal = map(potVal, 0, 1023, 0, 180); // mappa il valore su uno nuovo tra 0 e 180
  servo.write(servoVal); // invio il valore al servo motore                  
  delay(15);  
}
