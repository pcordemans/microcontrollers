

extern int asciiToBCD(int ascii);
extern int BCDToAscii(int bcd);
extern unsigned char cipher(unsigned char c);
extern unsigned char ccipher(unsigned char c, unsigned char shift);
extern int bit_reverse (int b);
extern void fib(int n, int* store);
extern void char_reverse(char* text, int length);
extern void word_reverse(char* text, int length);

void word_reverse_compiled(char* text, int length){
	char temp;	
	int i;
	for ( i = 0; i < length / 2; i++) {
				temp = text[i];
				text[i] = text[length - 1 - i];
				text[length - 1 - i] = temp;
		}			
}

int __main(void)
{
  int store [20];
	volatile unsigned char r;  
	char text [] = "1234";
	char test [] = "hello";
	volatile int result = asciiToBCD(0x30);
	result = asciiToBCD(0x3239);	
	result = BCDToAscii(0x1234);
	result = BCDToAscii(0x0);
	r = cipher('A');
	r = cipher('Z');
	r = ccipher('A', 5);
	result = bit_reverse(0xAAAA0000);
	fib(20, store);
	char_reverse(text, 4);
	
	word_reverse(text, 4);
	word_reverse(test, 5);
	
	word_reverse_compiled(text, 4);
	word_reverse_compiled(test, 5);
		
	return 0;
}


