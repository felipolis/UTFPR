#define debounceInterval 50 // ms
unsigned int debounceTime = 0;
unsigned int debounceTime2 = 0;


int lastState = 0;
int lastState2 = 0;

int botao = 0; // estado do botao
int botao2 = 0; // estado do botao

int posicao = 0;

void setup()
{
    DDRD |= (1 << PD7);
    DDRB |= (1 << PB0);
    DDRC |= (1 << PC5);

    DDRD &= ~(1 << PD2) & ~(1 << PD3);

    PORTD |= (1 << PD2) | (1 << PD3);
}

void loop()
{
    // Acendendo os leds da esquerda para a direita
    int leitura = PIND & (1 << PD2);

    if (leitura != lastState){
        debounceTime = millis();
    }

    if ((millis() - debounceTime) > debounceInterval){
        if (botao != leitura){
            botao = leitura;
            if (botao == 0){
                if (posicao == 0){          // Quando não tiver nenhum aceso
                    PORTB ^= (1 << PB0);    // acende o led1

                    PORTC = ~(1 << PC5);    // apaga o led3
                    PORTD = ~(1 << PD7);    // apaga o led2

                    posicao++;
                }

                else if (posicao == 1){    // Quando o led1 estiver aceso
                    PORTD ^= (1 << PD7);    // acende o led2

                    PORTB = ~(1 << PB0);    // apaga o led1
                    PORTC = ~(1 << PC5);    // apaga o led3

                    posicao++;            // proxima posicao
                }

                else if (posicao == 2){    // Quando o led2 estiver aceso
                    PORTC ^= (1 << PC5);    // acende o led3

                    PORTD = ~(1 << PD7);    // apaga o led2
                    PORTB = ~(1 << PB0);    // apaga o led1

                    posicao++;
                }

                else if (posicao == 3){    // Quando o led3 estiver aceso
                    PORTB ^= (1 << PB0);    // acende o led1

                    PORTD = ~(1 << PD7);    // apaga o led3
                    PORTC = ~(1 << PC5);    // apaga o led2

                    posicao++;
                    if(posicao == 4){
                        posicao = 1;
                    }
                }
            }
        }
    }

    lastState = leitura;

    // Acendendo os leds da direita para a esquerda
    int leitura2 = PIND & (1 << PD3);

    if (leitura2 != lastState2){
        debounceTime2 = millis();
    }

    if ((millis() - debounceTime2) > debounceInterval){
        if (botao2 != leitura2){    //
            botao2 = leitura2;
            if (botao2 == 0){
                if (posicao == 0){
                    PORTC ^= (1 << PC5);    // Acende o led3

                    PORTD = ~(1 << PD7);    // Apaga o led2
                    PORTB = ~(1 << PB0);    // Apaga o led1

                    posicao--;
                    if(posicao == -1){
                        posicao = 3;
                    }
                }

                else if (posicao == 3){
                    PORTD ^= (1 << PD7);    // Acende o led2

                    PORTB = ~(1 << PB0);    // Apaga o led1
                    PORTC = ~(1 << PC5);    // Apaga o led3

                    posicao--;
                }

                else if (posicao == 2){
                    PORTB ^= (1 << PB0);    // Acende o led1

                    PORTD = ~(1 << PD7);    // Apaga o led2
                    PORTC = ~(1 << PC5);    // Apaga o led3

                    posicao--;
                }

                else if (posicao == 1){
                    PORTC ^= (1 << PC5);    // Acende o led3

                    PORTD = ~(1 << PD7);    // Apaga o led2
                    PORTB = ~(1 << PB0);    // Apaga o led1

                    posicao--;
                    if(posicao == 0){
                        posicao = 3;
                    }
                }
            }
        }
    }
    lastState2 = leitura2;
}