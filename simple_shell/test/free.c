#include "shell.h"

void free_call(free_list *head)
{
	if (!head)
		return;
	while(head)
	{
		free(head->mall);
		head = head->next;
	}
}

void free_double(char **arglist)
{
	int i = 0;

	if (!arglist)
		return;

	while (arglist[i])
		free(arglist[i++]);

	free(arglist);
}
