        .data
 evenSum: .word 0
 oddSum: .word 0
str1: .asciiz "Please enter a number: \n"
str2: .asciiz "\nSum of even numbers is: "
str3: .asciiz "\nSum of odd numbers is: "

        .text
       	li $v0, 4         # service 4 is print string
    	la $a0, str1  # load desired value into argument register $a0, using pseudo-op
    	syscall	
        
        li $v0, 5 # service 5 is user inputs
	syscall
	move $s1, $v0

	rem $t1, $s1, 2
	bne $t1, 0, odd
	beq $t1, 0, even

while: 	beq $v0, $zero, print
	li  $v0, 4         # service 4 is print string
    	la $a0, str1  # load desired value into argument register $a0, using pseudo-op
    	syscall	
        
        li $v0, 5
	syscall
	move $s1, $v0
	
	rem $t1, $s1, 2
	bne $t1, 0, odd
	beq $t1, 0, even
	
	j while

even: 	add    $t6, $t6, $s1
	j while
	
odd:	add    $t7, $t7, $s1
	j while

print: 	li  $v0, 4         # service 1 is print string
    	la $a0, str2  # load desired value into argument register $a0, using pseudo-op
   	syscall	
	
	li  $v0, 1         # service 1 is print integer
    	la $a0, ($t6) 
	syscall
	
	li $v0, 4
	la $a0, str3	
	syscall	
	
	li  $v0, 1         # service 1 is print integer
    	la $a0, ($t7)
    	syscall
	
	li $v0, 10
	syscall