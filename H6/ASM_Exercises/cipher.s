	AREA    |.text|, CODE, READONLY

;   unsigned char cipher(unsigned char c);

    EXPORT  cipher

	
	;r1 = count register	
	

cipher              	; On entry, the character is stored in R0.
	MOV r1, #5			; initialize the count register
	
loop 
	ADD r0, r0, #1		; increment the value
	SUB r1, r1, #1		; decrement counter
	CMP r0, #0x5B		; if (r0 == 'Z'+1)
	MOVEQ r0, #0x41		; r0 = 'A'
	CMP r1, #0			
	BNE loop			; while r1 != 0 

return    
	BX r14     			; Return with result in R0.

    END