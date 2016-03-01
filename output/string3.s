.globl sub
	.type sub,@function
sub:
	enter $260,$0
	pushl $128
	pushl 8(%ebp)
	leal -128(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	pushl $128
	pushl $.s0
	leal -260(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	movl 12(%ebp),%eax
	movl %eax,-132(%ebp)
	.loop0:
	movl -132(%ebp),%eax
	cmpl 16(%ebp),%eax
	jg .skip0
	pushl -132(%ebp)
	leal -128(%ebp),%eax
	pushl %eax
	call get_char_at
	addl $8, %esp
	andw $0xff,%ax
	movw %ax,.stracc
	subl $128,%esp
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
	leal -260(%ebp),%eax
	pushl %eax
	push $.stracc
	call strcpy
	addl $8,%esp
	pushl %esp
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	addl $128,%esp
	pushl $128
	pushl $.stracc
	leal -260(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	movl -132(%ebp),%eax
	addl $1,%eax
	movl %eax,-132(%ebp)
	jmp .loop0
	.skip0:
	pushl $128
	leal -260(%ebp),%eax
	pushl %eax
	pushl $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	movl $.stracc,%eax
	jmp .sub_ret
.sub_ret:
	leave
	ret

.globl invert
	.type invert,@function
invert:
	enter $128,$0
	pushl $128
	pushl 8(%ebp)
	leal -128(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal -128(%ebp),%eax
	pushl %eax
	pushl $.s1
	call strcmp
	addl $8,%esp
	cmpl $0,%eax
	jne .no1
	pushl $128
	pushl $.s2
	pushl $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	movl $.stracc,%eax
	jmp .invert_ret
	.no1:
	subl $128, %esp
	leal -128(%ebp),%eax
	pushl %eax
	call strlen
	addl $4, %esp
	subl $1,%eax
	pushl %eax
	pushl $1
	leal -128(%ebp),%eax
	pushl %eax
	call sub
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $12, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	subl $128,%esp
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
	pushl $0
	leal -128(%ebp),%eax
	pushl %eax
	call get_char_at
	addl $8, %esp
	andw $0xff,%ax
	movw %ax,.stracc
	push $.stracc
	pushl %esp
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl %esp
	push $.stracc
	call strcpy
	movb $0,127(%eax)
	addl $8,%esp
	addl $128,%esp
	movl $.stracc,%eax
	jmp .invert_ret
.invert_ret:
	leave
	ret

.globl main
	.type main,@function
main:
	enter $256,$0
	pushl $128
	pushl $.s3
	leal -128(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	pushl $128
	pushl $.s4
	leal -256(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	subl $128, %esp
	pushl $128
	leal -128(%ebp),%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	leal -256(%ebp),%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	subl $128,%esp
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
	subl $128, %esp
	pushl $128
	leal -256(%ebp),%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	leal -128(%ebp),%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	push $.stracc
	pushl %esp
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl %esp
	push $.stracc
	call strcpy
	movb $0,127(%eax)
	addl $8,%esp
	addl $128,%esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call printf
	addl $132, %esp
	subl $128, %esp
	subl $128, %esp
	subl $128, %esp
	subl $128, %esp
	subl $128, %esp
	subl $128, %esp
	subl $128, %esp
	subl $128, %esp
	leal -256(%ebp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $4, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call invert
	pushl $128
	pushl %eax
	pushl $.stracc
	call strncpy
	addl $12, %esp
	movl $.stracc,%eax
	movb $0,127(%eax)
	addl $132, %esp
	pushl $128
	pushl $.stracc
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call printf
	addl $132, %esp
	movl $0,%eax
	jmp .main_ret
.main_ret:
	leave
	ret


	.comm .stracc,256,4

.section	.rodata
	.s0:	.string ""
	.s1:	.string ""
	.s2:	.string ""
	.s3:	.string "hello"
	.s4:	.string "world"
