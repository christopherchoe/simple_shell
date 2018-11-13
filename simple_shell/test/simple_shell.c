#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char **arglist;
	pid_t my_pid;
	int status = 0, i, k;

	while (argc)
	{
		arglist = arg_list();

		i = builtin_finder(arglist);

		if (i == 1)
			_exit(status);

		my_pid = fork();
		if (my_pid == -1)
		{
			perror("shell");
			return (1);
		}
		if (my_pid == 0 && i == 0 && arglist)
		{
			if (execve(arglist[i], arglist, NULL) == -1)
			{
				perror("./shell");
				free_double(arglist);
			}
		}
		if (wait(&status) == -1)
			_exit(status);
		if (arglist && i == 0)
			free_double(arglist);
	}
	return (0);
}

char **arg_list(void)
{
	char **arglist;
	char *buf;
	int i;
	size_t size_b = 1024;

	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (NULL);

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
