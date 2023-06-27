	# Compilando if-then-else em desvios conficionais
	# Adicionado valores nos registradores do exemplo 
	
	# No segmento de código a seguir, f, g, h, i e j são variáveis.
	# As cinco variáveis de f a j correspondem aos cinco registradores de $s0 a $s4.
	# Consideramos as variáveis f = 0, g = 4, h = 3 ,i = -2 e j = 1.
	# Assembly para a instrução if (i<j) f = g + h; else f = g - h;
	# As variáveis são associadas aos registradores $s0, $s1, $s2, $s3 e $s4.
	
	.data 
f:	.word 0 	
g:	.word 4
h:	.word 3
i:	.word -2
j:	.word 1

	.text # Itens subsequentes são colocados no segmento de texto.
	.globl main # Declara que o rótulo main é global e pode ser referênciado a partir de outros arquivos

main:	lw $s0, f
	lw $s1, g
	lw $s2, h
	lw $s3, i
	lw $s4, j 
			
	slt $t0, $s3, $s4	# $t0 = 1 se $s3 (i) < $s4 (j)
	beq $t0, $zero, Else 	# vai par Else se $s3 (i) >= $s4 (j)
	add $s0, $s1, $s2 	# f = g + h (ignorada se i >= j)
	# Agora, precisamos ir até o final da instrução if. Utilizamos o desvio incondicional
	j Exit 			# vá para Exit
Else:	sub $s0, $s1, $s2 	# f = g - h (ignorada se i < j)
Exit:
	
