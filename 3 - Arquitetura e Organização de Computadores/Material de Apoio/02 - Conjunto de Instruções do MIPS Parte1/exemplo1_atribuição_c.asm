	# Compilando uma atribuição em C usando registradores - página 64
	# Adicionado valores nos registradores do exemplo contido no livro
	
	# Assembly para a instrução de atribuição f = (g + h) - (i + j);
	# Consideramos as variáveis g = 4, h = 3, i = 2 e j = 1.
	# No final o registrador $s0 deve conter 4 = (4 + 3) - (2 + 1)
	# As variáveis são associadas aos registradores $s0, $s1, $s2, $s3 e $s4.

	.data # Itens subsequentes são armazenados no segmento de dados, exe.: variáveis globais, arrays
	      # Neste código o segmento de dados não é utilizado.
	.text # Itens subsequentes são colocados no segmento de texto.
	.globl main # Declara que o rótulo main é global e pode ser referênciado a partir de outros arquivos

main:	addi $s1, $zero, 4 # registrador $s1 recebe 0 + o valor imediato 4
	addi $s2, $zero, 3 # registrador $s2 recebe 0 + o valor imediato 3
	addi $s3, $zero, 2 # registrador $s3 recebe 0 + o valor imediato 2
	addi $s4, $zero, 1 # registrador $s4 recebe 0 + o valor imediato 1
	
	add $t0, $s1, $s2 # registrador $t0 contém g + h
	add $t1, $s3, $s4 # registrador $t1 contém i + j
	sub $s0, $t0, $t1 # f recebe $t0 - $t1, que é (g + h) - (i + j)
	
	
