#include "shell.h"

int exit_builtin(char **arglist)
{
	print_str("logout\n");
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

	return (0);
}
