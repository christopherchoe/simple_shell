#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char **arglist;
	pid_t my_pid;
	int status, i, k;

	print_str("#cisfun$ ");
	while (1)
	{
		arglist = arg_list();
		if (!arglist)
			_exit(status);

		if (!exit_builtin(arglist))
			_exit(status);

		my_pid = fork();
		if (my_pid == -1)
		{
			perror("shell");
			return (1);
		}
		if (my_pid == 0)
		{
			if (execve(arglist[0], arglist, NULL) == -1)
				perror("./shell");
		}
		if (wait(&status) == -1)
			_exit(status);
		print_str("#cisfun$ ");
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

	i = getline(&buf, &size_b, stdin);
	if (i == -1)
	{
		free(buf);
		print_str("logout\n");
		return (NULL);
	}
	*(buf + i - 1) = '\0';

	arglist = strtow(buf);

	free(buf);

	return (arglist);
}