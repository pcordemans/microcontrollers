	AREA    |.text|, CODE, READONLY

;   int asciiToBCD(int ascii);

    EXPORT  asciiToBCD
		

	;r6 = ascii value offset register
	;r5 = mask register upper nibble
	;r4 = mask register lower nibble
	;r3 = temp value register
	;r2 = nibble test register 
	;r1 = temp argument register	
	

asciiToBCD              ; On entry, the ascii value is stored in R0.
	MOV r1, r0			; move the argument to the temp register
	MOV r0, #0			; clear the return register
	MOV r4, #0xF		; initial lower nibble mask
	MOV r5, #0xF0		; initial upper nibble mask
	MOV r6, #0x30		; initial ascii value offset
	
loop	
	AND r2, r1, r5		; select the upper nibble
	TEQ r2, r6			; check if the ascii value corresponds with a numeral value
	BNE return			; if not return the value
	AND	r3, r1, r4		; else select the first nibble
	ORR r0, r3			; and append it to the result
	 
	MOV r1, r1, LSR #0x4	; shift one nibble to the right
	MOV r4, r4, LSL #0x4	; shift one nibble to the left
	MOV r5, r5, LSL #0x4	; shift one nibble to the left
	MOV r6, r6, LSL #0x4	; shift one nibble to the left
	B loop				; return to loop
	

return    
	BX r14     			; Return with result in R0.

    END