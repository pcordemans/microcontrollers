	AREA    |.text|, CODE, READONLY

;   void char_reverse(char* text, int lenght);

    EXPORT  word_reverse

	;r4 count
	;r3 store the last char
	;r2 store the first char

word_reverse				; On entry, the address of the char array is in R0, and the length is provided in R1 
	MOV r4, #0				; initialize the counter
loop
	SUB r1, r1, #1			; decrement the length
	CMP r1, r4
	BLE return				; if length <= count return
	LDRB r2, [r0, r4]		; load the first char
	LDRB r3, [r0, r1]		; load the last char
	STRB r2, [r0, r1]		; store the first char in the last position
	STRB r3, [r0, r4]		; store the last char in the first position
	ADD r4, r4, #1			; increment count
	B loop					; while
	
return    
	BX r14     			; Return with result in R0.

    END