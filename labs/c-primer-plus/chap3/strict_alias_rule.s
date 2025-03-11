	.file	"strict_alias_rule.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.2) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu strict_alias_rule.c
# -mtune=generic -march=x86-64 -O2 -fno-strict-aliasing -fverbose-asm
# -fasynchronous-unwind-tables -fstack-protector-strong -Wformat
# -Wformat-security -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -falign-functions -falign-jumps -falign-labels -falign-loops
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcaller-saves -fcode-hoisting
# -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
# -fcrossjumping -fcse-follow-jumps -fdefer-pop
# -fdelete-null-pointer-checks -fdevirtualize -fdevirtualize-speculatively
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fexpensive-optimizations -fforward-propagate -ffp-int-builtin-inexact
# -ffunction-cse -fgcse -fgcse-lm -fgnu-runtime -fgnu-unique
# -fguess-branch-probability -fhoist-adjacent-loads -fident -fif-conversion
# -fif-conversion2 -findirect-inlining -finline -finline-atomics
# -finline-functions-called-once -finline-small-functions -fipa-bit-cp
# -fipa-cp -fipa-icf -fipa-icf-functions -fipa-icf-variables -fipa-profile
# -fipa-pure-const -fipa-ra -fipa-reference -fipa-reference-addressable
# -fipa-sra -fipa-stack-alignment -fipa-vrp -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots
# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
# -fmath-errno -fmerge-constants -fmerge-debug-strings
# -fmove-loop-invariants -fomit-frame-pointer -foptimize-sibling-calls
# -foptimize-strlen -fpartial-inlining -fpeephole -fpeephole2 -fplt
# -fprefetch-loop-arrays -free -freg-struct-return -freorder-blocks
# -freorder-blocks-and-partition -freorder-functions -frerun-cse-after-loop
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fschedule-insns2
# -fsemantic-interposition -fshow-column -fshrink-wrap
# -fshrink-wrap-separate -fsigned-zeros -fsplit-ivs-in-unroller
# -fsplit-wide-types -fssa-backprop -fssa-phiopt -fstack-clash-protection
# -fstack-protector-strong -fstdarg-opt -fstore-merging
# -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim
# -ftree-dce -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop -ftree-pre
# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr
# -ftree-sra -ftree-switch-conversion -ftree-tail-merge -ftree-ter
# -ftree-vrp -funit-at-a-time -funwind-tables -fverbose-asm
# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.p2align 4
	.globl	set_value
	.type	set_value, @function
set_value:
.LFB23:
	.cfi_startproc
	endbr64	
# strict_alias_rule.c:8: 	*i = 0x3F800000;
	movl	$1065353216, (%rsi)	#, *i_2(D)
# strict_alias_rule.c:9: 	*f = 2.0f;
	movl	$0x40000000, (%rdi)	#, *f_4(D)
# strict_alias_rule.c:10: }
	ret	
	.cfi_endproc
.LFE23:
	.size	set_value, .-set_value
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%d "
	.text
	.p2align 4
	.globl	inf_while
	.type	inf_while, @function
inf_while:
.LFB24:
	.cfi_startproc
	endbr64	
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:107:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	movl	$1, %edi	#,
	xorl	%edx, %edx	#
	xorl	%eax, %eax	#
	leaq	.LC1(%rip), %rsi	#,
	call	__printf_chk@PLT	#
	movl	$10, %edi	#,
# strict_alias_rule.c:57: }	
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 8
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:107:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	jmp	putchar@PLT	#
	.cfi_endproc
.LFE24:
	.size	inf_while, .-inf_while
	.p2align 4
	.globl	access_struct
	.type	access_struct, @function
access_struct:
.LFB25:
	.cfi_startproc
	endbr64	
# strict_alias_rule.c:71: 	a->x = 100;
	movl	$100, (%rdi)	#, a_2(D)->x
# strict_alias_rule.c:72: 	b->y = 200.0f;
	movl	$0x43480000, (%rsi)	#, b_4(D)->y
# strict_alias_rule.c:73: }
	ret	
	.cfi_endproc
.LFE25:
	.size	access_struct, .-access_struct
	.section	.rodata.str1.1
.LC4:
	.string	"Result: %.2f\n"
	.text
	.p2align 4
	.globl	calc
	.type	calc, @function
calc:
.LFB26:
	.cfi_startproc
	endbr64	
# strict_alias_rule.c:86:     *f = 3.14f;
	movl	$0x4048f5c3, (%rdi)	#, *f_4(D)
# strict_alias_rule.c:88:     printf("Result: %.2f\n", *f);
	pxor	%xmm0, %xmm0	# tmp87
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:107:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	movl	$1, %eax	#,
# strict_alias_rule.c:87:     *i = 100.0f;
	movl	$100, (%rsi)	#, *i_6(D)
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:107:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	leaq	.LC4(%rip), %rsi	#,
# strict_alias_rule.c:88:     printf("Result: %.2f\n", *f);
	cvtss2sd	(%rdi), %xmm0	# *f_4(D), tmp87
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:107:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	movl	$1, %edi	#,
	jmp	__printf_chk@PLT	#
	.cfi_endproc
.LFE26:
	.size	calc, .-calc
	.section	.rodata.str1.1
.LC5:
	.string	"test set value start:"
.LC7:
	.string	"result: 0x%X (%.2f)\n"
.LC8:
	.string	"test inf while start:"
.LC9:
	.string	"test access struct start:"
.LC11:
	.string	"x=%d,y=%.1f\n"
.LC12:
	.string	"test calc start:"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB27:
	.cfi_startproc
	endbr64	
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:107:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	leaq	.LC5(%rip), %rdi	#,
	call	puts@PLT	#
	movl	$1073741824, %edx	#,
	movl	$1, %edi	#,
	movsd	.LC6(%rip), %xmm0	#,
	leaq	.LC7(%rip), %rsi	#,
	movl	$1, %eax	#,
	call	__printf_chk@PLT	#
	leaq	.LC8(%rip), %rdi	#,
	call	puts@PLT	#
# strict_alias_rule.c:101: 	inf_while();
	xorl	%eax, %eax	#
	call	inf_while	#
# /usr/include/x86_64-linux-gnu/bits/stdio2.h:107:   return __printf_chk (__USE_FORTIFY_LEVEL - 1, __fmt, __va_arg_pack ());
	leaq	.LC9(%rip), %rdi	#,
	call	puts@PLT	#
	movl	$1128792064, %edx	#,
	movl	$1, %edi	#,
	movsd	.LC10(%rip), %xmm0	#,
	leaq	.LC11(%rip), %rsi	#,
	movl	$1, %eax	#,
	call	__printf_chk@PLT	#
	leaq	.LC12(%rip), %rdi	#,
	call	puts@PLT	#
	movl	$1, %edi	#,
	movl	$1, %eax	#,
	movsd	.LC13(%rip), %xmm0	#,
	leaq	.LC4(%rip), %rsi	#,
	call	__printf_chk@PLT	#
# strict_alias_rule.c:114: }
	xorl	%eax, %eax	#
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE27:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC6:
	.long	0
	.long	1073741824
	.align 8
.LC10:
	.long	0
	.long	1080623104
	.align 8
.LC13:
	.long	0
	.long	923336704
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
