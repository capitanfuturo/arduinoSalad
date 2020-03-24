/*
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 *
 * Utilizzo di un servo motore Tower Pro SG90 con l'ausilio della libreria 
 * standard Servo. 
 */
#include <Servo.h>

const unsigned int SERVO_PIN = 9; // pin di comando del servo motore

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(0); // porto in posizione iniziale il servo motore
  delay(1000);
}

void loop() {
  
  servo.write(90); // porto in posizione centrale il servo motore
  delay(1000);
  servo.write(0); // porto in posizione iniziale il servo motore
  delay(1000);
  
}
