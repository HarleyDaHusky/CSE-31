		.data
x:		.word 5
y:		.word 10
m:		.word 15
b:		.word 2

		.text
MAIN:	la $t0, x
		lw $s0, 0($t0)		# s0 = x
		la $t0, y
		lw $s1, 0($t0)		# s1 = y
		
		# Prepare to call sum(x)
		add $a0, $zero, $s0	# Set a0 as input argument for SUM
		jal SUM
		add $t0, $s1, $s0
		add $s1, $t0, $v0
		addi $a0, $s1, 0 
		li $v0, 1		 
		syscall	
		j END

		
SUM: 	la $t0, m
		addi $sp, $sp, -12 #allocates 3 slots in memory, 0,4,8
		sw $a0, 0($sp) 	#Saves $a0 as a backup in 0
		sw $s0, 4($sp)	#Saves $s0 as a backup in 4
		sw $ra, 8($sp)	#Saves $ra as a backupin 8
		lw $s0, 0($t0)		# s0 = m
		
		add $a0, $s0, $a0	# Update a0 as new argument for SUB
		
		jal SUB
		
		lw $a0, 0($sp)  #calls $a0 stored in memory
		lw $s0, 4($sp)	#calls $s0 stored in memory
		lw $ra, 8($sp)	#calls $ra stored in memory
		
		addi $sp, $sp, 12 	#deallocates memory
		add $v0, $a0, $v0 	#sets argument as a value
		jr $ra		
		
SUB:	la $t0, b
		addi $sp, $sp -4	# allocates one spot in memory 
		sw $s0, 0($sp)		# Saves $s0 as a backup
		lw $s0, 0($t0)		# s0 = b
		
		sub $v0, $a0, $s0	
		
		lw $s0, 0($sp)		# calls $s0 stored in memory
		addi $sp, $sp 4		# unallocates the memory
		jr $ra

		
END:
