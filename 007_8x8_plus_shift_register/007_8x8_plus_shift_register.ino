/**
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 * Matrice di LED 8x8 per disegnare uno smile.
 * 
 * La seguente soluzione accende un solo LED alla volta ma sfrutta
 * la frequenza del microcontrollore di Arduino per dare l'effetto
 * di un'immagine statica. Sfruttiamo un registro a scorrimento per
 * pilotare le colonne e risparmiare delle porte sulla piattaforma
 * Arduino.
 */
const unsigned int colPin[] = {10, 11, 12, 13, 14, 15, 16, 17}; // pin delle colonne
const unsigned int latchPin = 5;  // 74HC595 Latch pin 12 connesso al pin digitale 5 di Arduino
const unsigned int clockPin = 6; // 74HC595 Clock pin 11 connesso la pin digitale 6 di Arduino
const unsigned int dataPin = 4;  // 74HC595 Data pin 14 connesso al pin digitale 4 di Arduino
const byte zero = 0;    // zero byte per cancellare l'intera riga

// sprite da visualizzare
cost byte smile[] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};


void setup() {
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Set all columns pins to be OUTPUTs
  for (int i = 0; i < 8; i++) { 
    pinMode(colPin[i], OUTPUT);
  }
}

void loop() {
  // count indica quale byte dell'array dello sprite è il corrente
  for(int count = 0; count < 8; count ++){

    // spegniamo tutte le righe
    updateShiftRegister(zero);
    
    for(int i = 0; i < 8; i++){
      // attiviamo la colonna di indice count
      if(i == count){
        digitalWrite(colPin[i], LOW);
      } else{
        // e inibiamo le altre colonne
        digitalWrite(colPin[i], HIGH);
      }
    }

    for(int row = 0; row < 8; row++){
      // controlla se la riga di indice row 
      // della colonna di indice count deve 
      // essere accesa o no
      int bit = (smile[count] >> row) & 1;
      if(bit == 1){
        updateShiftRegister(smile[count]);
      }
    }
    
  }
}

void updateShiftRegister(byte row)
{
  // avvisiamo il registro che stiamo per mandargli un nuovo byte
  digitalWrite(latchPin, LOW);
  // grazie a questa funzione mandiamo al registro l'intero byte
  // senza preoccupoarci di mandare un bit alla volta
  shiftOut(dataPin, clockPin, LSBFIRST, row);
  // avvisiamo il registro che abbiamo finito di mandargli il byte
  digitalWrite(latchPin, HIGH);
}