#include <iostream>

int main(void)
{
    /*
    When you start in a 2x2, you have to go right twice and down twice. 
    This means we need to know the number of permutations of RRDD.

    More generally, ABCD has n! permutations.
    However, for our purposes, AB = BA. This reduces the number of permutations we care about by a factor of 2!. 
    We also have CD = DC, which again reduces it by a factor of 2!.

    For a 3x3, we would have ABCDEF, giving 6! combinations. 
    ABC = ACB = CAB = ... which has 3! permutations. 
    Also, DEF = DFE = FDE = ..., giving another factor of 3! reduction.

    Thus, for an nxn grid, we will have ((2n)!)/((n!)^2)possible paths. Represented as a descending product, we have

    ((2n) * (2n - 1) * (2n - 2) * ... * (n+1))  /  ((n) * (n-1) * ... * (1)) 

    So a 20x20 grid will have 40 * 39 * 38 * ... * 21, then divided by (20 * 19 * 18 * ... * 1), paths.
    */

    unsigned long long paths = 1;
    for (int i = 40; i > 20; i--)
    {
        paths *= i; // Compute (2n!)
        if (i % 2 == 0) paths /= (i / 2); // Divide by n! as we go (to prevent overflow)
    }
    for (int i = 10; i > 0; i--)
    {
        paths /= i; // Divide by the rest of n!
    }
    std::cout << "Number of paths in a 20x20 lattice: " << paths << "\n";
}
