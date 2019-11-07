/**
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 * 
 * Uso di un registro a scorrimento a 8 bit per accendere una
 * riga di LED.
 */
const unsigned int latchPin = 5;  // 74HC595 Latch pin 12 connesso al pin digitale 5 di Arduino
const unsigned int clockPin = 6; // 74HC595 Clock pin 11 connesso la pin digitale 6 di Arduino
const unsigned int dataPin = 4;  // 74HC595 Data pin 14 connesso al pin digitale 4 di Arduino

const byte zero = 0;    // zero byte per cancellare la riga di LED

// sprite da visualizzare
const byte smile[] = {
  B00011000,
  B00111100,
  B01111110,
  B11111111,
  B10101010,
  B01010101,
  B11001100,
  B00110011
};

void setup() 
{
  // Impostiamo i PIN del register in modalità OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  // usiamo il monitor seriale per dei messaggi di log
  Serial.begin(9600);
  while (!Serial) {
    // no-op
  }
}

void loop() 
{
  // puliamo l'uscita del registro
  Serial.println(zero,BIN);
  updateShiftRegister(zero);
  delay(500);
  
  // scorro tutti i byte dell'array smile
  for (int i = 0; i < 8; i++)
  {
    // spedisco al registro tutto il byte da accendere
    Serial.println(smile[i], BIN);
    updateShiftRegister(smile[i]);
    delay(500);
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
