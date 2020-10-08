#include "menger.h"

/**
 * menger - Menger sponge
 *
 * @level: level menger
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

void menger(int level)
{
	int i, j, pot_a;

	if (level < 0)
		return;

	pot_a = (int)pow(3, level);

	for (i = 0; i < pot_a; i++)
	{
		for (j = 0; j < pot_a; j++)
		{
			if (i % 3 == 1 && j % 3 == 1)
			{
				printf(" ");
				continue;
			}

			if (pot_a / 3 <= i && 2 * (pot_a / 3) > i)
			{
				if (pot_a / 3 <= j && 2 * (pot_a / 3) > j)
				{
					printf(" ");
					continue;
				}
			}

			if (validate_1(pot_a, i, j))
				continue;

			if (validate_2(i, j))
				continue;

			printf("#");
		}
		printf("\n");
	}
}

/**
 * validate_1 - Menger sponge
 *
 * @pot_a: level menger
 * @i: integer column
 * @j: integer row
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int validate_1(int pot_a, int i, int j)
{
	int k, l;

	for (k = 1; k < pot_a / 3; k += 3)
	{
		for (l = 1; l < pot_a / 3; l += 3)
		{
			if ((pot_a / 9) * k <= i && ((pot_a / 9) * k) + pot_a / 9 > i)
			{
				if ((pot_a / 9) * l <= j && ((pot_a / 9) * l) + pot_a / 9 > j)
				{
					printf(" ");
					return (1);
				}
			}
		}
	}
	return (0);
}

/**
 * validate_2 - Menger sponge
 *
 * @i: integer column
 * @j: integer row
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int validate_2(int i, int j)
{
	int k, l;

	for (k = 3; k < 6; k++)
	{
		for (l = 3; l < 6; l++)
		{
			if (i % 9 == k && j % 9 == l)
			{
				printf(" ");
				return (1);
			}
		}
	}
	return (0);
}
