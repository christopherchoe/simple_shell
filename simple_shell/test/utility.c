#include "shell.h"

/**
 * _strlen - return length of a string
 * @s: char pointer for string to measure length
 * Return: length of string, n
 */
int _strlen(char *s)
{
	int n, i;

	n = 0;
	for (i = 0; *(s + i) != '\0'; i++)
		n++;

	return (n);
}

/**
 * *_strcmp - compares two string
 *
 * @s1: first string
 * @s2: second string
 * Return: int difference between s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);

	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 - *s2 != 0)
			return (*s1 - *s2);
		if (*(s1) != '\0')
			s1++;
		if (*(s2) != '\0')
			s2++;
	}
	return (0);
}

