#include <stdio.h>
#define MAX_TERM_VALUE 4000000

int main(void)
{
	long long sum = 2;
	int curTerm = 2, prevTerm = 1, prevPrevTerm = 1;
	// Note: if you start with 1, 1, 2, then the pattern for the Fibonacci sequence is "odd-odd-even".
	// So, we just need to add every third term.
	for (int termNum = 4; curTerm <= MAX_TERM_VALUE; termNum++)
	{
		// Shift terms
		prevPrevTerm = prevTerm;
		prevTerm = curTerm;
		// Make new term
		curTerm = prevTerm + prevPrevTerm;
		if (termNum % 3 == 0) // This is slightly faster by not performing modulo on numbers in the millions
		{
			sum += curTerm;
		}
	}
	printf("%lld\n", sum);
}
