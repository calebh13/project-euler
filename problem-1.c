#include <stdio.h>
// Constants for easy modifiability:
#define FACTOR_1 3
#define FACTOR_2 5
#define MAX 1000

int calcSum(int multiple);

int main(void)
{
	// Goal: find sum of all multiples of 3 and 5
	// To do this we will find individually the sum of multiples of 3, then the multiples of 5, and then the multiples of 15
	// The multiples will thus be sum_3 + sum_5 - sum_15, because we will have a duplicate for every multiple of 15
	
	// We will use the Gaussian method for incremental sums: n(n+1)/2, with the n being the maximum. Note that 1 is implicitly the minimum
	// This formula is obtained by adding the lowest term to the highest, then moving inward: 1 + 999, 2 + 998, 3 + 997, etc. 
	// All terms add up to 1000 in the above case, and there will be n/2 of them. Note that for odd numbers of terms, the median is n/2 which works perfectly.
	// To modify this for multiples, we take n to be the highest multiple of the factor which is strictly less than upper bound, 
	// and then multiply the final result by the factor.
	// However, "n" is the number of terms, whereas (n+1) is the sum of 2 "opposing" terms, so we must adjust that in the formula.
	// Also, the 1 needs to be changed to the factor to reflect the actual sum of 2 opposing terms.

	int duplicate = FACTOR_1 * FACTOR_2;
	printf("Sum of 3s: %d\n", calcSum(FACTOR_1));
	printf("Sum of 5s: %d\n", calcSum(FACTOR_2));
	printf("Sum of 15s: %d\n", calcSum(duplicate));
	printf("Final result: %d\n", calcSum(FACTOR_1) + calcSum(FACTOR_2) - calcSum(duplicate));

}

int calcSum(int factor)
{
	int max = (MAX / factor) * factor; // integer division finds max multiple
	if (max == MAX) max -= factor; // strictly less than, not <=
	int numTerms = max / factor;
	return (numTerms * (max + factor)) / 2; // Gaussian method, but + 1 is changed to + factor
}
