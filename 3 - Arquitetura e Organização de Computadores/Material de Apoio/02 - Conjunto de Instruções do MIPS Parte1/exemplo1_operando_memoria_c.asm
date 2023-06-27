	# Compilando uma atribuição quando um operando está na memória - página 65
	# Adicionado valores nos registradores e vetor do exemplo contido no livro
	
	# Assembly para a instrução de atribuição g = h + A[8];
	# variáveis = registradores g= $s1, h= $s2, endereço base do vetor a= $s3.
	# Consideramos as variáveis g = 0, h = 3.
	# Consideramos a[]={13,12,11,10,9,8,7,6,5,4,3,2,1}.
	# g = h + A[8] -> g = 3 + 5 -> g = 8.
	
	
	.data 
a:	.word 13,12,11,10,9,8,7,6,5,4,3,2,1 # Armazena os 13 valores no vetor a[]
g:	.word 0
h:	.word 3
	.text 
	.globl main 
		
main:	lw $s1,g # registrador $s1 recebe 0 + o valor imediato 0 (g = 0)
	lw $s2,h # registrador $s2 recebe 0 + o valor imediato 3 (h = 3)
	la $s3,a # carrega o endereço do rotulo a (endereço base) para o registrador $s3
	
	lw $t0,32($s3) # endereçamento do byte na instrução load word para selecionar a[8]
	add $s1,$s2,$t0 # registrador $s1 recebe h + a[8] 
	sw $s1,g
	
	
	
