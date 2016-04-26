	AREA    |.text|, CODE, READONLY

;   void char_reverse(char* text, int lenght);

    EXPORT  char_reverse

	;r6 shift register
	;r3 mask
	;r5 temp register
	;r4 result register
	;r2 char store

char_reverse				; On entry, the address of the char array is in R0, and the length is provided in R1 
	LDR r2, [r0]			; load 4 chars
	MOV r4, #0				; initialize result register
	MOV r3, #0x0000FF00		; initialize the mask
	MOV r6, #8				; initialize the shift register
	
loop
	AND r5, r2, r3			; AND mask the char
	MOV r5, r5, LSL r6		; shift it into position
	ORR r4, r5				; OR mask it into the result register
	MOV r5, #0				; clear r5
	MOV r3, r3, LSL r6		; shift the mask
	AND r5, r2, r3			; AND mask a char
	MOV r5, r5, LSR r6		; shift it into position
	ORR r4, r5				; OR mask it into the result register
	MOV r3, r3, LSR #16		; shift the mask to the new position
	ADD r6, r6, #16			; change the value of the shift register
	CMP r6, #24				
	BLE	loop				; branch if less or equal than 24

	STR r4, [r0]			; store the result
	
	
return    
	BX r14     			; Return with result in R0.

    END