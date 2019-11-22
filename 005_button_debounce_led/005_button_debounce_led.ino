/**
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 * 
 * Uso di un pulsante e relativa funzione software
 * di antirimbalzo.
 */
const unsigned int LED_PIN = 13;
const unsigned int BUTTON_PIN = 7;
const unsigned int WAIT_FOR_DEBOUNCE = 50;

int ledStatus = LOW;
int buttonStatus = LOW;
unsigned long debounceTime = 0;
int lastButtonValue = LOW;

void setup(){ 
  pinMode(LED_PIN, OUTPUT); // il pin del led lo usiamo per visualizzare lo stato del pulsante
  pinMode(BUTTON_PIN, INPUT); // il pin del pulsante lo usiamo per leggere lo stato del pulsante
  digitalWrite(LED_PIN, ledStatus); // inizializziamo il pin del led
}

void loop(){  
  int buttonValue = digitalRead(BUTTON_PIN);  // leggiamo lo stato del pulsante
  if(buttonValue != lastButtonValue){ // se lo stato del pin è variato
    debounceTime = millis(); // tengo in memoria l'orario del cambio di stato del pulsante
  }

  if((millis() - debounceTime) > WAIT_FOR_DEBOUNCE){ // se è passato un tempo minimo dall'ultimo cambio di stato
    if(buttonValue != buttonStatus && buttonValue == HIGH){  // se il pin del pulsante ha un valore diverso dalla variabile di stato 
      ledStatus = !ledStatus;                                // cambio lo stato del led
      digitalWrite(LED_PIN, ledStatus);
    }
    buttonStatus = buttonValue; // assegno lo stato del pulsante con il nuovo valore
  }

  lastButtonValue = buttonValue; // assegno all'ultimo valore del pulsante lo stato
  delay(10); // ritardo
}
