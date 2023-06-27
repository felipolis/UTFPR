
	.data # Itens subsequentes são armazenados no segmento de dados, exe.: variáveis globais, arrays
	      # Neste código o segmento de dados não é utilizado.
	.text # Itens subsequentes são colocados no segmento de texto.
	.globl main # Declara que o rótulo main é global e pode ser referênciado a partir de outros arquivos

main:	addi $s1, $zero, 4 # registrador $s1 recebe 0 + o valor imediato 4
	add  $t2,$s1, $zero  # registrador $t2 recebe $s1 + 0 ($s1 copiado para $t2)
	