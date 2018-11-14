#include "shell.h"

int main(int argc, char *const argv[], char *const envp[])
{
	char **arglist;
	pid_t my_pid;
	int status = 0, ret_code = 0, interactive = 0;

	(void)argv; (void)envp;

	interactive = isatty(STDIN_FILENO);

	while (argc)
	{
		arglist = arg_list(interactive);

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
			if (execve(arglist[NON_BUILTIN], arglist, NULL) == -1)
			{
				perror("./shell");
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

char **arg_list(int interactive)
{
	char **arglist;
	char *buf = NULL;
	int i;
	size_t size_b = 0;

	if (interactive)
		print_str("#cisfun$ ");

	i = getline(&buf, &size_b, stdin);
	if (i == -1)
	{
		free(buf);
		return (arglist = strtow("exit"));
	}
	*(buf + i - 1) = '\0';

	arglist = strtow(buf);

	free(buf);

	return (arglist);
}
