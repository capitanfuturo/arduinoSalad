/**
 * MIT License - Copyright (c) 2019 Giuseppe Caliendo
 * 
 * Uso della tecnica PWN per giocare sulla luminosita'
 * di un LED collegato al PIN 11
 */
const unsigned int LED_PIN = 11;

void setup(){}

void loop(){
  /** 
   * aumentiamo ogni 5 millisecondi la larghezza dell'onda
   * quadra sull'uscita digitale 11 finche' non raggiungiamo
   * il massimo valore consentito
   */
  for (int i = 0; i < 255; i++){
    analogWrite(LED_PIN, i);
    delay(5);
  }

  /**
   * come fatto in precedenza solo che diminuiamo il valore 
   * fino allo zero
   */
  for (int i = 255; i >= 0; i--){
    analogWrite(LED_PIN, i);
    delay(5);
  }
}
