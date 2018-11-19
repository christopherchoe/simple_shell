#include "shell.h"

/**
  * build_path - Adds each path directory to a NULL-terminated array
  *
  * @path: colon separated string of all paths
  * Return: NULL-terminated array of dir strings
  */
char **build_path(char *path)
{
	char **pathlist;
	int i = 0;

	if (!path)
		return (NULL);

	pathlist = strtow(path, ':');

	if (pathlist)
		return (pathlist);
	pathlist = malloc(sizeof(char **));
	if (!pathlist)
		return (NULL);
	pathlist[i] = malloc(sizeof(char) * 2);
	if (!pathlist[i])
	{
		free(pathlist);
		return (NULL);
	}
	pathlist[i][i] = '.';
	pathlist[i][1] = '\0';
	return (pathlist);
}

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

/**
  * print_env - prints the environment variables
  *
  * @env: pointer to array of environment variables
  * Return: void
  */
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
  * Return: the contents of a matching variable or NULL
  */
char *_getenv(char *name)
{
	int i = 0, k = 0;

	if (!environ || !name)
		return (NULL);

	while (environ[k])
	{
		if (*(name + i) != environ[k][i])
		{
			if (!(*(name + i)) && environ[k][i] == '=')
				return (cut_env(environ[k]));
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

