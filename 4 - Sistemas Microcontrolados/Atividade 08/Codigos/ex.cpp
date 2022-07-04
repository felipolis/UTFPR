#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 
#include <avr/pgmspace.h>

//Definições de macros
#define	set_bit(Y,bit_x) (Y|=(1<<bit_x))	
#define	clr_bit(Y,bit_x) (Y&=~(1<<bit_x))	
#define tst_bit(Y,bit_x) (Y&(1<<bit_x))  	
#define cpl_bit(Y,bit_x) (Y^=(1<<bit_x))

#define TOP 39999
#define BOTAO1 PB0
#define BOTAO2 PB2

#define DISPLAY   PORTD
#define D1 PB3
#define D2 PB4
#define D3 PB5

const unsigned char Tabela[] PROGMEM = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x18, 0x08, 0x03, 0x46, 0x21, 0x06, 0x0E};

int deslocamento = 200;
float grausDeslocamento = 9;

ISR(PCINT0_vect);
void escreveDisplay();

int main()
{ 
  Serial.begin(300);
  
  DDRB  = 0b11111010;
  PORTB = 0b00000101;
  DDRD = 0xFF;
  PORTD= 0xFF;
  UCSR0B = 0x00;
  
  
  ICR1 = TOP;
  
  TCCR1A = (1<<WGM11);
  
  
  TCCR1B = (1<<WGM13) | (1<<WGM12) | (1 << CS11);
  set_bit(TCCR1A,COM1A1); 
  OCR1A = 1000;

  
  PCICR = 1<<PCIE0;
  PCMSK0 = (1<<PCINT0)|(1<<PCINT2);
  
  sei();
  while(1){
    unsigned char valorGrau = ((OCR1A-1000)/deslocamento)*grausDeslocamento;  
    char d1 = 0, d2 = 0, d3 = 0; 
    if (valorGrau<10) {
       d1 = valorGrau;
       d2 = 0;
       d3 = 0;
    }else if(valorGrau<100) {
       d3 = 0;
       d2 = valorGrau/10;
       d1 = valorGrau%10;
    }else{
       d3 = valorGrau/100;
       d2 = (valorGrau/10)%10;
       d1 = valorGrau%10;
    }
    
    if (d3 >= 0) {
      clr_bit(PORTB,D2);
      clr_bit(PORTB,D1); 
      DISPLAY = pgm_read_byte(&Tabela[d3]); 
      set_bit(PORTB,D3);      
      _delay_ms(2);
    }
    if (d2 >= 0) {
      clr_bit(PORTB,D3);       
      clr_bit(PORTB,D1); 
      DISPLAY = pgm_read_byte(&Tabela[d2]); 
      set_bit(PORTB,D2);
      _delay_ms(2);
    }
  	clr_bit(PORTB,D2);
  	clr_bit(PORTB,D3);
  	DISPLAY = pgm_read_byte(&Tabela[d1]);
  	set_bit(PORTB,D1);
  	_delay_ms(2);
  }
}

ISR(PCINT0_vect){
  	if(!tst_bit(PINB, BOTAO1)){
      if(OCR1A < 5000){
    	OCR1A +=deslocamento;
      }

    }if(!tst_bit(PINB, BOTAO2)){
      if(OCR1A > 1000){
    	OCR1A -=deslocamento;
      }

    }
}