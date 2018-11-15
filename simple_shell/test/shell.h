#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define EXIT_BUILTIN 1
#define NON_BUILTIN 0

extern char **environ;

/*
  * struct to_free - struct for holding instances of allocated memory
  * @mall: the instance of allocated memory
  * @next: pointer to next to_free struct in linked list
  * Description: struct to create a linked list of allocated memory to free at
  * any exit of program.
  */
typedef struct to_free {
	char *mall;
	struct to_free *next;
} free_list;

/**
  * struct built_in - struct for matching commands to built in commands
  * @command: the string matching the command to execute
  * @built_cmd: the built in command to call if command matches
  * Description: Special built in commands for custom shell
  */
typedef struct built_in {
	char *command;
	int (*built_cmd)(char **, char **);
} do_built;

char *check_path(char *);
char **arg_list(int);

/* free */
void free_call(free_list *);
void free_double(char **);

/* strtow */
char **strtow(char *, char);
int word_counter(char *, char);

/* Built in */
int exit_builtin(char **, char **);
int env_builtin(char **, char **);

/* Utility */
int _strlen(char *);
int _strcmp(char *, char *);
char *_strcat_dir(char *, char *);

/* Path */
char **build_path(char *);
void print_dir(char *);
void print_env(char **);
char *_getenv(char *);
char *cut_env(char *);

/* prompt */
int print_str(char *);
int builtin_finder(char **);

#endif /*_SHELL_H_*/

