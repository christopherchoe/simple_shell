#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char **arglist;
	pid_t my_pid;
	int status = 0, ret_code = 0;

	while (argc)
	{
		arglist = arg_list();

		ret_code = builtin_finder(arglist);

		if (ret_code == EXIT_BUILTIN) /* called exit_builtin */
			_exit(status);

		my_pid = fork();
		if (my_pid == -1)
		{
			perror("shell");
			return (1);
		}
		if (my_pid == 0 && ret_code == NON_BUILTIN && arglist) /* if non-builtin cmd */
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

char **arg_list(void)
{
	char **arglist;
	char *buf = NULL;
	int i;
	size_t size_b = 1024;

	/*buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (NULL);*/

	print_str("#cisfun$ ");

	i = getline(&buf, &size_b, stdin);
	printf("i == %d\n", i);
	if (i == -1)
	{
		printf("Freeing buf\n");
		free(buf);
		return (arglist = strtow("exit"));
	}
	*(buf + i - 1) = '\0';

	arglist = strtow(buf);

	free(buf);

	return (arglist);
}
