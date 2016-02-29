.globl main
  .type main,@function
main:
  enter $8, $0
  pushl $45000
  popl -4(%ebp)
  pushl $123
  popl %edx
  movl $0, %ecx
  subl %edx, %ecx
  push %ecx
  popl -8(%ebp)
  pushl -8(%ebp)
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl -8(%ebp)
  pushl $45000
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl $123
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl $123
  pushl $45000
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl $0
  pushl -8(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  push %eax
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl -8(%ebp)
  pushl $0
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  push %eax
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl $0
  pushl -8(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  push %eax
  pushl $0
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  push %eax
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl $123
  pushl $0
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  push %eax
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl $0
  pushl -8(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  push %eax
  pushl $45000
  popl %eax
  popl %ecx
  imull %ecx, %eax
  push %eax
  call printd
  pushl %eax
  addl $4, %esp
  pushl $0
  popl %eax
  jmp .main_ret
.main_ret:
  leave
  ret

	.comm .stracc,256,4

