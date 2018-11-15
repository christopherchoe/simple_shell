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

/**
  * builtin_finder - checks if the first argument matches a built in command
  *
  * @arglist: argument list from our shell
  * @envp: environment variables
  * Return: 0 if no match, 1 if exit, non 1/0 otherwise
  */
int builtin_finder(char **arglist, char **envp)
{
	int i = 0, ret = 0;
	do_built built_commands[] = {
		{"exit", exit_builtin},
		{"env", env_builtin},
		{NULL, NULL}
	};

	if (!arglist)
		return (0);

	while (built_commands[i].command)
	{
		if (_strcmp(built_commands[i].command, arglist[ret]))
		{
			i++;
		}
		else
		{
			ret = built_commands[i++].built_cmd(arglist, envp);
			break;
		}
	}
	return (ret);
}

