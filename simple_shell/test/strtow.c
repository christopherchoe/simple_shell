#include "shell.h"

/**
 * **strtow - splits a string into words
 *
 * @str: string to split
 * Return: pointer to array of strings, or NULL if fail
 */
char **strtow(char *str)
{
	char **a;
	int i, k, n, word_count = 0, word_len = 0, current_word = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = word_counter(str);

	if (word_count == 0)
		return (NULL);

	a = malloc(sizeof(char *) * (word_count + 1));
	if (a == NULL)
		return (NULL);
	for (i = 0, k = i; current_word < word_count; i++, word_len = 0, k = i)
	{
		if (*(str + i) == ' ')
			continue;
		while (*(str + k) != ' ' && *(str + k++))
			word_len++;
		a[current_word] = malloc(sizeof(char) * word_len + 2);
		if (!a[current_word])
		{
			free_double(a);
			return (NULL);
		}
		for (n = 0; i < k; i++, n++)
			a[current_word][n] = *(str + i);
		a[current_word++][n] = '\0';
	}
	a[word_count] = NULL;
	return (a);
}

/**
  * word_counter - counts the words in a string for strtow format
  *
  * @str: string to obtain word count from
  * Return: returns the number of words that qualify
  */
int word_counter(char *str)
{
	int i, count = 0;

	if (!str)
		return (0);
	for (i = 0; *(str + i); i++)
	{
		if (*(str + i) != ' ')
			count++;
		while (*(str + i) != ' ' && *(str + i))
			i++;
		if (!*(str + i))
			break;
	}
	return (count);
}

