#include "substring.h"

/**
 * find_substring -  finds all the possible substrings
 * @s: string to search
 * @words: array of words all substrings must be a concatenation
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the number of elements in the
 * returned array.
 * Return:  an allocated array, storing each index in s, at which a
 * substring was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{

	int index_currently, count, length, length_word, validate, i, j, k;
	int *match, *idx_array;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);
	length = strlen(s);
	length_word = strlen(words[0]);
	idx_array = malloc(length * sizeof(int));
	if (!idx_array)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);
	for (i = count = 0; i <= length - nb_words * length_word; i++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				index_currently = i + j * length_word;
				validate = strncmp(s + index_currently, *(words + k), length_word);
				if (!*(match + k) && !validate)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(idx_array + count) = i, count += 1;
	}
	free(match);
	*n = count;
	return (idx_array);
}
