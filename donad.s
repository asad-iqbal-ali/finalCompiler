.globl main
	.type main,@function
main:
	enter $12,$0
	movl $45000 ,-4(%ebp)
	movl $-123 ,-8(%ebp)
	movl $43 ,-12(%ebp)
	movl -12(%ebp),%eax
	subl -8(%ebp),%eax
	sarl $2,%eax
	pushl %eax
	movl -8(%ebp),%eax
	imull -12(%ebp),%eax
	movl -4(%ebp), %ecx
	cltd
	idivl %ecx
	movl %edx,%eax
	pushl %eax
	movl -4(%ebp),%eax
	addl -8(%ebp),%eax
	imull -12(%ebp),%eax
	movl $100, %ecx
	cltd
	idivl %ecx
	popl %ecx
	addl %ecx,%eax
	subl -8(%ebp),%eax
	movl -12(%ebp),%ecx
	sall %cl,%eax
	popl %ecx
	cltd
	idivl %ecx
	pushl %eax
	call printd
	addl $4, %esp
	movl $0,%eax
	jmp .main_ret
.main_ret:
	leave
	ret


	.comm .stracc,256,4

