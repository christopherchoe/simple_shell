#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>

/**
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
	void (*built_cmd)(char **);
} do_built;

char **arg_list(void);

/* free */
void free_call(free_list *);
void free_double(char **);

/* strtow */
char **strtow(char *);
int word_counter(char *);

/* Built in */
int exit_builtin(char **);
int env_builtin(char **);

/* Utility */
int _strlen(char *);
int _strcmp(char *, char *);

#endif /*_SHELL_H_*/

