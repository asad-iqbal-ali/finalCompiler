.globl main
  .type main,@function
main:
  enter $256, $0
  pushl $.s0
  popl %edx
  pushl $128
  pushl %edx
  leal -128(%ebp), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl $.s1
  popl %edx
  pushl $128
  pushl %edx
  leal -256(%ebp), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl $.s2
  leal (%ebp), %ecx
  leal -128(%ecx), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl $.s3
  call printf
  pushl %eax
  addl $4, %esp
  pushl $.s5
  pushl $.s4
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  pushl $.s6
  leal -128(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  leal -256(%ebp), %eax
  pushl %eax
  pushl $.s7
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  leal -256(%ebp), %eax
  pushl %eax
  leal -128(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  leal -256(%ebp), %eax
  pushl %eax
  leal -128(%ecx), %eax
  pushl %eax
  leal -128(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  leal -256(%ebp), %eax
  pushl %eax
  leal -128(%ecx), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  leal -128(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  leal -256(%ebp), %eax
  pushl %eax
  leal -256(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  leal -128(%ebp), %eax
  pushl %eax
  leal -128(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  leal -256(%ebp), %eax
  pushl %eax
  leal -128(%ecx), %eax
  pushl %eax
  leal -128(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  popl %eax
  popl %ecx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ecx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $.stracc
  call printf
  pushl %eax
  addl $4, %esp
  pushl $0
  popl %eax
  jmp .main_ret
.main_ret:
  leave
  ret

	.comm .stracc,256,4

.section	.rodata
	.s0:	.string	"hello"
	.s1:	.string	" world\n"
	.s2:	.string	"bye"
	.s3:	.string	"hello"
	.s4:	.string	"hello"
	.s5:	.string	"world\n"
	.s6:	.string	"world\n"
	.s7:	.string	"hello"
