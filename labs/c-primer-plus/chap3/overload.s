	.file	"overload.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.2) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu overload.c -mtune=generic
# -march=x86-64 -fverbose-asm -fasynchronous-unwind-tables
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
	.string	"func1: MAX = %d\n"
	.text
	.globl	func1
	.type	func1, @function
func1:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# overload.c:7:     printf("func1: MAX = %d\n", MAX);  // 输出 200
	movl	$200, %esi	#,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# overload.c:8: }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	func1, .-func1
	.section	.rodata
.LC1:
	.string	"func2: MAX = %d\n"
	.text
	.globl	func2
	.type	func2, @function
func2:
.LFB1:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# overload.c:11:     printf("func2: MAX = %d\n", MAX);  // 输出 200（受 func1 内的宏定义影响）
	movl	$200, %esi	#,
	leaq	.LC1(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# overload.c:12: }
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	func2, .-func2
	.section	.rodata
	.align 8
.LC2:
	.string	"main (before func1): MAX = %d\n"
.LC3:
	.string	"main (after func1): MAX = %d\n"
.LC5:
	.string	"%d\n"
.LC7:
	.string	"%.1f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# overload.c:15: 	printf("main (before func1): MAX = %d\n", MAX);  // 输出 100
	movl	$200, %esi	#,
	leaq	.LC2(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# overload.c:16: 	func1();
	movl	$0, %eax	#,
	call	func1	#
# overload.c:17: 	printf("main (after func1): MAX = %d\n", MAX);    // 输出 200
	movl	$200, %esi	#,
	leaq	.LC3(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# overload.c:18: 	func2();
	movl	$0, %eax	#,
	call	func2	#
# overload.c:20: 	float t = 33554432.0f;
	movss	.LC4(%rip), %xmm0	#, tmp90
	movss	%xmm0, -4(%rbp)	# tmp90, t
# overload.c:21: 	printf("%d\n",t == 33554432.0f?1:0);
	movss	-4(%rbp), %xmm0	# t, tmp92
	ucomiss	.LC4(%rip), %xmm0	#, tmp92
	setnp	%al	#, tmp91
	movl	$0, %edx	#, tmp94
	movss	-4(%rbp), %xmm0	# t, tmp93
	ucomiss	.LC4(%rip), %xmm0	#, tmp93
	cmovne	%edx, %eax	# tmp91,, tmp94, _1
	movzbl	%al, %eax	# _1, _2
	movl	%eax, %esi	# _2,
	leaq	.LC5(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# overload.c:23: 	t = 16777217.0f;
	movss	.LC6(%rip), %xmm0	#, tmp95
	movss	%xmm0, -4(%rbp)	# tmp95, t
# overload.c:24: 	printf("%.1f\n",t);
	cvtss2sd	-4(%rbp), %xmm0	# t, _3
	leaq	.LC7(%rip), %rdi	#,
	movl	$1, %eax	#,
	call	printf@PLT	#
# overload.c:25: 	printf("%d\n",t == 16777217.0f?1:0);
	movss	-4(%rbp), %xmm0	# t, tmp97
	ucomiss	.LC6(%rip), %xmm0	#, tmp97
	setnp	%al	#, tmp96
	movl	$0, %edx	#, tmp99
	movss	-4(%rbp), %xmm0	# t, tmp98
	ucomiss	.LC6(%rip), %xmm0	#, tmp98
	cmovne	%edx, %eax	# tmp96,, tmp99, _4
	movzbl	%al, %eax	# _4, _5
	movl	%eax, %esi	# _5,
	leaq	.LC5(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# overload.c:27: 	t = 16777218.0f;
	movss	.LC8(%rip), %xmm0	#, tmp100
	movss	%xmm0, -4(%rbp)	# tmp100, t
# overload.c:28:         printf("%.1f\n",t);
	cvtss2sd	-4(%rbp), %xmm0	# t, _6
	leaq	.LC7(%rip), %rdi	#,
	movl	$1, %eax	#,
	call	printf@PLT	#
# overload.c:31:     return 0;
	movl	$0, %eax	#, _19
# overload.c:32: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC4:
	.long	1275068416
	.align 4
.LC6:
	.long	1266679808
	.align 4
.LC8:
	.long	1266679809
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
