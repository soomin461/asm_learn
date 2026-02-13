	.syntax unified
	.thumb

	.text

    .extern  HardFault_Handler
    .extern  MemManage_Handler
    .extern  BusFault_Handler
    .extern  UsageFault_Handler

    .global _HardFault_Handler
  	.type 	_HardFault_Handler, %function
_HardFault_Handler:

	MOV		R0, SP
	MOV		R1, LR
	MRS		R2, PSP
	B		HardFault_Handler

    .global _MemManage_Handler
  	.type 	_MemManage_Handler, %function
_MemManage_Handler:

	MOV		R0, SP
	MOV		R1, LR
	MRS		R2, PSP
	B		MemManage_Handler

    .global _BusFault_Handler
  	.type 	_BusFault_Handler, %function
_BusFault_Handler:

	MOV		R0, SP
	MOV		R1, LR
	MRS		R2, PSP
	B		BusFault_Handler

    .global _UsageFault_Handler
  	.type 	_UsageFault_Handler, %function
_UsageFault_Handler:

	MOV		R0, SP
	MOV		R1, LR
	MRS		R2, PSP
	B		UsageFault_Handler

	.equ	ICSR, 	0xE000ED04

    .global NMI_Gen
  	.type 	NMI_Gen, %function
NMI_Gen:

	PUSH	{R0, LR}
	LDR		r0, =ICSR
	LDR		r1, [r0]
	ORR		r1, r1, #(1<<31)
	STR		r1, [r0]
	POP		{R0, PC}

    .global PendSV_Gen
  	.type 	PendSV_Gen, %function
PendSV_Gen:

	PUSH	{R0, LR}
	LDR		r0, =ICSR
	LDR		r1, [r0]
	ORR		r1, r1, #(1<<28)
	STR		r1, [r0]
	POP		{R0, PC}


    .global _SVC_Handler
  	.type 	_SVC_Handler, %function
_SVC_Handler:

	.extern SVC_FUNC
	
	@ SVC 핸들러 설계
	PUSH	{r4, lr}

	mrs		lr, PSP
	LDR		r12, [lr, #0x18]		@r12 := Return Addr
	LDRB	R12, [R12, #-2]			@ imm8
	LDR		LR, =SVC_FUNC
	
	LDR		R12, [LR, R12, LSL #2]	@ R12:= SVC_FUNC
	BLX		R12
	mrs  	r4, psp
	stmia	r4, {r0, r1}
	POP		{r4, pc}



@ System Call Service APIs @

    .global PRT
  	.type 	PRT, %function
PRT:

	SVC   	0
	BX    	lr

    .global SQR
  	.type 	SQR, %function
SQR:

	SVC   	1
	BX    	lr

    .global ADD_DBL
  	.type 	ADD_DBL, %function
ADD_DBL:

	SVC   	2
	BX    	lr

	.end
