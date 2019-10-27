/**
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 * Esercizio #2 Uso di un potenziometro su una uscita
 * analogica. Sfruttando il valore rilevato dal potenziometro
 * pilotare la velocita' del gioco di accensione di 10
 * LED in linea in stile KITT di supercar.
 */
int delayTime = 100; // tempo di attesa letto dal potenziometro
int currentLED = 4; // contiene la posizione del LED corrente
int dir = 1; // indica la direzione del prossimo LED da accendere
long timeChanged = 0; // tempo alla fine del loop
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // lista di LED usati
int lengthPin = 10; // PIN del potenziometro

String directionMsg = "DIR: "; // messaggio di log
String delayMsg = "DELAY: "; // messaggio di log

void setup() {
  // tutti i PIN della lista sono impostati in modalita' uscita
  for (int i = 0; i < lengthPin; i++) {
    pinMode(ledPin[i], OUTPUT);
  }

  //vci mettiamo in ascolto della seriale
  Serial.begin(9600);
  while (!Serial) {
    // no-op
  }

  // ci segnamo il tempo corrente in millisecondi 
  timeChanged = millis();
}

void loop() {
  // se abbiamo aspettato abbastanza allora ripetiamo il ciclo
  if ((millis() - timeChanged) > delayTime) {

    // spegniamo tutti i LED
    for (int i = 0; i < lengthPin; i++) {
      digitalWrite(ledPin[i], LOW);
    }
    
    // accendiamo il LED corrent
    digitalWrite(ledPin[currentLED], HIGH);

    // calcoliamo il prossimo LED corrente
    currentLED = currentLED + dir;

    // se il prossimo LED corrente e' all'estremo della lista 
    // allora invertiamo direzione per il prossimo giro
    if (currentLED == (lengthPin - 1)) {
      dir = -1;
      String msg = directionMsg + dir;
      // scrivo un messaggio di log per indicare la direzione corrente
      Serial.println(msg);
    }

    // se il prossimo LED corrente e' in posizione zero 
    // allora invertiamo direzione per il prossimo giro
    if (currentLED == 0) {
      dir = 1;
      String msg = directionMsg + dir;
      Serial.println(msg);
    }

    // ci segnamo il tempo corrente
    timeChanged = millis();
  }

  // imposto il tempo da aspettare con il valore letto dal potenziometro 
  delayTime = analogRead(0);
  // scrivo un messaggio di log con il valore letto dal potenziometro
  String msg = delayMsg + delayTime;
  Serial.println(msg);
  delay(5);
}
