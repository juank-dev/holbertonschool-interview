#include "slide_line.h"


/**
 * slide_line - Prints out an array of integer, followed by a new line
 *
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: direction
 *
 * Return: 0 - EXIT_SUCCESS or 1 - EXIT_FAILURE
 */
int slide_line(int *line, size_t size, int direction)
{

	int i = 0, j = 0, k = 0, num = 0, size_n = size, data = 0;

	if (line == NULL || (direction != 0 && direction != 1))
		return (0);

	if (direction == 0)
	{
		for (i = 0; i < size_n; i++)
		{
			if (line[i] == line[i + 1]  && line[i] != 0)
			{
				line[k++] = line[i] + line[i + 1], i++;
				line[k] = 0;
			}
			else if (line[i] != 0)
			{
				if(data == line[i])
				{
					line[--k] = data * 2;
					k++;
					data = 0;
				}
				else
					line[k++] = line[i], data = line[i];
			}
		}
		for (i = k; i < size_n; i++)
		{
			line[i] = 0;
		}

	}
	else
	{
		for (i = size - 1; i > -1; i--)
		{
			if (line[i] != 0)
				line[j++] = line[i];
			line[i] = 0;
		}
		k = size - 1, num = j;

		for (i = 0; i < num; i++)
		{
			if (line[i] == line[i + 1])
				line[k--] = line[i] + line[i + 1], i++;
			else if (line[i] != 0)
				line[k--] = line[i];
		}
	}	return (1);
}
