.globl foo
  .type foo,@function
foo:
  enter $8, $0
  pushl $0
  popl -4(%ebp)
  pushl 4(%ebp)
  pushl -4(%ebp)
  popl %eax
  popl %ecx
  addl %ecx, %eax
  push %eax
  popl -8(%ebp)
  pushl -8(%ebp)
  popl %eax
  jmp .foo_ret
.foo_ret:
  leave
  ret

.globl main
  .type main,@function
main:
  enter $0, $0
  popl %eax
  jmp .main_ret
.main_ret:
  leave
  ret

