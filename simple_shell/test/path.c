#include "shell.h"

/**
  * print_dir - prints the directory of the path found, one per line
  *
  * @path: colon separated string of all paths
  * Return: void
  */
void print_dir(char *path)
{
	if (!path)
		return;

	while (*path)
	{
		if (*path != ':')
			write(STDOUT_FILENO, path, 1);
		else
			write(STDOUT_FILENO, "\n", 1);
		path++;
	}
}

void print_env(char **env)
{
	int i = 0, k = 0;

	if (!env)
		return;

	while (env[i])
	{
		for (k = 0; env[i][k];)
			k++;
		write(STDOUT_FILENO, env[i], k);
		print_str("\n");
		i++;
	}
}

/**
  * _getenv - gets a matching env variable or returns NULL
  *
  * @name: name of env variable we want
  * @env: environment variables
  * Return: the contents of a matching variable or NULL
  */
char *_getenv(char *name, char **env)
{
	int i = 0, k = 0;

	if (!env || !name)
		return (NULL);

	while (env[k])
	{
		if (*(name + i) != env[k][i])
		{
			if (!(*(name + i)) && env[k][i] == '=')
				return (cut_env(env[k]));
			i = 0;
			k++;
		}
		else
		{
			i++;
		}
	}
	return (NULL);
}

/**
  * cut_env - cuts the environment variable to be only after the =
  *
  * @env: string of environment variable
  * Return: the cut string
  */
char *cut_env(char *env)
{
	while (*env != '=')
		env++;
	return (++env);
}

