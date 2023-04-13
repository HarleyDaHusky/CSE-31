.data
n:	.word 25
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"

.text
	la $t0, n
	lw $s0, 0($t0)
	
	li $v0, 5
	syscall
	move $s1, $v0
	
	slt $t0, $s1, $s0
	bne $t0, $zero, less
	beq $t0, $zero, greater
	
#greater:	li $v0, 4
#		la $a0, str4
#		syscall
#		j finish

#less:		li $v0, 4
#		la $a0, str1
#		syscall
#		j finish

greater:	li $v0, 4
		la $a0, str3
		syscall
		j finish
		
less:		li $v0, 4
		la $a0, str2
		syscall
		j finish
		
finish:		li $v0, 10
		syscall
		