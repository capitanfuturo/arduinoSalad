/*
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 *
 * Utilizzo di un motore passo passo 28BYJ-48 + scheda driver
 * ULN2003 con l'ausilio della libreria standard Stepper. 
 */
#include <Stepper.h>

static const int STEPS_PER_REVOLUTION     = 24 * 64;
static const int PIN_IN1_BLUE             = 8;
static const int PIN_IN2_PINK             = 9;
static const int PIN_IN3_YELLOW           = 10;
static const int PIN_IN4_ORANGE           = 11;

Stepper myStepper(STEPS_PER_REVOLUTION, PIN_IN1_BLUE, PIN_IN3_YELLOW, PIN_IN2_PINK, PIN_IN4_ORANGE);


void setup() {
  myStepper.setSpeed(6.5); // in rpm rotazioni per minuto
}

void loop() {
  myStepper.step(STEPS_PER_REVOLUTION);   // clockwise
  delay(100);
  myStepper.step(-STEPS_PER_REVOLUTION);  // counter-clockwise
  delay(1000);
}