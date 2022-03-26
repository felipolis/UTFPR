
void setup()
{
  DDRB = 0b00100000;
  //DDRB = 1<<5;
  //DDRB = 1<PB5;
  //DDRB = 32;
  //DDRB = 0x20;
  
  DDRB |= 1<<PB2;
  
}

void loop()
{
  PORTB = 0b00100000;
  delay(50);
  
  PORTB = 0b00000100;
  delay(50);
  
  PORTB = 0;
  delay(450);
}