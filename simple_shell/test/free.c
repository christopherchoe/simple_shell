#include "shell.h"

/**
  * free_call - frees a linked list
  *
  * @head: pointer to the first node of the linked list
  * Return: void
  */
void free_call(free_list *head)
{
	if (!head)
		return;
	while (head)
	{
		free(head->mall);
		head = head->next;
	}
}

/**
  * free_double - frees a 2D array
  *
  * @arglist: the double array to free
  * Return: void
  */
void free_double(char **arglist)
{
	int i = 0;

	if (!arglist)
		return;

	while (arglist[i])
		free(arglist[i++]);

	free(arglist);
}
