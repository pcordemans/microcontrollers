	AREA    |.text|, CODE, READONLY

;   int bit_reverse (int b);

    EXPORT  bit_reverse

	
	;r5 = shift counter
	;r4 = temp store
	;r3 = mask 
	
	;r2 = temp value
	;r1 = temp input value store	
	

bit_reverse				; On entry, the value is stored in R0 
	MOV r1, r0			; copy the value in r0 to r1
	MOV r0, #0			; clear r0
	MOV r3, #0x10001	; set bit 16 and bit 1 in bit mask
	
	MOV r5, #1			; initialise shift counter with 1
	
loop
	AND r4, r1, r3		; select bits
	MOV r4, r4, ROR r5	; rotate bits into position
	ORR r0, r0, r4		; append to the result
	MOV r3, r3, LSL #1	; shift the mask one left
	ADD r5, r5, #2		; increment shift counter with 2
	CMP r5, #33			; while the shift counter is lower than 33
	BNE loop

return    
	BX r14     			; Return with result in R0.

    END