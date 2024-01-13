#include <stdio.h>

int main(void)
{
	/*
	The square of the sum of the first 100 natural numbers is (n(n+1)/2)^2, by the formula used in problem 1.
	However, now we need to find a formula for the sum of squares.
	Squares: 1 + 4 + 9 + 16 + 25 + 36 + ...
	Sum of squares: 1, 5, 14, 30, 55, 91, ...
	Let's look at the discrete derivatives:
	(0), 4, 9, 16, 25, 36, ... This makes sense, because the terms of the sum are n^2, so it will increase by n^2 each time.
	So basically, f(n+1) - f(n) = (n+1)^2, so our actual function should be some sort of cubic. Discrete integration does not work the same,
	so let's find the coefficients for some cubic an^3 + bn^2 + cn + d.
	For n = 0, we have f(n) = 0, so d = 0.
	For n = 1, we have a + b + c = 1.
	For n = 2, we have 8a + 4b + 2c = 5. 
	For n = 3, we have 27a + 9b + 3c = 14.
	For n = 4, we have 64a + 16b + 4c = 30.
	This will now be enough to solve via elementary row operations (3 equations and 3 unknowns). Put the terms into an augmented matrix like so:
	{{1,1,1,1},{8,4,2,5},{27,9,3,14}}. Through Gaussian elimination, we can solve the linear system and get a = 1/3, b = 1/2, and c = 1/6.
	So f(n) appears to be equal to (2n^3 + 3n^2 + n)/6. We can factor out the n, and get n(2n^2 + 3n + 1)/6
	Factor the quadratic: (n)(2n+1)(n+1)/6. This is a nice expression. Let's now try to prove that it is equal for all n via induction.
	Base case: n=1. Let's test. (1)(2+1)(1+1)/6 = (1)(3)(2)/6 = 6/6 = 1. That is correct.
	Now, we need to prove it increases by (n+1)^2 when going to n+1.
	So (n+1)(2(n+1)+1)((n+1)+1)/6 - (n)(2n+1)(n+1)/6 SHOULD = n^2. Let's evaluate.
	(n+1)(2n+3)(n+2)/6 - (2n^3 + 3n^2 + n)/6 = 1/6((2n^3 + 9n^2 + 13n + 6) - (2n^3 + 3n^2 + n))
	= 1/6(0n^3 + 6n^2 + 12n + 6) = n^2 + 2n + 1 = (n+1)^2 by factoring. So, the base case is correct, and the n+1 case is correct, so therefore
	this function is equal to the sum of squares for all n.
	Let's now compute the problem.
	*/

	long squareOfSum = (100 * (101) / 2); // sum of natural numbers <= 100
	squareOfSum *= squareOfSum; // square it

	long sumOfSquares = (100) * (201) * (101) / 6; // use formula we proved earlier
	long difference = squareOfSum - sumOfSquares;
	printf("Difference: %ld\n", difference);
}
