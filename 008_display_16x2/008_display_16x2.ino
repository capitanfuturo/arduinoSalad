/*
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 *
 * Utilizzo di un display LCD 16x2 LCD display con l'aiuto della libreria 
 * LiquidCrystal compatibile con gli Hitachi HD44780. 
 */
#include <LiquidCrystal.h>

const unsigned int RS = 12;
const unsigned int EN = 11;
const unsigned int D4 = 5;
const unsigned int D5 = 4;
const unsigned int D6 = 3;
const unsigned int D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  // imposto le dimensioni del display colonne x righe
  lcd.begin(16, 2);
  // pulisco il display
  lcd.clear();
  // inizializzo la comunicazione seriale con banda 9600
  Serial.begin(9600);
}

void loop() {
  // creo un effetto blink del cursore

  // spengo il cursore
  lcd.noCursor();
  delay(500);
  // accendo il cursore
  lcd.cursor();
  delay(500);
  
  if (Serial.available()) {
    // aspetto l'arrivo dell'intero messaggio
    delay(100);
    // pulisco il display
    lcd.clear();
    // leggo tutti i caratteri dalla seriale
    while (Serial.available() > 0) {
      // leggo il messaggio
      String msg = Serial.readString();
      // salvo la lunghezza del messaggio
      unsigned int msgLength = msg.length();
      // lo stampo come ECHO sul monitor seriale di Arduino
      Serial.println(msg);
      // inizializzo una variabile da usare quando finirò le 16 colonne
      // del display 
      unsigned int pos = 0; 
      
      // scorro carattere per carattere il messaggio
      for (int thisChar = 0; thisChar < msgLength; thisChar++) {
        // stampo il carattere i-esimo
        lcd.print(msg.charAt(thisChar));
        delay(250);
        // se sono giunto alla fine delle colonne parto con lo scroll a sinistra
        if(pos > 16){
          lcd.scrollDisplayLeft();  
        } else {
          // altrimenti incremento il puntatore
          pos++;
        }
      }
    }// fine while
  }// fine attesa della porta seriale
}
