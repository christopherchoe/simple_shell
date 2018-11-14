#include "shell.h"

/**
  * main - runs the shell
  *
  * @argc: number of arguments
  * @argv: array of arguments (strings)
  * @envp: environmental variable array
  * Return: 0
  */
int main(int argc, char *const argv[], char *envp[])
{
	char **arglist, **pathlist;
	pid_t my_pid;
	int status = 0, ret_code = 0, isinteractive = 0;

	if (argc == 2 && !(_strcmp(argv[1], "debug")))
	{
		pathlist = build_path(_getenv("PATH", envp));
		while (*pathlist)
			printf("%s\n", *pathlist++);
	}
	(void)argv;

	isinteractive = isatty(STDIN_FILENO);

	while (argc)
	{
		arglist = arg_list(isinteractive);

		ret_code = builtin_finder(arglist);

		if (ret_code == EXIT_BUILTIN)
			_exit(status);

		my_pid = fork();
		if (my_pid == -1)
		{
			perror("shell");
			return (1);
		}
		if (my_pid == 0 && ret_code == NON_BUILTIN && arglist)
		{
			if (*arglist[NON_BUILTIN] != '/')
			{
				if (execve(arglist[NON_BUILTIN], arglist, NULL) == -1)
				{
					perror("./shell");
					free_double(arglist);
				}
			}
		}
		if (wait(&status) == -1) /* if child failed */
			_exit(status);
		if (arglist && ret_code == NON_BUILTIN)
			free_double(arglist);
	}
	return (0);
}

/**
  * arg_list - obtains an argument list from the getline
  *
  * @isinteractive: a flag to indicate interactive mode
  * Return: an array of strings that contain the arguments
  */
char **arg_list(int isinteractive)
{
	char **arglist;
	char *buf = NULL;
	int i;
	size_t size_b = 0;

	if (isinteractive)
		print_str("#cisfun$ ");

	i = getline(&buf, &size_b, stdin);
	if (i == -1)
	{
		free(buf);
		return (arglist = strtow("exit", ' '));
	}
	*(buf + i - 1) = '\0';

	arglist = strtow(buf, ' ');

	free(buf);

	return (arglist);
}
