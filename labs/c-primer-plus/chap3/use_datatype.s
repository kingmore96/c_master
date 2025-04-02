	.file	"use_datatype.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.2) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu use_datatype.c
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
	.string	"%d\n"
	.text
	.globl	test1
	.type	test1, @function
test1:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# use_datatype.c:7: 	int a = 12.99;
	movl	$12, -4(%rbp)	#, a
# use_datatype.c:8: 	printf("%d\n",a);
	movl	-4(%rbp), %eax	# a, tmp82
	movl	%eax, %esi	# tmp82,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# use_datatype.c:9: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	test1, .-test1
	.globl	test2
	.type	test2, @function
test2:
.LFB1:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# use_datatype.c:13: 	double a = 12.99;
	movsd	.LC1(%rip), %xmm0	#, tmp82
	movsd	%xmm0, -8(%rbp)	# tmp82, a
# use_datatype.c:14: 	int b = a;
	movsd	-8(%rbp), %xmm0	# a, tmp83
	cvttsd2sil	%xmm0, %eax	# tmp83, tmp84
	movl	%eax, -12(%rbp)	# tmp84, b
# use_datatype.c:15: 	printf("%d\n",b);
	movl	-12(%rbp), %eax	# b, tmp85
	movl	%eax, %esi	# tmp85,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# use_datatype.c:16: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	test2, .-test2
	.section	.rodata
.LC2:
	.string	"%f\n"
	.text
	.globl	test3
	.type	test3, @function
test3:
.LFB2:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# use_datatype.c:25: 	uint64_t low = 1202590843ULL;
	movq	$1202590843, -24(%rbp)	#, low
# use_datatype.c:26: 	uint64_t high = 1076493025ULL;
	movq	$1076493025, -16(%rbp)	#, high
# use_datatype.c:28: 	uint64_t combined = high << 32 | low;
	movq	-16(%rbp), %rax	# high, tmp84
	salq	$32, %rax	#, _1
# use_datatype.c:28: 	uint64_t combined = high << 32 | low;
	orq	-24(%rbp), %rax	# low, tmp86
	movq	%rax, -8(%rbp)	# tmp86, combined
# use_datatype.c:29: 	c.v = combined;
	movq	-8(%rbp), %rax	# combined, tmp87
	movq	%rax, -32(%rbp)	# tmp87, c.v
# use_datatype.c:31: 	printf("%f\n",c.d);
	movq	-32(%rbp), %rax	# c.d, _2
	movq	%rax, %xmm0	# _2,
	leaq	.LC2(%rip), %rdi	#,
	movl	$1, %eax	#,
	call	printf@PLT	#
# use_datatype.c:32: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2:
	.size	test3, .-test3
	.globl	test4
	.type	test4, @function
test4:
.LFB3:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# use_datatype.c:35: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp83
	movq	%rax, -8(%rbp)	# tmp83, D.2571
	xorl	%eax, %eax	# tmp83
# use_datatype.c:41: 	c.v[1] = 1076493025;
	movl	$1076493025, -12(%rbp)	#, c.v
# use_datatype.c:42: 	c.v[0] = 1202590843;
	movl	$1202590843, -16(%rbp)	#, c.v
# use_datatype.c:44: 	printf("%f\n",c.d);
	movq	-16(%rbp), %rax	# c.d, _1
	movq	%rax, %xmm0	# _1,
	leaq	.LC2(%rip), %rdi	#,
	movl	$1, %eax	#,
	call	printf@PLT	#
# use_datatype.c:45: }	
	nop	
	movq	-8(%rbp), %rax	# D.2571, tmp84
	xorq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp84
	je	.L5	#,
	call	__stack_chk_fail@PLT	#
.L5:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE3:
	.size	test4, .-test4
	.section	.rodata
.LC3:
	.string	"%016llX\n"
.LC4:
	.string	"%016lX\n"
	.text
	.globl	test5
	.type	test5, @function
test5:
.LFB4:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# use_datatype.c:48: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp86
	movq	%rax, -8(%rbp)	# tmp86, D.2573
	xorl	%eax, %eax	# tmp86
# use_datatype.c:49: 	double d = 12.99;
	movsd	.LC1(%rip), %xmm0	#, tmp85
	movsd	%xmm0, -24(%rbp)	# tmp85, d
# use_datatype.c:50: 	printf("%016llX\n",d);
	movq	-24(%rbp), %rax	# d, d.0_1
	movq	%rax, %xmm0	# d.0_1,
	leaq	.LC3(%rip), %rdi	#,
	movl	$1, %eax	#,
	call	printf@PLT	#
	movq	-24(%rbp), %rax	# MEM[(char * {ref-all})&d], _6
# use_datatype.c:53: 	memcpy(&bits,&d,sizeof(bits));
	movq	%rax, -16(%rbp)	# _6, MEM[(char * {ref-all})&bits]
# use_datatype.c:55: 	printf("%016lX\n",bits);
	movq	-16(%rbp), %rax	# bits, bits.1_2
	movq	%rax, %rsi	# bits.1_2,
	leaq	.LC4(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# use_datatype.c:56: }
	nop	
	movq	-8(%rbp), %rax	# D.2573, tmp87
	xorq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp87
	je	.L7	#,
	call	__stack_chk_fail@PLT	#
.L7:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE4:
	.size	test5, .-test5
	.section	.rodata
.LC5:
	.string	"py_low:1202590843U = %016X\n"
.LC6:
	.string	"py_high:1076493025U = %016X\n"
.LC7:
	.string	"%02X "
	.text
	.globl	test6
	.type	test6, @function
test6:
.LFB5:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# use_datatype.c:60: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp91
	movq	%rax, -8(%rbp)	# tmp91, D.2576
	xorl	%eax, %eax	# tmp91
# use_datatype.c:61: 	printf("py_low:1202590843U = %016X\n",1202590843U);
	movl	$1202590843, %esi	#,
	leaq	.LC5(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# use_datatype.c:62: 	printf("py_high:1076493025U = %016X\n",1076493025U);
	movl	$1076493025, %esi	#,
	leaq	.LC6(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# use_datatype.c:64: 	double d = 12.99;
	movsd	.LC1(%rip), %xmm0	#, tmp87
	movsd	%xmm0, -24(%rbp)	# tmp87, d
# use_datatype.c:65: 	char *p = (char*)&d;
	leaq	-24(%rbp), %rax	#, tmp88
	movq	%rax, -16(%rbp)	# tmp88, p
# use_datatype.c:67: 	for(int i = 0;i < sizeof(d);i++){
	movl	$0, -28(%rbp)	#, i
# use_datatype.c:67: 	for(int i = 0;i < sizeof(d);i++){
	jmp	.L9	#
.L10:
# use_datatype.c:68: 		printf("%02X ",*(p+i));
	movl	-28(%rbp), %eax	# i, tmp89
	movslq	%eax, %rdx	# tmp89, _1
	movq	-16(%rbp), %rax	# p, tmp90
	addq	%rdx, %rax	# _1, _2
# use_datatype.c:68: 		printf("%02X ",*(p+i));
	movzbl	(%rax), %eax	# *_2, _3
# use_datatype.c:68: 		printf("%02X ",*(p+i));
	movsbl	%al, %eax	# _3, _4
	movl	%eax, %esi	# _4,
	leaq	.LC7(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# use_datatype.c:67: 	for(int i = 0;i < sizeof(d);i++){
	addl	$1, -28(%rbp)	#, i
.L9:
# use_datatype.c:67: 	for(int i = 0;i < sizeof(d);i++){
	movl	-28(%rbp), %eax	# i, i.2_5
# use_datatype.c:67: 	for(int i = 0;i < sizeof(d);i++){
	cmpl	$7, %eax	#, i.2_5
	jbe	.L10	#,
# use_datatype.c:70: 	printf("\n");
	movl	$10, %edi	#,
	call	putchar@PLT	#
# use_datatype.c:71: }
	nop	
	movq	-8(%rbp), %rax	# D.2576, tmp92
	xorq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp92
	je	.L11	#,
	call	__stack_chk_fail@PLT	#
.L11:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE5:
	.size	test6, .-test6
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# use_datatype.c:76: 	test1();
	movl	$0, %eax	#,
	call	test1	#
# use_datatype.c:77: 	test2();
	movl	$0, %eax	#,
	call	test2	#
# use_datatype.c:78: 	test3();
	movl	$0, %eax	#,
	call	test3	#
# use_datatype.c:79: 	test4();
	movl	$0, %eax	#,
	call	test4	#
# use_datatype.c:80: 	test5();
	movl	$0, %eax	#,
	call	test5	#
# use_datatype.c:81: 	test6();
	movl	$0, %eax	#,
	call	test6	#
	movl	$0, %eax	#, _8
# use_datatype.c:82: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	1202590843
	.long	1076493025
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
