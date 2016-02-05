

extern int factorial(int N);

int __main(void)
{
    int i;

    /* The largest factorial we can store in an int,
     * or an ARM register, is 12! or 479,001,600. So
     * loop from 0..12. */
    for (i = 0; i < 13; i++)
        factorial(i);
	
	return 0;
}
