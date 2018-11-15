#include "shell.h"
#include <string.h>

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

	/* Run with `debug` as an argument to run this block */
	if (argc == 2 && !(_strcmp(argv[1], "debug")))
	{
		pathlist = build_path(_getenv("PATH", envp));
		while (*pathlist)
			printf("%s\n", *pathlist++);

		char a[] = "_str";
		char b[] = "cat";
		printf("%s works?\n", _strcat(a, b));
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
				int i = 0;
				for (; pathlist[i]; i++)
				{
					char *path = strdup(pathlist[i]);
					char *full_cmd = _strcat(path, "/");
					full_cmd = _strcat(full_cmd, arglist[NON_BUILTIN]);
					if (!access(full_cmd, F_OK))
					{
						if (execve(full_cmd, arglist, NULL) == -1)
						{
							perror("./shell");
							free_double(arglist);
						}
						break;
					}
				}
			}
			else
			{
				perror("not found");
				free_double(arglist);
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
		write(STDOUT_FILENO, "\n", 1);
		free(buf);
		return (arglist = strtow("exit", ' '));
	}
	*(buf + i - 1) = '\0';

	arglist = strtow(buf, ' ');

	free(buf);

	return (arglist);
}
