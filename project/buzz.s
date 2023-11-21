	.arch msp430g2553
	.p2align 1,0
	.text

	.global setoff
	.extern OFFSET

setoff:
	mov r12, &OFFSET
	pop r0
	
