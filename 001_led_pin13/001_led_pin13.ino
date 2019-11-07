/**
 * MIT License - Copyright (c) 2019 Giuseppe Caliendo
 * 
 * Accensione e spegnimento del LED 13
 */
const unsigned int LED_PIN = 13;

void setup() {
  // imposto il LED come output, di default i pin sono in modalita' INPUT
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // accendi il LED
  digitalWrite(LED_PIN, HIGH);
  // aspetta 1 secondo
  delay(1000);
  // spegni il LED  
  digitalWrite(LED_PIN, LOW);
  // aspetta un secondo
  delay(1000);
}
