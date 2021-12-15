	.data 
	.text 
	.globl main 
main:	lw $t2,0($zero)
      lw $t3,4($zero)
		add $t1,$t2,$t3
		sw $t1,8($zero)
exit:	beq $zero,$zero,exit
