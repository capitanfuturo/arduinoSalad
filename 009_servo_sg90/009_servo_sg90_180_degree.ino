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
  // ruoto in un senso
  for(int angle = 0; angle < 180; angle++){
    servo.write(angle);
    delay(10);
  }
  // ruoto nel senso opposto
  for(int angle = 180; angle > 0; angle--){
    servo.write(angle);
    delay(10);  
  }
  
}
