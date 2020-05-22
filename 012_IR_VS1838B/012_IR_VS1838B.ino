/*
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 *
 * Utilizzo di un ricevitore ad infrarossi VS1838B. 
 */
#include <IRremote.h>
#include <IRremoteInt.h>

const unsigned int RECV_PIN = 7; // PIN segnale -> Arduino
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600); //inizializzo la seriale
  irrecv.enableIRIn(); //abilito il ricevitore
  irrecv.blink13(true); //configuro il LED al PIN 13 di Arduino ad illuminarsi all'arrivo di un segnale
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX); // stampo il codice arrivato dal telecomando in formato esadecimale
        irrecv.resume(); // mi preparo a ricevere un nuovo segnale
  }
}