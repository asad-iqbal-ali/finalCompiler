.globl main
  .type main,@function
main:
  enter $8, $0
  pushl $45000
  popl -4(%ebp)
  pushl $123
  pushl $0
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  popl -8(%ebp)
  pushl -8(%ebp)
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl -8(%ebp)
  pushl $45000
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl $123
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl $123
  pushl $45000
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl $0
  pushl -8(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl -8(%ebp)
  pushl $0
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl $0
  pushl -8(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  pushl $0
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl $123
  pushl $0
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
  addl $4, %esp
  pushl %eax
  pushl $0
  pushl -8(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  pushl %eax
  pushl $45000
  popl %eax
  popl %ecx
  subl %ecx, %eax
  pushl %eax
  call printd
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

