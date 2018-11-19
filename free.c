#include "shell.h"

/**
  * free_double - frees a 2D array
  *
  * @arglist: the double array to free
  * Return: void
  */
void free_double(char **arglist)
{
	int i = 0;

	if (!arglist)
		return;

	while (arglist[i])
		free(arglist[i++]);

	free(arglist);
}
