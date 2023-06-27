	# Compilando um loop while em C - página 85
	# Suponha que i e k correspondam ao registradores $s3 e $s5 e a base do array save esteja em $s6. i = 0 e k = 0.
	# Assembly para a instrução while (save[i] == k) i += 1;
	
	.data  # 0x10010000
save:	.word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 	# vetor save[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}; 
							
	.text  # 0x00400000
	.globl main 
	
main:	add $s3, $zero, $zero # registrador $s3 recebe 0 + 0 (i = 0)
	add $s5, $zero, $zero # registrador $s5 recebe 0 + 0 (k = 0)

	# Antes que possamos ler save[i] para um registrador temporário, precisamos ter seu endereço
	# Antes que possamos somar i à base do array save para formar o endereço, temos que multiplicar o índice por 4.
	# Podemos usar o deslocamento lógico à esquerda, pois o deslocamento à esquerda de 2 bits multiplica por 4.
	# Precisamos acrescentar o rótulo Loop para podermos desviar de volta a essa instrução no final do loop.
	la $s6,save	   	# carrega o endereço do rotulo save (endereço base array) para o registrador $s6
Loop:	sll $t1, $s3, 2		# registrador temporário $t1 = 4 * i
		
	# Para obter o endereço de save[i], temos que somar $t1 e a base do array save em $s6
	add $t1, $t1, $s6	# $t1 = endereço de save[i]
	
	# Agora, podemos usar esse endereço para ler save[i] para um registrador temporário.
	lw $t0, 0($t1)	# registrador temporário $t0 = save[i]
	
	# A próxima instrução realiza o teste do loop, terminando se save[i] <> k
	bne $t0, $s5, Exit	# vá para Exite se save[i] <> k
	addi $s3, $s3, 1	# i = i + 1
	
	# O final do loop desvia de volta ao teste do while no início do loop. Simplesmente acrescentamos o rótulo Exit
	# depois dele e terminamos.
	j Loop	# vá para Loop
Exit:
	
