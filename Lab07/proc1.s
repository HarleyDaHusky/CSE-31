        .data
m: 		.word 10
n: 		.word 5

		.text
MAIN:	la $t0, m			# Load address of m
		lw $a0, 0($t0)		# a0 = m
		la $t0, n			# Load address of n
		lw $a1, 0($t0)		# a1 = n
	
		addi $ra,$zero, 0x00400028	# Replace 0 with a correct return address 
		add $v0, $a0, $a1
		
		addi $a0, $v0, 0	# Print out result
		li $v0, 1		 
		syscall	
		
		j END

#SUM:	add $v0, $a0, $a1
		#jr $ra
		

		
END:
