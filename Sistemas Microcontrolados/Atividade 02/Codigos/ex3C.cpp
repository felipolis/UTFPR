//Ligue sequencialmente 1 LED da direita para a esquerda, desta vez somente um LED deve ser ligado por vez.

void setup()
{
  DDRD = 0b11111111;
}

void loop(){
    
    PORTD = 0b11111111;

    for(int i = 0; i < 8; i++){
        PORTD = ~(1 << i);
        _delay_ms(300);
    } 
    
}