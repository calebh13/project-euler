#include <stdio.h>
#include <stdlib.h> // malloc
int main(void)
{
	/* 
 	   For this problem we will use the well-known Sieve of Eratosthenes
	   For a rough heuristic for how much memory we need to allocate, I used the prime number theorem:
	   The prime counting function is roughly equivalent to x/log(x), and x/log(x) surpasses 10000 at roughly x = 110,000, so we will
	   allocate roughly 200,000 integers, thus we need to allocate 800KB of memory, which isn't terrible.
	*/
	int* primes = malloc(sizeof(int) * 200000); 
	if (!primes)
	{
		printf("Error allocating memory\n");
		return 1; 
	}
	int primeCounter = 0;
	for (int i = 0; i < 200000; i++)
	{
		primes[i] = 1; // initialize everything to 1, as we will set to 0 when we are sure it is not prime
	}

	for (int i = 2; i < 200000; i++) // note that we aren't using all 200,000 integers for nicer indexing
	{
		if (primes[i]) primeCounter++;
		if (primeCounter == 10001)
		{
			printf("%d\n", i);
			break;
		}
		for (int j = i; j < 200000; j += i)
		{
			primes[j] = 0; // j is not prime because it's a multiple of i
		}
	}
	free(primes);
	return 0;
}
