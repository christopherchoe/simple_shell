#include "shell.h"

/**
  * _strcat - concatenates two strings
  *
  * @dest: first string
  * @src: second string
  * Return: dest which will have concatenated string
  */
char *_strcat(char *dest, char *src)
{
	_strcpy(dest + _strlen(dest), src);
	return (dest);
}

/**
  * _strcpy - copies a string 
  *
  */
char *_strcpy(char *dest, char *src)
{
	return ( _memcpy(dest, src, _strlen(src) + 1) );
}

void *_memcpy(void *dest, void *src, size_t len)
{
	char *cdest = (char *)dest;
	char *csrc  = (char *)src;
	size_t i = 0;

	for (; i < len; i++)
		cdest[i] = csrc[i];

	return (dest);
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

