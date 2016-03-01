.globl main
	.type main,@function
main:
	enter $8,$0
	pushl $128
	pushl $.s0
	leal tab,%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	movl $1 ,-4(%ebp)
	.loop0:
	movl -4(%ebp),%eax
	cmpl $100,%eax
	jge .skip0
	pushl $128
	leal tab,%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	pushl $.s1
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl $128
	pushl $.stracc
	leal tab,%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	movl -4(%ebp),%eax
	addl $1,%eax
	movl %eax,-4(%ebp)
	jmp .loop0
	.skip0:
	movl $2 ,-4(%ebp)
	.loop1:
	movl -4(%ebp),%eax
	cmpl $10,%eax
	jge .skip1
	movl -4(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,-8(%ebp)
	.loop2:
	movl -8(%ebp),%eax
	cmpl $100,%eax
	jge .skip2
	pushl $48
	pushl -8(%ebp)
	leal tab,%eax
	pushl %eax
	call put_char_at
	addl $12, %esp
	movl -8(%ebp),%eax
	addl -4(%ebp),%eax
	movl %eax,-8(%ebp)
	jmp .loop2
	.skip2:
	movl -4(%ebp),%eax
	addl $1,%eax
	movl %eax,-4(%ebp)
	jmp .loop1
	.skip1:
	movl $0 ,-4(%ebp)
	.loop3:
	movl -4(%ebp),%eax
	cmpl $100,%eax
	jge .skip3
	pushl -4(%ebp)
	leal tab,%eax
	pushl %eax
	call get_char_at
	addl $8, %esp
	cmpl $49,%eax
	jne .no4
	pushl -4(%ebp)
	call printd
	addl $4, %esp
	subl $128, %esp
	pushl $128
	pushl $.s2
	leal 8(%esp),%eax
	pushl %eax
	call strncpy
	movb $0,127(%eax)
	addl $12, %esp
	leal 0(%esp),%eax
	pushl %eax
	call printf
	addl $132, %esp
	.no4:
	movl -4(%ebp),%eax
	addl $1,%eax
	movl %eax,-4(%ebp)
	jmp .loop3
	.skip3:
	subl $128, %esp
	pushl $128
	pushl $.s3
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

	.comm tab,128,4

	.comm .stracc,256,4

.section	.rodata
	.s0:	.string "0"
	.s1:	.string "1"
	.s2:	.string " "
	.s3:	.string "\n"
