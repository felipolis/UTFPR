// Ligue sequencialmente 1 LED da esquerda para a direita (o LED deve permanecer ligado até que todos os 8 estejam ligados, depois eles devem ser desligados e o processo repetido).

void setup()
{
  DDRD = 0b11111111;
}

void loop(){

    PORTD = 0b11111111;

    for(int i = 0; i < 8; i++){
        PORTD = PORTD >> 1;
        _delay_ms(300);
    }

}