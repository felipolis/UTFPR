	# Compilando um procedimento em C que não chama outro procedimento - página 90
	# Adicionado valores nos registradores do exemplo contido no livro
	
	# Assembly para a instrução de atribuição f = (g + h) - (i + j);
	# Consideramos as variáveis g = 4, h = 3, i = 2 e j = 1.
	# No final o registrador $s0 deve conter 4 = (4 + 3) - (2 + 1)
	# As variáveis são associadas aos registradores $s0, $s1, $s2, $s3 e $s4.
	
	.data 
f:	.word 5 	
g:	.word 4
h:	.word 3
i:	.word 2
j:	.word 1

	.text # Itens subsequentes são colocados no segmento de texto.
	.globl main # Declara que o rótulo main é global e pode ser referênciado a partir de outros arquivos

main:	lw $s0, f
	lw $s1, g
	lw $s2, h
	lw $s3, i
	lw $s4, j
	
	# Copia dos valores dos registradores para os argumentos $a0, $a1, $a2 e $a3
	add $a0, $zero, $s1 	# registrador $a0 recebe 0 + $s1 
	add $a1, $zero, $s2 	# registrador $a1 recebe 0 + $s2
	add $a2, $zero, $s3 	# registrador $a2 recebe 0 + $s3
	add $a3, $zero, $s4 	# registrador $a3 recebe 0 + $s4
	
	# Após copiar os valores nos argumentos do procedimento ele é chamado
	jal folha
	
	# No retorno o valor de retorno contido no registrador $v0 é copiado para f ($s0)
	add $s0, $zero, $v0 	# registrador $s0 recebe 0 + $v0 
	sw $s0, f
	
	# O programa é terminado. Exit.
	j exit
	
folha:
	# Precisamos salvar registrador $s0. Empilhamos os valores antigos
	# criando espaço para uma words na pilha e depois armazenamos
	addi $sp, $sp, -4	# ajusta a pilha, criando espaço para 1 item
	sw $s0, 0($sp)		# salva reg. $s0
	
	# As três instuções seguintes correspondem ao corpo do procedimento	
	add $t0, $a0, $a1 	# registrador $t0 contém g + h
	add $t1, $a2, $a3 	# registrador $t1 contém i + j
	sub $s0, $t0, $t1 	# f recebe $t0 - $t1, que é (g + h) - (i + j)
	
	# Para retornar o valor de f, nós o copiamos para um registrador de valor de retorno
	add $v0, $s0, $zero 	# retorna f ($v0 = $s0 + 0)
	
	# Antes de retornar, restauramos o valor antigo do registrador que salvamos, 
	# desempilhando-os.
	lw $s0, 0($sp)		# restaura reg. $s0 para o caller (chamador)
	addi $sp, $sp, 4 	# ajusta pilha para excluir 1 item
	
	# O procedimento termina com um jump register usando o endereço de retorno
	jr $ra 			# desvia de volata à rotina que chamou
	
exit:
