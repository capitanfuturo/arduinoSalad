/**
 * MIT License - Copyright (c) 2020 Giuseppe Caliendo
 * Matrice di LED 8x8 per disegnare uno smile.
 * 
 * La seguente soluzione accende un solo LED alla volta ma sfrutta
 * la frequenza del microcontrollore di Arduino per dare l'effetto
 * di un'immagine statica.
 */
const unsigned int rowPin[] = {2,3,4,5,6,7,8,9}; //pin delle righe
const unsigned int colPin[] = {10,11,12,13,14,15,16,17}; // pin delle colonne

// immagine dello smile da visualizzare
const byte smile[] = {
B00111100,
B01000010,
B10100101,
B10000001,
B10100101,
B10011001,
B01000010,
B00111100
};

// setup iniziale
void setup(){
  // impostiamo tutte le uscite in modalita' output
  for(int i = 0; i <8; i++){
    pinMode(rowPin[i], OUTPUT);
    pinMode(colPin[i], OUTPUT);
  }
}

void loop(){
  // mostriamo lo smile in loop continuo
  displaySprite();
}

void displaySprite(){
  // andiamo ad accendere un solo LED alla volta

  // count indica quale byte dell'array smile è il corrente
  for(int count = 0; count < 8; count ++){

    // spegniamo tutte le righe
    for(int i = 0; i < 8; i++){
      digitalWrite(rowPin[i], LOW);
    }
    
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
        digitalWrite(rowPin[row], HIGH);
      }
    }
    
  }
}
