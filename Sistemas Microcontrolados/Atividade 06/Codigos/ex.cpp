#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL

#define tst_bit(Y, bit_x) 	(Y & (1 << bit_x))
#define set_bit(Y, bit_x) 	(Y |= (1 << bit_x))
#define clr_bit(Y, bit_x) 	(Y &= ~(1 << bit_x))
#define cpl_bit(y, bit) 	(y ^= (1 << bit))

#define LED0 PD5
#define LED1 PD4
#define LED2 PD3

//-------------------------------------------------------------------------------------
ISR(PCINT0_vect); 
ISR(INT0_vect); 


int main(){
  
  UCSR0B = 0x00;
  
  // Pull-up
  DDRB   |= 0x00; 
  PORTB  |= 0xFF;
  
  DDRC   |= 0x00;
  PORTC  |= 0xFF;
  
  DDRD |= 0b00111000;
  PORTD  |= 0b10000100;
  
  //habilita as interrupções dos PCINTs
  PCICR  |= (1<<PCIE0)|(1<<PCIE1)|(1<<PCIE2);
  
  //habilita os pinos específicos para interrupções
  PCMSK0 |= (1<<PCINT1);
  PCMSK1 |= (1<<PCINT11);
  PCMSK2 |= (1<<PCINT23);
  
  //habilita o INT0 na borda de descida
  EICRA  |= (1<<ISC01);
  
  //habilita o INT0 para interrupção
  EIMSK  |= (1<<INT0);
  
  sei();
  //habilita as interrupções
 
  while(1) {};
  return 1;
}

// Botoes unitarios dos leds
ISR(PCINT0_vect) {
	if(!tst_bit(PINB, PB1))
		cpl_bit(PORTD, LED0);
	else if(!tst_bit(PINC,PC3))
		cpl_bit(PORTD,LED1);
	else if(!tst_bit(PIND,PD7))
		cpl_bit(PORTD, LED2);
}

// botao unico dos leds
ISR(INT0_vect) {
  if (
    !tst_bit(PORTD, PD3)
    && !tst_bit(PORTD, PD4)
    && !tst_bit(PORTD, PD5)
  ){
   set_bit(PORTD, PD3);
   set_bit(PORTD, PD4);
   set_bit(PORTD, PD5); 
  }
  else {
   clr_bit(PORTD, PD3);
   clr_bit(PORTD, PD4);
   clr_bit(PORTD, PD5);
  }
}