#include "shell.h"

/**
  * print_str - prints a string to standard out
  *
  * @str: string to write out
  * Return: int of how many chars written
  */
int print_str(char *str)
{
	int i;

	if (!str)
		return (-1);
	for (i = 0; *(str + i);)
		i++;
	return (write(STDOUT_FILENO, str, i));
}

void builtin_finder(char **arglist)
{
	int i = 0, ret;

	do_built built_commands[] = {
		{"exit", exit_builtin},
		{"env", env_builtin},
		{NULL, NULL}
	};

	while (built_commands[i])
	{
		if (_strcmp(built_command[i].command, arglist[0]))
			i++;
		else
			ret = built_commands[i].built_cmd(arglist);
	}
}

