#include <stdio.h>
#include <stdlib.h> // malloc
#define MAX 2000000
int main(void)
{
	/*
	   For this problem we will again the well-known Sieve of Eratosthenes
	   This time, we need to check all primes under 2 million, so we need to allocate 2MB for the array. 2 million seems like a large array, but it's
	   surprisingly small when you think of it in terms of MB. This problem also was my fastest so far; it took about 30 seconds of actual coding.
	*/
	int* primes = malloc(sizeof(int) * MAX);
	long long sum = 0;
	if (!primes)
	{
		printf("Error allocating memory\n");
		return 1;
	}
	for (int i = 0; i < MAX; i++)
	{
		primes[i] = 1; // initialize everything to 1, as we will set to 0 when we are sure it is not prime
	}

	for (int i = 2; i < MAX; i++) // note that we aren't using all 200,000 integers for nicer indexing
	{
		if (primes[i]) sum += i;
		for (int j = i; j < MAX; j += i)
		{
			primes[j] = 0; // j is not prime because it's a multiple of i
		}
	}
	free(primes);
	printf("Sum: %lld\n", sum);
	return 0;
}
