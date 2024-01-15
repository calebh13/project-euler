#include <stdio.h>
#define MINIMUM 53

int calcProduct(int table[20][20], int row, int col, int rowDir, int colDir)
{
	if ((row + rowDir * 3 >= 20 || row + rowDir * 3 < 0) || (col + colDir * 3 >= 20 || col + colDir * 3 < 0)) return 0; // goes out of bounds
	int product = 1, curNum = 0;

	for (int increment = 1; increment <= 3; increment++)
	{
		curNum = table[row + rowDir * increment][col + colDir * increment];
		if (curNum < MINIMUM)
		{
			return 0;
		}
		else
		{
			product *= curNum;
		}
	}

	return table[row][col] * product; // save this final multiplication for the end so we might save on a multiplication for a bad set
}

int main(void)
{
	int table[20][20] =
	//0 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19
	{{8,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91, 8},
	{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00},
	{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65},
	{52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91},
	{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
	{24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50},
	{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
	{67,26,20,68,02,62,12,20,95,63,94,39,63, 8,40,91,66,49,94,21},
	{24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
	{21,36,23, 9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95},
	{78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14, 9,53,56,92},
	{16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57},
	{86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58},
	{19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40},
	{04,52, 8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66},
	{88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69},
	{04,42,16,73,38,25,39,11,24,94,72,18 ,8,46,29,32,40,62,76,36},
	{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16},
	{20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54},
	{01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48}};

	/*
	For this problem, I'll be utilizing a heuristic based on a large product I found while quickly glancing at the table.
	In the 7th row, 4th-to-last column, we have 66. Moving downwards, we get 66 * 91 * 88 * 97.
	Unfortunately I had to replace all 08 and 09s with 8 and 9 respectively as C was interpreting them as octal (and I guess nonal???) digits.
	Anyway, to get a bigger product than that, assuming 3 99's, the lowest possible value would be 53. This is because 66 * 91 * 88 * 97 / (99^3) = 52.8.
	So if there is anything lower than a 53, we know it cannot possibly be bigger than the product I found, therefore we don't need to bother multiplying, which is
	an expensive operation. I don't think there are any other ways to really optimize this without using some sort of brute-force technique, as there doesn't appear
	to be much of a pattern to the data.
	*/
	int maxProduct = 0, curProduct = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			// Calculate all 8 directional products
			if (table[i][j] < MINIMUM) continue;
			for (int rowDir = -1; rowDir <= 1; rowDir++)
			{
				for (int colDir = -1; colDir <= 1; colDir++)
				{
					if (rowDir == 0 && colDir == 0) continue; // We don't want to stay in the same spot
					curProduct = calcProduct(table, i, j, rowDir, colDir);
					if (curProduct > maxProduct)
					{
						maxProduct = curProduct;
						printf("New max %d at (%d, %d). Directions: down %d, right %d\n", maxProduct, i, j, rowDir, colDir);
					}
				}
			}
		}
	}
	printf("Final max product: %d\n", maxProduct);
}
