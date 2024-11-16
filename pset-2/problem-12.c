#include <stdio.h>
#define DIVISORS 500

int calculateDivisors(int n);

int main(void)
{
	/*
	PROBLEM STATEMENT: What is the value of the first triangular number (sum of the first n natural numbers) to have over five hundred divisors?
 
	The number of divisors of a number is obviously directly related to its number of prime factors. For example, consider 72.
	72 = 2^3 * 3^2 --> 1 and 72, 2 and 36, 3 and 24, 4 and 18, 6 and 12, 8 and 9 = 12 divisors. 
	There is a well-known formula for the number of divisors based on prime factorization: take the exponents of the prime factors, add one, and
	multiply them together. In the case of 72, we get 4 * 3 = 12, which is correct. There are many accessible proofs, so I won't prove it here. 
	
	We know the formula for a triangular number: T(n) = (n)(n+1)/2. This has been used in many problems before, starting with problem 1.
	We would like to calculate the number of divisors for (n/2) and (n+1), then multiply them together. Note that in practice, we take n to be even,
	then calculate divisors of n/2 and n-1 and n+1. This gives us the divisors of both T(n-1) and T(n). In the program, you will see we calculate T(n-1).

	In order for this method to work, we essentially need to prove that n/2 is coprime to both n-1 and n+1 to ensure there are no duplicates.

	Let d = gcd(n/2, n-1). This means d divides n/2 and n-1.
	Because d divides n/2, d must also divide n (by multiplication). d also divides n-1. 
	We know that consecutive integers are coprime, i.e.: gcd(n-1,n) = 1. 
	Therefore d must be 1.

	We can easily do the same with n+1. d divides n/2 and n+1, d divides n and n+1, gcd(n,n+1) = 1, so d = 1.
	Therefore, n/2 is coprime to n-1 and n+1 for all even natural numbers n.

	To reiterate, we know that given an even n, we can compute the divisors D of triangular numbers T(n-1) and T(n) by computing D(n/2), 
	then computing either D(n-1) or D(n+1) for T(n-1) and T(n) respectively. If you're confused by this, remember the formula for T(n).

	The main reason we do this is to not need to calculate T(n) more than once, because that is slow. 
	That is the beauty of this algorithm: we know about the divisors of a certain number without knowing the number itself.

	It's worth mentioning that this optimization is totally unneeded for only 500 divisors, but I learned some interesting number theory in the process.
	*/

	int n = 2, evenDivisors = 0, oddDivisors = 0; // declared outside for scope reasons
	for (int numDivisors = 0; numDivisors <= DIVISORS; n++)
	{
		if (n % 2 == 0)
		{
			evenDivisors = calculateDivisors(n / 2); // Will be used in calculation of T(n-1) and T(n+1)
			oddDivisors = calculateDivisors(n - 1);
		}
		else
		{
			// Even divisors remain the same
			oddDivisors = calculateDivisors(n); // If you consider the even factor (calculated in the last loop) to be n, this is now n+1
		}
		numDivisors = evenDivisors * oddDivisors; // Remove 1 divisor because of division by 2 in calculation of T(n)
		//printf("divisors of T(%d): %d\n", n - 1, numDivisors);
	}
	// Note that the extra n++ at the end of the loop means n-1 is transformed to n, hence the shift in the formula we use for T(n) below:
	printf("First triangular number with over %d divisors: %d", DIVISORS, ((n - 2) * (n - 1)) / 2);	
}

int calculateDivisors(int n)
{
	int primeExponent = 0, numDivisors = 1;

	while (n % 2 == 0) n /= 2, primeExponent++; // Get rid of all factors of 2 so we can do += 2 in next loop
	numDivisors *= (primeExponent + 1);

	for (int factor = 3; n > 1; factor += 2)
	{
		primeExponent = 0;
		while (n % factor == 0) n /= factor, primeExponent++;
		/* 
		This factorization strategy works by dividing by each factor until we cannot anymore.
		Note that if we ever get to a composite number c, because all of that composite number's factors have been checked already,
		t % c != 0, therefore we will not count any composites. 
		*/
		numDivisors *= (primeExponent + 1); // Divisor calculation formula mentioned in main() comment block
	}
	if (numDivisors == 1) return 2; else return numDivisors; // have to add 1 because primeness isn't accounted for
}
