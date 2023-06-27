	# void strcpy (char x[], char y[])
	# { int i;
	#  i = 0;
	#  while ((x[i]=y[i])!='\0')
	#    i += 1;
	# }

	.data			

x: 	.asciiz "Ola"		# armazena na memória uma string "Ola" terminada em nulo
y:	.asciiz "   "		# armazena na memória uma string "   " terminada em nulo

	.text			
	.globl main		
main:
	la $a0, x
	la $a1, y
	jal strcpy
				
	li $v0, 10		
	syscall			
	
strcpy:	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $a0, 4($sp)
	sw $a1, 0($sp)

	add $t1, $zero, $zero # i = 0
	
L1:     	add $t2, $zero, $a0
	add $t2, $t2, $t1 # fte[i]      	
	lb $t3, 0($t2)	 #$t3 = fte[i]
	
	add $t2, $zero, $a1
        	add $t2, $t2, $t1 	
	sb $t3, 0($t2)	# dst[i] = fte[i]	
	
	beq $t3, $zero, L2
	addi $t1, $t1, 1	
	j L1			
	
L2:	addi $v0, $t1, 1	
	
	lw $a1, 0($sp)
	lw $a0, 4($sp)
	lw $ra, 8($sp)
	addi $sp, $sp, 12
	
	jr $ra




