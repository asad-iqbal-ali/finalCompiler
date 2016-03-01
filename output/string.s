.globl main
	.type main,@function
main:
	enter $256,$0
	pushl $128
	pushl $.s0
	leal -128(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	pushl $128
	pushl $.s1
	leal -256(%ebp),%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
	pushl $128
	pushl $.s2
	leal u,%eax
	pushl %eax
	call strncpy
	movb $0, 127(%eax)
	addl $12, %esp
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
	subl $128, %esp
	pushl $128
	pushl $.s6
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
	pushl $128
	leal -128(%ebp),%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	pushl $.s7
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
	call printf
	addl $132, %esp
	subl $128, %esp
	pushl $128
	pushl $.s8
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
	pushl $128
	leal -128(%ebp),%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	leal u,%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	leal -256(%ebp),%eax
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
	call printf
	addl $132, %esp
	subl $128, %esp
	pushl $128
	leal u,%eax
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
	leal -128(%ebp),%eax
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
	pushl $128
	leal -128(%ebp),%eax
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
	subl $128,%esp
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
	pushl $128
	leal -256(%ebp),%eax
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
	pushl $128
	leal -128(%ebp),%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	leal u,%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	leal -256(%ebp),%eax
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
	call printf
	addl $132, %esp
	movl $0,%eax
	jmp .main_ret
.main_ret:
	leave
	ret

	.comm u,128,4

	.comm .stracc,256,4

.section	.rodata
	.s0:	.string "hello"
	.s1:	.string " world\n"
	.s2:	.string "bye"
	.s3:	.string "hello"
	.s6:	.string "helloworld\n"
	.s7:	.string "world\n"
	.s8:	.string "hello"
