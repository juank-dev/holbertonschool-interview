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
	int i, j, k, pot_a, flag = 0;

	if (level < 0)
		return;

	pot_a = (int)pow(3, level);

	for (i = 0; i < pot_a; i++)
	{
		for (j = 0; j < pot_a; j++)
		{
			flag = 0;

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

			for (k = 1; k < pot_a / 3; k += 3)
			{
				for (int l = 1; l < pot_a / 3; l += 3)
				{
					if ((pot_a / 9) * k <= i && ((pot_a / 9) * k) + pot_a / 9 > i)
					{
						if ((pot_a / 9) * l <= j && ((pot_a / 9) * l) + pot_a / 9 > j)
						{
							printf(" ");
							flag = 1;
						}
					}
				}
			}
			if (flag)
				continue;
			for (k = 3; k < 6; k++)
			{
				for (int l = 3; l < 6; l++)
				{
					if (i % 9 == k && j % 9 == l)
					{
						printf(" ");
						flag = 1;
						continue;
					}
				}
			}
			if (flag)
				continue;

			printf("#");
		}
		printf("\n");
	}
}
