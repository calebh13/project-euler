#include <stdio.h>
#include <stdlib.h>
#define MAX 200000000

/* 
Problem statement: the following iterative sequence is defined for positive integers:
n -> n/2 if n is even
n -> 3n+1 if n is odd
Which starting number, under 1 million, produces the longest chain? 
*/

long long col(long long n)
{
	if (n % 2 == 0) return n / 2;
	else return (3 * n + 1) / 2; // "shortcut" collatz
}

int main(void)
{
	/*
	My original plan for this was to make an array of integers with an index for every natural number. Then we would go through various Collatz chains,
	and keep track of the terms in a different array. Once that was finished, we would iterate backwards and put the number of terms until 0 is reached in
	the previously mentioned array. However, this would require an array with 450 GB of space, which is unfortunately not possible on my laptop.
	If you have a supercomputer, I suggest you utilize that method. For this program, I will be modifying that strategy and only tracking terms
	which are less than 200,000,000. This will require ~800MB of RAM.
	*/
	int* termsTillOne = calloc(MAX, sizeof(int)); // index of this array is the collatz term itself
	long long* terms = malloc(200000 * sizeof(long long)); // index n of this array is the nth term in an ongoing collatz sequence
	int curMaxTerms = 0, maxNum = 0;
	if (!termsTillOne || !terms)
	{
		printf("Error allocating memory. Exiting ...\n");
		return 1;
	}
	for (int n = 2; n < 1000000; n++)
	{
		int counter = 0, termsCalculated = 0;
		for (long long term = n; term != 1; term = col(term), counter++)
		{
			terms[counter] = term;
			if (term < MAX && termsTillOne[term] != 0) // This term has been reached in a previous sequence
			{
				termsCalculated = counter;
				// If we don't use termsCalculated, we will be accessing values of terms[] from previous iterations, so we need to make sure
				// in the next loop that we don't access terms that we didn't actually calculate. However, we still need to increment counter for the
				// sake of correct values for termsTillOne.
				counter += termsTillOne[term];
				break;
			}
			termsCalculated = counter;
		}

		for (int i = 0; i < termsCalculated; i++)
		{
			if (terms[i] < MAX)
			{
				termsTillOne[terms[i]] = counter - i;
			}
		}

		if (counter > curMaxTerms)
		{
			curMaxTerms = counter;
			printf("New max: %d with %d terms\n", n, curMaxTerms);
			maxNum = n;
		}
	}
	
	printf("Final max: %d with %d terms\n", maxNum, curMaxTerms);
	return 0;
}
