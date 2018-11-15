#include "shell.h"

/**
  * _strcat_dir - concatenates two strings with a slash for directories
  *
  * @dest: first string
  * @src: second string
  * Return: dest which will have concatenated string
  */
char *_strcat_dir(char *dest, char *src)
{
	char *cat;
	int i, k = 0;

	if (!dest || !src)
		return (NULL);

	cat = malloc(sizeof(char) * (_strlen(dest) + _strlen(src) + 2));
	if (!cat)
		return (NULL);

	for (i = 0; i < _strlen(dest); i++)
		*(cat + k++) = *(dest + i);

	*(cat + k++) = '/';

	for (i = 0; i < _strlen(src); i++)
		*(cat + k++) = *(src + i);

	*(cat + k) = '\0';

	return (cat);
}

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

	while (*s1 || *s2)
	{
		if (*s1 - *s2 != 0)
			return (*s1 - *s2);
		if (*(s1))
			s1++;
		if (*(s2))
			s2++;
	}
	return (0);
}

