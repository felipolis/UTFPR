	.data 
	.text 
	.globl main 
main:	addi $t2, $zero, 1
      addi $t3, $zero, 2
		add $t1,$t2,$t3
		sw $t1,8($zero)
exit:	j exit
