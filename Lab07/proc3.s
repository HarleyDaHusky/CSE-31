.data
x:		.word 1
y:		.word 2
z:		.word 3

.text
MAIN:		la $t0, x
		lw $s0, 0($t0)		# s0 = x
		la $t0, y
		lw $s1, 0($t0)		# s1 = y
		la $t0, z
		lw $s2, 0($t0)		# s2 = z
		
		
		# Prepare to call sum(x)
		add $a0, $zero, $s0	# differentiates $s0 and $a0 for FOO
		add $a1, $zero, $s1
		add $a2, $zero, $s2
		
		jal FOO
		
		add $t0, $s1, $s0 	#t0 = x+y
		add $t0, $t0, $s2	#t0 = (x+y) + z
		add $a0, $s3, $t0 	#a0 = $s3 + $t0
		
		li $v0, 1		 
		syscall	
		j END
		
BAR: 		addi $sp, $sp, -16 # allocate 5 spaces in memory, does not need to save $ra because $ra is returning to foo not main
		sw $v0, 0($sp) # 0 for return value
		sw $a0, 4($sp) # 4 for "a"
		sw $a1, 8($sp) # 8 for "b"
		sw $a2, 12($sp) # 12 for "c"
		
		sub $t7, $a1, $a0 # "b - a"
		sllv  $v0, $t7, $a2  # (b-a) shifted to the left c times

		lw $t1, 0($sp) # load allocated slot 0 into $t1
		lw $a0, 4($sp) # load allocated slot 4 into $a0
		lw $a1, 8($sp) # load allocated slot 8 into $a1
		lw $a2, 12($sp) # load allocated slot 12 into $a2

		addi $sp, $sp 16 # unallocated memory 
   		jr $ra
   	
FOO:		addi $sp, $sp -20 # allocate 6 spaces in memory, needs to save $ra because $ra is modified when function calls BAR, if BAR is not called, $ra does not need to be saved.
		sw $v0, 0($sp)	# 0 for return value
		sw $a0, 4($sp)	# 4 for m = a
		sw $a1, 8($sp)	# 8 for n = b
		sw $a2, 12($sp)	# 12 for o = c
		sw $ra, 16($sp) # 20 for $ra (address to return to main)

		add $t0, $a0, $a2 # m + o 
		add $t1, $a1, $a2 # n + o 
		add $t2, $a0, $a1 # m + n 

		sub $t3, $a0, $a2 # m - o
		sub $t4, $a1, $a0 # n - m
		add $t5, $a1, $a1  # n + n

		move $a0, $t0 # m = m+o
		move $a1, $t1 # n = n+o
		move $a2, $t2 # o = m+n

		jal BAR # p, $ra is changed due to this call
			
		move $a0, $t3 # m = m-o
		move $a1, $t4 # n = n-m
		move $a2, $t5 # o = n+n

		jal BAR # q

		lw $s3, 0($sp) # loads the return value to $s3 from stored address 0
		lw $a0, 4($sp) # loads $a0 with stored address 4 (m = a)
		lw $a1, 8($sp) # loads $a1 with stored address 8 (n = b)
		lw $a2 12($sp) # loads $a2 with stored address 12 (o = c)	
		lw $ra 16($sp) # loads $ra with stored address 20 (address of main to return to main)
		
		add $s3, $t0, $v0

		addi $sp, $sp, 20 # unallocates the 6 slots of memory
		
		jr $ra
		
END:		li $v0, 10 
		syscall