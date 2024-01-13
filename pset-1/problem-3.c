#include <stdio.h>
#include <math.h>
#define NUM 600851475143 // 600 billion (long long)
int isPrime(int n)
{
	if (n == 2) return 1; else if(n % 2 == 0) return 0;

	int upperBound = (int)floor(sqrt(n)) + 1; // + 1 is there for perfect squares
	for (int i = 3; i < upperBound; i += 2) // no need to check multiples of 2
	{
		if (n % i == 0) return 0; // i is a factor of n, so n is not prime
	}
	return 1;
}

int main(void)
{
	int factor = (int)(floor(sqrt(NUM))); // start at sqrt, but no need for + 1 because we are looking for prime factors
	while (1)
	{
		// note: isPrime is on right side of bool. expr. so it is evaluated ONLY if "factor" is actually a factor (isPrime is very computationally expensive)
		if (NUM % factor == 0 && isPrime(factor)) break; 
		--factor;
	}
	printf("%d\n", factor);
}
