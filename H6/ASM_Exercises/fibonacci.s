	AREA    |.text|, CODE, READONLY

;   void fib(int n, int* store);

    EXPORT  fib

	;r4 = temp 
	;r2 = fib1
	;r3 = fib0	

fib						; On entry, the number of requires elements is stored in R0, and the array pointer is provided in R1 
	MOV r3, #0			; initialize fib(0) with 0
	STR r3, [r1], #4	; store contents of r3 into the array then increment
	MOV r2, #1			; initialize fib(1) with 1
	STR r2, [r1], #4	; store contents of r2 into the array then increment
	SUB r0, r0, #2		; subtract 2 of count as two elements are given

loop
	
	MOV r4, r2			; temp = r2
	ADD r2, r2, r3		; add both fib number and store result in r2
	STR r2, [r1], #4	; store contents of r2 into the array then increment
	MOV r3, r4			; r3 = temp
	SUB r0, r0, #1		; decrement count
	CMP r0, #0			; while r0 != 0
	BNE loop
	
	
return    
	BX r14     			; Return with result in R0.

    END