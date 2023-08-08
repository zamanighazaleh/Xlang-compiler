.globl main
	addi $s0, $zero, 0
	addi $a0, $zero, 12
	li $v0, 9
	syscall
	move $s1, $v0
	addi $a0, $zero, 262140
	li $v0, 9
	syscall
	move $s2, $v0
	addi $s3, $zero, 0
ff:
	addi $s4, $zero, 0
	addi $a0, $zero, 2 
	addi $a1, $zero, 2 
	addi $a2, $zero, 2 
	addi $a3, $zero, 2 
	addi $t0,$zero,10
	slt $t0,$t0,$s4
	beq $t0, $zero, L1
	addi $s5, $zero, 0
L1:
	addi $a0, $zero, 10 
	jr $ra
func:
	sll $t1,$a1,2
	add $t1,$t1,$s1
	lw $t1,0($t1)
	move $a0, $t1
	addi $t1, $zero , 3
	sw $t1, 8($s1)
	add $t1,$a0,$a1
	move $v0, $t1 
	jr $ra
main:
	addi $s6, $zero, 0
	addi $s7, $zero, 0
	addi $, $zero, 0
	lw $t1,8($s1)
	addi $t2,$t1,3
	sw $t2, 4($s1)
	addi $s6,$zero,0
LOOP1:
	addi $t1,$zero,5
	slt $t1,$s6,$t1
	xori $t1,$t1,1
	beq $t1,$zero,L2
	j L2
	j Loop1
	add $t2,$s7,$s6
	move $, $t2
	addi $,$s6,1
	move $s6,$
	j LOOP1
L2:
	beq 1, $zero, L3
	add $t2,$s7,$s6
	move $, $t2
	j L4
L3:
	add $t2,$s7,$s6
	move $, $t2
L4 : 
	addi $t2,$s6,4
	move $, $t2
	addi $t2,$zero,8
	mul $t2,$s6,8
	div $t3,$t2,$s0
	add $t2,$,$t3
	move $s7, $t2
	addi $a0,$zero,1
	addi $a1,$zero,2
	addi $a2,$zero,3
	addi $a3,$zero,4
	jal ff
	move $s6, $s6
	add $t2,$s7,$s6
	move $s7, $t2
	addi $a0,$zero,3
	addi $a1,$zero,5
	jal func
	move $s6, $v0
	addi $s0,$zero,1
LOOP2:
	addi $t2,$zero,3
	slt $t2,$s0,$t2
	xori $t2,$t2,1
	beq $t2,$zero,L5
	addi $, $zero, 0
	beq 1, $zero, L6
	j Loop2
L6:
	addi $t2,$s0,1
	move $s0,$t2
	j LOOP2
L6:
	addi $s6,$zero,1
LOOP3:
	addi $t3,$zero,10
	slt $t3,$s6,$t3
	xori $t3,$t3,1
	beq $t3,$zero,L7
	addi $s7, $s7, 1 
	addi $s7,$s6,1
	move $s6,$s7
	j LOOP3
L7:
	addi $a0,$zero,12
	call "itoa"
	addi $t4,$zero,10
	slt $t4,$t4,$s6
	beq $t4, $zero, L8
	addi $, $zero, 0
	addi $s7, $zero, 10 
	j L9
L8:
	addi $s7, $zero, 9 
L9 : 
	li $v0, 10
	syscall
