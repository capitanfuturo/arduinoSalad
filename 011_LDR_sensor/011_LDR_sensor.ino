/*
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 *
 * Utilizzo di un sensore LDR per costruire un crepuscolare. 
 */
const unsigned int LDR_PIN = A0; // LDR è collegato ad un PIN analogico
const unsigned int LED_PIN = 9; // PIN collegato al LED
const unsigned int THRESHOLD = 510; // valore soglia per lo spegnimento del LED

int value; // Valore del sensore (0-1023)

void setup(){
    pinMode(LED_PIN, OUTPUT); // PIN collegato al LED
    pinMode(LDR_PIN, INPUT); // PIN collegato al sensore LDR
}

void loop(){
    value = analogRead(pResistor);
    
    if (value > THRESHOLD){
        digitalWrite(ledPin, LOW);  // Spegni il LED
    } else {
        digitalWrite(ledPin, HIGH); // Accendi il LED
    }
    
    delay(500);
}