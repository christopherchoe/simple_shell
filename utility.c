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

/**
 * _atoi - return a num inside of a string
 *
 * @s: pointer for string to parse
 * Return: int pulled from string, 0 if none
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int flag = -1, i = 0, neg = 1;

	if (*s == '\0')
		flag = 1;
	for (i = 0; flag == -1; i++)
	{
		if ((*(s + i) >= '0') && (*(s + i) <= '9'))
		{
			if (num != 0)
				num = ((num * 10) + (*(s + i) - '0'));
			else
				num = (*(s + i) - '0');
		}
		else
		{
			num = -1;
			neg = 1;
			break;
		}
		if (*(s + i + 1) == '\0')
			flag = 1;
		if (*(s + i) == '-')
			neg *= -1;
		if (num != 0)
		{
			if ((*(s + i + 1) < '0') || (*(s + i + 1) > '9'))
				flag = 0;
		}
	}
	return (neg * num);
}
