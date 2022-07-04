#define F_CPU = 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

#define cpl_bit(y,bit) (y^=(1<<bit)) //troca o estado lógico do bit x da variável Y

#define LED0 PB5
#define LED1 PB4
#define LED2 PB3

ISR(TIMER0_COMPA_vect){ 
 cpl_bit(PORTB,LED0); 
}

ISR(TIMER1_COMPA_vect){
  cpl_bit(PORTB,LED1);
}

ISR(TIMER2_COMPA_vect){
  cpl_bit(PORTB,LED2);
}

int main(){
  
	
  DDRB = 0b00111000;     //somente pino do LED como saída
  PORTB = 0b11000111;    //apaga LED e habilita pull-ups nos pinos não utilizados 
  
  //Timer 0
  TCCR0A = 0b01000000;
  
  OCR0A = 155;
  TCCR0B = (1<<CS02) | (1<<CS00); // TC0 com prescaler de 1024, a 100Hz	
  TIMSK0 = 1<<OCIE0A;		//habilita a interrupção do TC0 
  
  
  //Timer 1
  TCCR1A = 0b01000000;

  OCR1A = 15592;
  TCCR1B = (1<<CS11) | (1<<CS10); // TC1 com prescaler de 1024, a 1.00200401Hz	
  TIMSK1 = 1<<OCIE1A;		//habilita a interrupção do TC1
  
  
  //Timer 2
  TCCR2A = 0b01010011;

  OCR2A = 39061;
  TCCR2B = (1<<CS22) | (1<<CS21) | (1<<CS20); // TC2 com prescaler de 1024, a 0.4Hz
  TIMSK2 = 1<<OCIE2A;		//habilita a interrupção do TC2 
  
  
  sei();
  
  while(1){};
  
}