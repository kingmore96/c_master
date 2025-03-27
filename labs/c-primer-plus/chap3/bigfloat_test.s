	.file	"bigfloat_test.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.2) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu bigfloat_test.c
# -mtune=generic -march=x86-64 -fverbose-asm -fasynchronous-unwind-tables
# -fstack-protector-strong -Wformat -Wformat-security
# -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
# -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
# -fipa-stack-alignment -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fshrink-wrap-separate
# -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop
# -fstack-clash-protection -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	print_bits
	.type	print_bits, @function
print_bits:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movss	%xmm0, -20(%rbp)	# f, f
# bigfloat_test.c:9: 	c.a = f;
	movss	-20(%rbp), %xmm0	# f, tmp87
	movss	%xmm0, -8(%rbp)	# tmp87, c.a
# bigfloat_test.c:11: 	for(int i=0;i<32;i++){
	movl	$0, -4(%rbp)	#, i
# bigfloat_test.c:11: 	for(int i=0;i<32;i++){
	jmp	.L2	#
.L5:
# bigfloat_test.c:12: 		printf("%d",c.b & 1 << (31 - i) ? 1 : 0);	
	movl	-8(%rbp), %edx	# c.b, _1
# bigfloat_test.c:12: 		printf("%d",c.b & 1 << (31 - i) ? 1 : 0);	
	movl	-4(%rbp), %eax	# i, tmp88
	movl	$-2147483648, %esi	#, tmp89
	movl	%eax, %ecx	# tmp88, tmp91
	shrl	%cl, %esi	# tmp91, tmp89
	movl	%esi, %eax	# tmp89, _2
# bigfloat_test.c:12: 		printf("%d",c.b & 1 << (31 - i) ? 1 : 0);	
	andl	%edx, %eax	# _1, _3
# bigfloat_test.c:12: 		printf("%d",c.b & 1 << (31 - i) ? 1 : 0);	
	testl	%eax, %eax	# _3
	setne	%al	#, _4
	movzbl	%al, %eax	# _4, _5
	movl	%eax, %esi	# _5,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# bigfloat_test.c:14: 		if(i == 0 || i == 8)
	cmpl	$0, -4(%rbp)	#, i
	je	.L3	#,
# bigfloat_test.c:14: 		if(i == 0 || i == 8)
	cmpl	$8, -4(%rbp)	#, i
	jne	.L4	#,
.L3:
# bigfloat_test.c:15: 			printf(" ");
	movl	$32, %edi	#,
	call	putchar@PLT	#
.L4:
# bigfloat_test.c:11: 	for(int i=0;i<32;i++){
	addl	$1, -4(%rbp)	#, i
.L2:
# bigfloat_test.c:11: 	for(int i=0;i<32;i++){
	cmpl	$31, -4(%rbp)	#, i
	jle	.L5	#,
# bigfloat_test.c:17: 	printf("\n");
	movl	$10, %edi	#,
	call	putchar@PLT	#
# bigfloat_test.c:18: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	print_bits, .-print_bits
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# bigfloat_test.c:24: 	b = 2.0e20 + 1;
	movss	.LC1(%rip), %xmm0	#, tmp86
	movss	%xmm0, -8(%rbp)	# tmp86, b
# bigfloat_test.c:25: 	print_bits(b);
	movl	-8(%rbp), %eax	# b, tmp87
	movd	%eax, %xmm0	# tmp87,
	call	print_bits	#
# bigfloat_test.c:26: 	a = b - 2.0e20;
	cvtss2sd	-8(%rbp), %xmm0	# b, _1
	movsd	.LC2(%rip), %xmm1	#, tmp88
	subsd	%xmm1, %xmm0	# tmp88, _2
# bigfloat_test.c:26: 	a = b - 2.0e20;
	cvtsd2ss	%xmm0, %xmm0	# _2, tmp90
	movss	%xmm0, -4(%rbp)	# tmp90, a
# bigfloat_test.c:27: 	print_bits(a);
	movl	-4(%rbp), %eax	# a, tmp91
	movd	%eax, %xmm0	# tmp91,
	call	print_bits	#
	movl	$0, %eax	#, _8
# bigfloat_test.c:28: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC1:
	.long	1630370028
	.align 8
.LC2:
	.long	2025163840
	.long	1143320349
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
