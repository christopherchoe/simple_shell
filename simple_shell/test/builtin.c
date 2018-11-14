#include "shell.h"

int exit_builtin(char **arglist)
{
	write(STDOUT_FILENO, "\n", 1);
	if (arglist)
		free_double(arglist);

	return (1);
}

int env_builtin(char **arglist)
{
	extern char **environ;

	print_env(environ);

	if (arglist)
		free_double(arglist);

	return (2);
}
