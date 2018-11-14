#include "shell.h"

int exit_builtin(char **arglist)
{
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
