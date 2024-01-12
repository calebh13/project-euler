#include <stdio.h>
int isPalindrome(int n)
{
	int digits[6] = { 0 };
	for(int i = 5; n > 0; i--)
	{
		digits[i] = n % 10; // Get last digit
		n /= 10; // Truncate last digit
		if (i < 3 && digits[i] != digits[5 - i]) return 0; // checking i < 3 is so we don't check when digits[] is not filled in
	}
	return 1;
}

int main(void)
{
	/*
	Consider the naive way: Compute a * b and check if it is a palindrome, where a and b range from 100 to 999. This is initially a search space of 810,000. Let's reduce it.
	We should use nested for loops beginning at 999, and every time we find a palindrome inside the inner loop, break out (because obviously the numbers will just decrease from there on out).
	Also, when the value of the outer loop * 999 is less than the current maximum palindrome, we can stop, because we know we will never find any larger palindromes.
	*/
	int a, b, curProduct, maxPalindrome = 0;	
	for (a = 999; a >= 100; a--)
	{
		if (a * 999 < maxPalindrome) break; // we would then be unable to find any larger palindromes
		for (b = 999; b >= 100; b--)
		{
			curProduct = a * b; // Don't repeat the multiplication for speed
			if (isPalindrome(curProduct))
			{
				if (curProduct > maxPalindrome) maxPalindrome = curProduct;
				break;
			}
		}
	}
	printf("Max palindrome: %d\n", maxPalindrome);
}
