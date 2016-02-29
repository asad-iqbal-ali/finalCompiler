.globl main
  .type main,@function
main:
  enter $4, $0
  pushl $2
  popl -4(%ebp)
  enter $4, $0
  pushl $23
  popl -4(%ebp)
  enter $0, $0
  pushl $2
  leal (%ebp), %ecx
  leal (%ecx), %ecx
  leal (%ecx), %ecx
  popl -4(%ecx)
  leal (%ebp), %ecx
  leal (%ecx), %ecx
  leal (%ecx), %ecx
  pushl -4(%ecx)
  leal (%ebp), %ecx
  pushl -4(%ecx)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  leal (%ebp), %ecx
  leal (%ecx), %ecx
  popl -4(%ecx)
  leave
  leave
  pushl -4(%ebp)
  popl %eax
  jmp .main_ret
.main_ret:
  leave
  ret

.globl start
start:
  enter $4, $0
  pushl $0
  popl -4(%ebp)
  jmp main

	.comm .stracc,256,4

	.comm .strres,256,4

