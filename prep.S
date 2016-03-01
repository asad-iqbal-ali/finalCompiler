.globl sub
  .type sub,@function
sub:
  enter $260, $0
  pushl $128
  pushl 8(%ebp)
  leal -128(%ebp) %eax
  pushl %eax
  call strncpy
  movb  $0, 127(%eax)
  addl $12, %esp
  pushl $.s0
  popl %edx
  pushl $128
  pushl %edx
  leal -260(%ebp), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl 12(%ebp)
  popl -132(%ebp)
  .loop0:
  pushl -132(%ebp)
  pushl 16(%ebp)
  popl %edx
  popl %eax
  cmp %edx, %eax
  jg .skip0
  pushl -132(%ebp)
  leal -128(%ebp), %eax
  pushl %eax
  call get_char_at
  addl $8, %esp
  pushl %eax
  leal -260(%ebp), %eax
  pushl %eax
  popl %ebx
  popl %eax
  andw $0xff, %ax
  movw %ax, .stracc
  sub $128, %esp
  movl %esp, %ecx
  pushl $.stracc
  pushl %ecx
  call strcpy
  addl $8, %esp
  pushl $128
  pushl  %ebx
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %esp
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $136, %esp
  pushl $128
  pushl $.stracc
  pushl $.strres
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push $.strres
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  popl %edx
  pushl $128
  pushl %edx
  leal -260(%ebp), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl $1
  pushl -132(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  popl -132(%ebp)
  jmp .loop0
  .skip0:
  leal -260(%ebp), %eax
  pushl %eax
  popl %eax
  jmp .sub_ret
.sub_ret:
  leave
  ret

.globl invert
  .type invert,@function
invert:
  enter $388, $0
  pushl $128
  pushl 8(%ebp)
  leal -128(%ebp) %eax
  pushl %eax
  call strncpy
  movb  $0, 127(%eax)
  addl $12, %esp
  leal -388(%ebp), %eax
  pushl %eax
  pushl $.s1
  popl %edx
  popl %eax
  cmp %edx, %eax
  jne .no1
  pushl $.s2
  popl %eax
  jmp .invert_ret
  .no1:
  pushl $0
  leal -388(%ebp), %eax
  pushl %eax
  call get_char_at
  addl $8, %esp
  pushl %eax
  pushl $1
  leal -388(%ebp), %eax
  pushl %eax
  call strlen
  addl $4, %esp
  pushl %eax
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  pushl $1
  leal -388(%ebp), %eax
  pushl %eax
  call sub
  addl $12, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  popl %ebx
  popl %eax
  andw $0xff, %ax
  movw %ax, .stracc
  sub $128, %esp
  movl %esp, %ecx
  pushl $.stracc
  pushl %ecx
  call strcpy
  addl $8, %esp
  pushl $128
  pushl  %ebx
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %esp
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $136, %esp
  pushl $128
  pushl $.stracc
  pushl $.strres
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push $.strres
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  popl %eax
  jmp .invert_ret
.invert_ret:
  leave
  ret

.globl main
  .type main,@function
main:
  enter $644, $0
  pushl $.s3
  popl %edx
  pushl $128
  pushl %edx
  leal -516(%ebp), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl $.s4
  popl %edx
  pushl $128
  pushl %edx
  leal -644(%ebp), %eax
  pushl %eax
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  leal -516(%ebp), %eax
  pushl %eax
  leal -644(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ebx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ebx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $128
  pushl $.stracc
  pushl $.strres
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push $.strres
  call invert
  addl $4, %esp
  pushl %eax
  leal -644(%ebp), %eax
  pushl %eax
  leal -516(%ebp), %eax
  pushl %eax
  popl %eax
  popl %ebx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ebx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $128
  pushl $.stracc
  pushl $.strres
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push $.strres
  popl %eax
  popl %ebx
  pushl $128
  pushl %eax
  pushl $.stracc
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  pushl %ebx
  pushl $.stracc
  call strcat
  movb $0, 127(%eax)
  addl $8, %esp
  pushl $128
  pushl $.stracc
  pushl $.strres
  call strncpy
  movb $0, 127(%eax)
  addl $12, %esp
  push $.strres
  call printf
  addl $4, %esp
  pushl %eax
  leal -644(%ebp), %eax
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call invert
  addl $4, %esp
  pushl %eax
  call printf
  addl $4, %esp
  pushl %eax
  pushl $0
  popl %eax
  jmp .main_ret
.main_ret:
  leave
  ret

	.comm .stracc,256,4

	.comm .strres,256,4

.section	.rodata
	.s0:	.string	""
	.s1:	.string	""
	.s2:	.string	""
	.s3:	.string	"hello"
	.s4:	.string	"world"
