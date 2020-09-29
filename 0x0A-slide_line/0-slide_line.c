#include "slide_line.h"


/**
 * slide_line - Prints out an array of integer, followed by a new line
 * @line: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 * @direction: direction
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int slide_line(int *line, size_t size, int direction)
{
	int list[size], i = 0, j = 0, k = 0, num = 0, size_n = size;
	if (line == NULL)
		return (0);
	if (direction == 0)
	{
		for (i = 0; i < size_n; i++)
		{
			if (line[i] != 0)
				list[j++] = line[i];
			line[i] = 0;
		}
		for (i = 0; i < j; i++)
		{
			if (list[i] == list[i + 1])
				line[k++] = list[i] + list[i + 1], i++;
			else if (list[i] != 0)
				line[k++] = list[i];
		}
	}
	else
	{
		for (i = size - 1; i > -1; i--)
		{
			if (line[i] != 0)
				list[j++] = line[i];
			line[i] = 0;
		}
		k = size - 1, num = j;

		for (i = 0; i < num; i++)
		{
			if (list[i] == list[i + 1])
				line[k--] = list[i] + list[i + 1], i++;
			else if (list[i] != 0)
				line[k--] = list[i];
		}
	}
	return (1);
}
