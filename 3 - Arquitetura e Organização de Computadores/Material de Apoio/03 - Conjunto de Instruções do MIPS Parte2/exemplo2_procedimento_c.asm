	# Compilando um procedimento em C que chama outro procedimento recursivo - página 92
	# Adicionado valores nos registradores do exemplo contido no livro
	
	# int fatorial(int n)
	#{
	#    if (n < 1) return f;.
	#    else return n * fact(n - 1);
	# }
	# Argumento n em $a0
	# Resultado em $v0
	
	.data 	     
	.text
	.globl main 
main:	addi $s0, $zero, 0 # registrador $s0 recebe 0 + o valor imediato 0 (f = 0)
       	addi $s1, $zero, 1 # registrador $s0 recebe 0 + o valor imediato 0 (n = 1)
	add $a0, $zero, $s1 # registrador $a0 recebe 0 + $s1 
	# Após copiar os valores nos argumentos do procedimento ele é chamado
	jal fatorial
	add $s0, $zero, $v0 # registrador $s0 recebe 0 + $v0 (f = $v0)
	# O programa é terminado. Exit.
	j exit

 
fatorial:
        	addi $sp, $sp, -8
        	sw $ra, 4 ($sp)
        	sw $a0, 0 ($sp)
       	slti $t0, $a0, 1
        	beq $t0, $zero, L1
        	addi $v0, $zero, 1
        	addi $sp, $sp, 8
        	jr $ra
 
L1:
        	addi $a0, $a0, -1
        	jal fatorial
 
        	lw $a0, 0 ($sp)
        	lw $ra, 4 ($sp)
        	addi $sp, $sp, 8
        	mul $v0, $a0, $v0
        	jr $ra

exit:
      
