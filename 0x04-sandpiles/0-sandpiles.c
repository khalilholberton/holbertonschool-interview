#include "sandpiles.h"
#include <stdio.h>
#include <string.h>
/**
 * tot - add func
 * @grid1: matrix
 * @grid2: matrix
 */
static void tot(int grid1[3][3], int grid2[3][3])
{
	int a;
	int b;

	a = 0;

	while (a < 3)
	{
		for (b = 0; b < 3; b++)
		{
			grid1[a][b] += grid2[a][b], grid2[a][b] = 0;
		}
	a++;
	}
}

/**
 * fixed - verify if the snadpile is stable.
 * @grid: matrix.
 * Return: 1 if stable, 0 otherwise.
 */
static int fixed(int grid[3][3])
{
	int a;
	int b;

	a = 0;

	while (a < 3)
	{
		for (b = 0; b < 3; b++)
			if (grid[a][b] > 3)
			return (0);
		a++;
	}
	return (1);
}
/**
 * display - print the grid
 * @grid: matrix
 * Return: 1 if stable, 0 otherwise.
 */
static void display(int grid[3][3])
{
	int a;
	int b;

	a = 0;
	printf("=\n");
	while (a < 3)
	{
		for (b = 0; b < 3; b++)
		{
			if (b)
				printf(" ");
			printf("%d", grid[a][b]);
		}
		printf("\n");
		a++;
	}
}

/**
 * factory - factory matrix.
 * @grid1: sandpile.
 * @grid2: sandpile.
 */
static void factory(int grid1[3][3], int grid2[3][3])
{
	int a;
	int b;

	a = 0;

	while (a < 3)
	{
		for (b = 0; b < 3; b++)
			if (grid1[a][b] > 3)
			{
				grid1[a][b] -= 4;
				if (a - 1 >= 0)
					grid2[a - 1][b]++;
				if (a + 1 < 3)
					grid2[a + 1][b]++;

				if (b - 1 >= 0)
					grid2[a][b - 1]++;
				if (b + 1 < 3)
					grid2[a][b + 1]++;
			}
		a++;
	}
}

/**
 * sandpiles_sum - regroup all func.
 * @grid1: sandpile.
 * @grid2: sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	tot(grid1, grid2);
	while (!fixed(grid1))
	{
		display(grid1);
		factory(grid1, grid2);
		tot(grid1, grid2);
	}
}
