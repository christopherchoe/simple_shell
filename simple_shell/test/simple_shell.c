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
	char *full_cmd = NULL;
	pid_t my_pid;
	int status = 0, ret_code = 0, isinteractive = 0;

	(void)argv;

	isinteractive = isatty(STDIN_FILENO);

	while (argc)
	{
		arglist = arg_list(isinteractive);

		pathlist = build_path(_getenv("PATH", envp));

		ret_code = builtin_finder(arglist, envp);

		if (ret_code == EXIT_BUILTIN)
		{
			free_double(pathlist);
			_exit(status);
		}

		my_pid = fork();
		if (my_pid == -1)
		{
			free_double(arglist);
			free_double(pathlist);
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
					full_cmd = _strcat_dir(pathlist[i], arglist[NON_BUILTIN]);
					if (!access(full_cmd, F_OK))
					{
						if (execve(full_cmd, arglist, NULL) == -1)
						{
							free(full_cmd);
							free_double(pathlist);
							perror("./shell");
							free_double(arglist);
						}
						break;
					}
				}
			}
			else
			{
				if (execve(arglist[NON_BUILTIN], arglist, NULL) == -1)
				{
					perror("not found");
					free_double(arglist);
					free_double(pathlist);
				}
			}
		}
		if (wait(&status) == -1) /* if child failed */
			_exit(status);
		if (arglist && ret_code == NON_BUILTIN)
		{
			if (full_cmd)
				free(full_cmd);
			free_double(pathlist);
			free_double(arglist);
		}
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
