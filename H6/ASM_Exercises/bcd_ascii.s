	AREA    |.text|, CODE, READONLY

;   int BCDToAscii(int bcd);

    EXPORT  BCDToAscii
		

	
	;r5 = ascii value register
	;r4 = count register
	;r3 = temp value register
	;r2 = mask register 
	;r1 = temp argument register	
	

BCDToAscii              ; On entry, the bcd value is stored in R0.
	MOV r1, r0			; move the argument to the temp register
	MOV r0, #0			; clear the return register
	
	MOV r2, #0xF000		; load the initial mask
	MOV r5, #0x30000	; load the initial ascii value
	MOV r4, #0x10			; initialize the count register
				
	
loop 
	SUB r4, r4, #0x4		; decrement the count to select the next nibble
	AND r3, r1, r2		; select the next BCD value from r1 and store it in r3
	ADD	r3, r3, r5		; add 0x30 to that value
	MOV r3, r3, LSL r4  ; shift the value to the correct position
	ORR r0, r0, r3		; append the result
	MOV r2, r2, LSR #0x4  ; shift the mask one nibble
	MOV r5, r5, LSR #0x4  ; shift the ascii value one nibble
	CMP R4, #0x0
	BNE loop			; return if r4 == 0	

return    
	BX r14     			; Return with result in R0.

    END