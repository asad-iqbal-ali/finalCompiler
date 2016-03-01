.globl main
	.type main,@function
main:
	enter $132,$0
	movl $15 ,-4(%ebp)
	movl -4(%ebp),%eax
	movl %eax,-4(%ebp)
	movl -4(%ebp),%eax
	jmp .main_ret
.main_ret:
	leave
	ret


	.comm .stracc,256,4

.section	.rodata
	.s2:	.string "aaa"
	.s5:	.string "aaa"
	.s8:	.string "abcdef"
	.s9:	.string "1"
