.globl str
  .type str,@function
str:
  enter $128, $0
  pushl $128
  pushl 8(%ebp)
  leal -128(%ebp), %eax
  pushl %eax
  call strncpy
  movb  $0, 127(%eax)
  addl $12, %esp
  pushl $.s0
  leal -128(%ebp), %eax
  pushl %eax
  popl %eax
  movl %esp, %ebx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl (%ebx)
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  subl $128, %esp
  movl %esp, %eax
  pushl $128
  pushl $.stracc
  leal (%eax), %eax
  push %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push %eax
  popl %eax
  jmp .str_ret
.str_ret:
  leave
  ret

.globl str2
  .type str2,@function
str2:
  enter $384, $0
  pushl $128
  pushl 8(%ebp)
  leal -128(%ebp), %eax
  pushl %eax
  call strncpy
  movb  $0, 127(%eax)
  addl $12, %esp
  pushl $128
  pushl 12(%ebp)
  leal -256(%ebp), %eax
  pushl %eax
  call strncpy
  movb  $0, 127(%eax)
  addl $12, %esp
  leal -384(%ebp), %eax
  pushl %eax
  leal -256(%ebp), %eax
  pushl %eax
  popl %eax
  movl %esp, %ebx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl (%ebx)
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  subl $128, %esp
  movl %esp, %eax
  pushl $128
  pushl $.stracc
  leal (%eax), %eax
  push %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push %eax
  popl %eax
  jmp .str2_ret
.str2_ret:
  leave
  ret

.globl main
  .type main,@function
main:
  enter $644, $0
  pushl $.s1
  popl %edx
  pushl $128
  pushl %edx
  leal s, %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl $.s2
  popl %edx
  pushl $128
  pushl %edx
  leal -640(%ebp), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl $.s3
  leal s, %eax
  pushl %eax
  call str2
  addl $8, %esp
  movl %esp, %ebx
  subl $4, %ebx
  subl $128, %esp
  movl %esp, %edx
  pushl $128
  pushl %eax
  pushl %edx
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push %eax
  call printf
  addl $4, %esp
  pushl %eax
  pushl $.s4
  leal s, %eax
  pushl %eax
  call str2
  addl $8, %esp
  movl %esp, %ebx
  subl $4, %ebx
  subl $128, %esp
  movl %esp, %edx
  pushl $128
  pushl %eax
  pushl %edx
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push %eax
  call str
  addl $4, %esp
  movl %esp, %ebx
  subl $4, %ebx
  subl $128, %esp
  movl %esp, %edx
  pushl $128
  pushl %eax
  pushl %edx
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push %eax
  leal -640(%ebp), %eax
  pushl %eax
  popl %eax
  movl %esp, %ebx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl (%ebx)
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  subl $128, %esp
  movl %esp, %eax
  pushl $128
  pushl $.stracc
  leal (%eax), %eax
  push %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push %eax
  call printf
  addl $4, %esp
  pushl %eax
  pushl $0
  popl %eax
  jmp .main_ret
.main_ret:
  leave
  ret

	.comm s,128,4
	.comm .stracc,256,4

	.comm .strres,256,4

.section	.rodata
	.s0:	.string	"\n"
	.s1:	.string	"SPACE"
	.s2:	.string	"abcd"
	.s3:	.string	"\n"
	.s4:	.string	"efg"
