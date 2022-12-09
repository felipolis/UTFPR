"""
************* Tempo de Jogo com Minutos *************

Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.

Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XX HORA(S) E YY MINUTO(S)” .

----------------------------------------------------------------
Exemplo de Entrada      Exemplo de Saída
7 8 9 10                O JOGO DUROU 2 HORA(S) E 2 MINUTO(S)
7 7 7 7                 O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)
7 10 8 9                O JOGO DUROU 0 HORA(S) E 59 MINUTO(S)
----------------------------------------------------------------

"""

hora_inicial, minuto_inicial, hora_final, minuto_final = map(int, input().split())

minuto_inicial = minuto_inicial + (hora_inicial * 60)
minuto_final = minuto_final + (hora_final * 60)

tempo = minuto_final - minuto_inicial

if tempo <= 0:
    tempo = tempo + 24 * 60

h = tempo // 60
m = tempo % 60

print("O JOGO DUROU {} HORA(S) E {} MINUTO(S)".format(h, m))





