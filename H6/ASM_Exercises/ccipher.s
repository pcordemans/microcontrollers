	AREA    |.text|, CODE, READONLY

;   unsigned char ccipher(unsigned char c, unsigned char shift);

    EXPORT  ccipher

	
	;r2 = count register	
	

ccipher              	; On entry, the character is stored in R0 and shift value in R1
	
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