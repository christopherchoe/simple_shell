#include "shell.h"

int exit_builtin(char **arglist)
{
	print_str("logout\n");
	free_double(arglist);

	return (0);
}

void env_builtin(char **arglist)
{
	extern char **environ;
	char *path;

	path = _getenv("PATH", environ);
	print_dir(path);
}
