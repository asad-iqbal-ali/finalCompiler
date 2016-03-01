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
	leal -128(%ebp),%eax
	pushl %eax
	leal -256(%ebp),%eax
	pushl %eax
	call strcmp
	addl $8,%esp
	cmpl $0,%eax
	jne .no0
	pushl $1
	call printd
	addl $4, %esp
	jmp .out0
	.no0:
	pushl $0
	call printd
	addl $4, %esp
	.out0:
	pushl $1
	call printd
	addl $4, %esp
	leal -256(%ebp),%eax
	pushl %eax
	leal -128(%ebp),%eax
	pushl %eax
	call strcmp
	addl $8,%esp
	cmpl $0,%eax
	jne .no2
	pushl $1
	call printd
	addl $4, %esp
	jmp .out2
	.no2:
	pushl $0
	call printd
	addl $4, %esp
	.out2:
	pushl $128
	leal -256(%ebp),%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	pushl $.s5
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	subl $128,%esp
	movl %esp,%ecx
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
	pushl $128
	leal u,%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	pushl $.s6
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl %esp
	pushl $.stracc
	call strcmp
	addl $8,%esp
	addl $128,%esp
	cmpl $0,%eax
	jne .no3
	pushl $1
	call printd
	addl $4, %esp
	jmp .out3
	.no3:
	pushl $0
	call printd
	addl $4, %esp
	.out3:
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
	leal u,%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	subl $128,%esp
	movl %esp,%ecx
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
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
	leal u,%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl %esp
	pushl $.stracc
	call strcmp
	addl $8,%esp
	addl $128,%esp
	cmpl $0,%eax
	jne .no4
	pushl $1
	call printd
	addl $4, %esp
	jmp .out4
	.no4:
	pushl $0
	call printd
	addl $4, %esp
	.out4:
	leal -128(%ebp),%eax
	pushl %eax
	leal -256(%ebp),%eax
	pushl %eax
	call strcmp
	addl $8,%esp
	cmpl $0,%eax
	je .no5
	pushl $1
	call printd
	addl $4, %esp
	jmp .out5
	.no5:
	pushl $0
	call printd
	addl $4, %esp
	.out5:
	pushl $0
	call printd
	addl $4, %esp
	leal -256(%ebp),%eax
	pushl %eax
	leal -128(%ebp),%eax
	pushl %eax
	call strcmp
	addl $8,%esp
	cmpl $0,%eax
	je .no7
	pushl $1
	call printd
	addl $4, %esp
	jmp .out7
	.no7:
	pushl $0
	call printd
	addl $4, %esp
	.out7:
	pushl $128
	leal -256(%ebp),%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	pushl $.s9
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	subl $128,%esp
	movl %esp,%ecx
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
	pushl $128
	leal u,%eax
	pushl %eax
	push $.stracc
	call strncpy
	movb $0,127(%eax)
	addl $12,%esp
	pushl $.s10
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl %esp
	pushl $.stracc
	call strcmp
	addl $8,%esp
	addl $128,%esp
	cmpl $0,%eax
	je .no8
	pushl $1
	call printd
	addl $4, %esp
	jmp .out8
	.no8:
	pushl $0
	call printd
	addl $4, %esp
	.out8:
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
	leal u,%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	subl $128,%esp
	movl %esp,%ecx
	movl %esp,%ecx
	pushl $.stracc
	pushl %ecx
	call strcpy
	addl $8,%esp
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
	leal u,%eax
	pushl %eax
	push $.stracc
	call strcat
	movb $0,127(%eax)
	addl $8,%esp
	pushl %esp
	pushl $.stracc
	call strcmp
	addl $8,%esp
	addl $128,%esp
	cmpl $0,%eax
	je .no9
	pushl $1
	call printd
	addl $4, %esp
	jmp .out9
	.no9:
	pushl $0
	call printd
	addl $4, %esp
	.out9:
	movl $0,%eax
	jmp .main_ret
.main_ret:
	leave
	ret

	.comm u,128,4

	.comm .stracc,256,4

.section	.rodata
	.s0:	.string "hello"
	.s1:	.string "helll"
	.s2:	.string "hellp"
	.s3:	.string "abc"
	.s4:	.string "abc"
	.s5:	.string "abc"
	.s6:	.string "ab"
	.s7:	.string "abc"
	.s8:	.string "abc"
	.s9:	.string "abc"
	.s10:	.string "ab"
