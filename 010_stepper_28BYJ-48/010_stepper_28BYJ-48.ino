#include <Servo.h>
#include <Stepper.h>

static const unsigned int SERVO_PIN = 13;
static const int STEPS_PER_REVOLUTION     = 24 * 64;
static const int PIN_IN1_BLUE             = 8;
static const int PIN_IN2_PINK             = 9;
static const int PIN_IN3_YELLOW           = 10;
static const int PIN_IN4_ORANGE           = 11;


Servo servo;
Stepper myStepper(STEPS_PER_REVOLUTION, PIN_IN1_BLUE, PIN_IN3_YELLOW, PIN_IN2_PINK, PIN_IN4_ORANGE);


void setup() {
  servo.attach(SERVO_PIN);
  servo.write(0); // porto in posizione iniziale il servo motore
  delay(2000);

    myStepper.setSpeed(6.5);                // in rpm

}

void loop() {
  servo.write(90); // invio il valore al servo motore                  
  delay(1000);
  servo.write(180); // invio il valore al servo motore                  
  delay(1000);
  servo.write(90); // invio il valore al servo motore                  
  delay(1000);
  servo.write(0); // invio il valore al servo motore                  
  delay(1000);

     myStepper.step(STEPS_PER_REVOLUTION);   // clockwise
  delay(100);
  myStepper.step(-STEPS_PER_REVOLUTION);  // counter-clockwise
  delay(1000);
}