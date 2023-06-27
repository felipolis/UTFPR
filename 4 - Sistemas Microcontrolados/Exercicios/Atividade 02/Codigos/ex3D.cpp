// Ligue sequencialmente 1 LED da esquerda para a direita e vice-versa (vai e volta), só um LED deve ser ligado por vez.

void setup()
{
  DDRD = 0b11111111;
}

void loop(){
    PORTD = 0b11111111;
    
    // Direita para a esquerda
    for(int i = 0; i < 8; i++){
        PORTD = ~(1 << i);
        _delay_ms(300);
    }

    // Esquerda para a direita
    for(int i = 6; i >= 0; i--){
        PORTD = ~(1 << i);
        _delay_ms(300);
    }

}