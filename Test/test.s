.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
li $v0, 4
la $a0, _prompt
syscall
li $v0, 5
syscall
jr $ra
write:
li $v0, 1
syscall
li $v0, 4
la $a0, _ret
syscall
move $v0, $0
jr $ra

main:
sw $30, -8($29)
move $30, $29
sw $31, -4($30)
lw $15, -12($30)
li $15, 0
lw $14, -16($30)
move $14, $15
lw $13, -20($30)
li $13, 1
lw $12, -24($30)
move $12, $13
lw $11, -28($30)
li $11, 0
lw $10, -32($30)
move $10, $11
lw $9, -36($30)
lw $8, -40($30)
move $9, $8
label1:
sw $10, -32($30)
lw $10, -44($30)
sw $10, -44($30)
lw $10, -48($30)
move $10, $10
sw $10, -48($30)
lw $10, -52($30)
sw $10, -52($30)
lw $10, -56($30)
move $10, $10
sw $10, -56($30)
lw $10, -44($30)
sw $10, -44($30)
lw $10, -52($30)
blt $10, $10, label2
j label3
label2:
sw $10, -52($30)
lw $10, -60($30)
sw $10, -60($30)
lw $10, -64($30)
move $10, $10
sw $10, -64($30)
lw $10, -68($30)
sw $10, -68($30)
lw $10, -72($30)
move $10, $10
sw $10, -72($30)
lw $10, -76($30)
sw $10, -76($30)
lw $10, -60($30)
sw $10, -60($30)
lw $10, -68($30)
add $10, $10, $10
sw $10, -68($30)
lw $10, -80($30)
sw $10, -80($30)
lw $10, -76($30)
move $10, $10
sw $10, -76($30)
lw $10, -84($30)
sw $10, -84($30)
lw $10, -88($30)
move $10, $10
sw $10, -88($30)
lw $10, -92($30)
sw $10, -92($30)
lw $10, -96($30)
move $10, $10
sw $10, -96($30)
lw $10, -100($30)
sw $10, -100($30)
lw $10, -92($30)
move $10, $10
sw $10, -92($30)
lw $10, -104($30)
sw $10, -104($30)
lw $10, -108($30)
move $10, $10
sw $10, -108($30)
lw $10, -112($30)
sw $10, -112($30)
lw $10, -104($30)
move $10, $10
sw $10, -104($30)
lw $10, -116($30)
sw $10, -116($30)
lw $10, -120($30)
move $10, $10
sw $10, -120($30)
lw $10, -124($30)
li $10, 1
sw $10, -124($30)
lw $10, -128($30)
sw $10, -128($30)
lw $10, -116($30)
sw $10, -116($30)
lw $10, -124($30)
add $10, $10, $10
sw $10, -124($30)
lw $10, -132($30)
sw $10, -132($30)
lw $10, -128($30)
move $10, $10
j label1
label3:
sw $10, -128($30)
lw $10, -136($30)
li $10, 0
move $2, $10
jr $ra
