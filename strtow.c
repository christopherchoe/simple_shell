#include "shell.h"

/**
 * **strtow - splits a string into words
 *
 * @str: string to split
 * @delim: char to split str with
 * Return: pointer to array of strings, or NULL if fail
 */
char **strtow(char *str, char delim)
{
	char **a;
	int i = 0, k, n, word_count = 0, word_len = 0, current_word = 0;

	word_count = word_counter(str, delim);
	if (word_count == 0)
		return (NULL);
	a = malloc(sizeof(char *) * (word_count + 1));
	if (a == NULL)
		return (NULL);
	for (k = i; current_word < word_count && *(str + i); i++, word_len = 0, k = i)
	{
		if (*(str + i) == ':' && word_len == 0 && delim == ':')
		{
			a[current_word] = _malloc(1, a);
			if (!a[current_word])
				return (NULL);
			a[current_word++][word_len] = '\0';
			continue;
		}
		if (*(str + i) == delim)
			continue;
		while (*(str + k) != delim && *(str + k++))
			word_len++;
		a[current_word] = _malloc(word_len + 2, a);
		if (!a[current_word])
			return (NULL);
		for (n = 0; i < k; i++, n++)
			a[current_word][n] = *(str + i);
		a[current_word++][n] = '\0';
	}
	if (*(str + i - 1) == ':' && delim == ':')
	{
		a[current_word] = _malloc(2, a);
		if (!a[current_word])
			return (NULL);
		a[current_word][0] = '.';
		a[current_word][1] = '\0';
	}
	a[word_count] = NULL;
	return (a);
}

/**
  * _malloc - allocates memory for n chars and frees the 2D array on failure
  *
  * @n: number of chars to allocate memory for
  * @a: 2D array that string will be a part of
  * Return: the pointer to chars for which memory has been allocated
  */
char *_malloc(int n, char **a)
{
	char *ret;

	ret = malloc(sizeof(char) * n);
	if (!ret)
	{
		free_double(a);
		return (NULL);
	}
	return (ret);
}

/**
  * word_counter - counts the words in a string for strtow format
  *
  * @str: string to obtain word count from
  * @delim: char to split str with
  * Return: returns the number of words that qualify
  */
int word_counter(char *str, char delim)
{
	int i, count = 0;

	if (!str || *str == '\0')
		return (0);
	for (i = 0; *(str + i) && delim != ':'; i++)
	{
		if (*(str + i) != delim)
			count++;
		while (*(str + i) != delim && *(str + i))
			i++;
		if (!*(str + i))
			break;
	}
	if (delim != ':')
		return (count);
	for (i = 0, count = 1; *(str + i) && delim == ':'; i++)
	{
		if (*(str + i) == delim)
			count++;
	}
	return (count);
}

