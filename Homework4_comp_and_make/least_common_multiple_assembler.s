	.file	"least_common_multiple.c"
	.text
	.globl	nok
	.def	nok;	.scl	2;	.type	32;	.endef
	.seh_proc	nok
nok:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$2, -4(%rbp)
	movl	$1, -8(%rbp)
	jmp	.L2
.L5:
	movl	16(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L3
	movl	16(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%eax, 16(%rbp)
	movl	-8(%rbp), %eax
	imull	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	24(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L2
	movl	24(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%eax, 24(%rbp)
	jmp	.L2
.L3:
	movl	24(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L4
	movl	24(%rbp), %eax
	cltd
	idivl	-4(%rbp)
	movl	%eax, 24(%rbp)
	movl	-8(%rbp), %eax
	imull	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L2
.L4:
	addl	$1, -4(%rbp)
.L2:
	cmpl	$1, 16(%rbp)
	jne	.L5
	cmpl	$1, 24(%rbp)
	jne	.L5
	movl	-8(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$18, %edx
	movl	$12, %ecx
	call	nok
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev7, Built by MSYS2 project) 13.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
