#include "shell.h"

/**
  * exit_builtin - built in function to exit shell
  *
  * @arglist: arguments list
  * @envp: environment variables
  * Return: returns 1 to signal exit
  */
int exit_builtin(char **arglist, char **envp)
{
	int i = 0;
	(void)envp;

	if (arglist && arglist[1])
	{
		i = _atoi(arglist[1]);
		if (i <= 0)
			perror("illegal number");
	}

	if (arglist)
		free_double(arglist);

	return (i);
}

/**
  * env_builtin - built in for printing the environment variables
  *
  * @arglist: arguments list
  * @envp: environment variables
  * Return: -2 to indicate non exit, but found builtin
  */
int env_builtin(char **arglist, char **envp)
{
	print_env(envp);

	if (arglist)
		free_double(arglist);

	return (-2);
}
