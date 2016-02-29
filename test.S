.globl main
  .type main,@function
main:
  enter $4, $0
  pushl $1
  popl -4(%ebp)
  enter $4, $0
  enter $0, $0
  pushl $3
  movl (%ebp), %ecx
  popl -4(%ecx)
  enter $0, $0
  movl (%ebp), %ecx
  movl (%ecx), %ecx
  pushl -4(%ecx)
  movl (%ebp), %ecx
  movl (%ecx), %ecx
  movl (%ecx), %ecx
  popl -4(%ecx)
  leave
  leave
  leave
  pushl -4(%ebp)
  call printd
  addl $4, %esp
  pushl %eax
.main_ret:
  leave
  ret

	.comm .stracc,256,4

	.comm .strres,256,4

