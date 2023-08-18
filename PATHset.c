#include "main.h"

/**
 * PATHset - creates a set of paths from PATH
 * Return: a pointer to the head of the set
*/

strset *PATHset(void)
{
	strset *head, *temp;
	char **paths, *the_path;
	int i = 0;

	the_path = _getenv("PATH");
	if (the_path == NULL)
	{
		printf("Couldn't find PATH\n");
		return (NULL);
	}
	i = 1;
	paths = _strtok(the_path, ":");
	head = (strset *) malloc(sizeof(strset));
	temp = head;
	head->data = paths[0];
	while (paths[i])
	{
		temp->next = (strset *) malloc(sizeof(strset));
		temp = temp->next;
		temp->data = paths[i];
		i++;
	}
	temp = NULL;
	return (head);
}
