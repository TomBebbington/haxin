	.file	"tests/hello.ll"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	subq	$184, %rsp
.Ltmp1:
	.cfi_def_cfa_offset 192
	testb	%al, %al
	je	.LBB0_2
# BB#1:
	vmovaps	%xmm0, 48(%rsp)
	vmovaps	%xmm1, 64(%rsp)
	vmovaps	%xmm2, 80(%rsp)
	vmovaps	%xmm3, 96(%rsp)
	vmovaps	%xmm4, 112(%rsp)
	vmovaps	%xmm5, 128(%rsp)
	vmovaps	%xmm6, 144(%rsp)
	vmovaps	%xmm7, 160(%rsp)
.LBB0_2:
	movq	%r9, 40(%rsp)
	movq	%r8, 32(%rsp)
	movq	%rcx, 24(%rsp)
	movq	%rdx, 16(%rsp)
	movq	%rsi, 8(%rsp)
	movq	%rdi, (%rsp)
	movl	$.str, %edi
	callq	puts
	xorl	%eax, %eax
	addq	$184, %rsp
	ret
.Ltmp2:
	.size	main, .Ltmp2-main
	.cfi_endproc

	.type	.str,@object            # @.str
	.section	.rodata,"a",@progbits
.str:
	.asciz	 "Hello World"
	.size	.str, 12


	.section	".note.GNU-stack","",@progbits
