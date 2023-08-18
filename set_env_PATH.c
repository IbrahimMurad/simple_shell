#include "main.h"


/**
 * set_myenv_n_v - sets the name and the value of myenv node
 * @s: the environ string that is in the form NAME=VALUE
 *
 * Return: a pointer to the node
*/

myenv *set_myenv_n_v(char *s)
{
	myenv *temp;
	int i;

	temp = (myenv *) malloc(sizeof(myenv));
	temp->name = (char *) malloc(64);
	if (temp == NULL || temp->name == NULL)
	{
		return (NULL);
	}
	for (i = 0; s[i] != '='; i++)
	{
		temp->name[i] = s[i];
	}
	temp->name[i] = '\0';
	temp->value = s + i + 1;
	temp->next = NULL;
	return (temp);
}
/**
 * set_my_env - builds a linked list that stores the env
 *
 * Return: a pointer to the head of the list
*/

myenv *set_my_env(void)
{
	myenv *head;
	myenv *node;
	myenv *New;
	int i;

	New = set_myenv_n_v(environ[0]);
	head = New;
	node = New;
	for (i = 1; environ[i] != NULL; i++)
	{
		New = set_myenv_n_v(environ[i]);
		node->next = New;
		node = node->next;
	}
	return (head);
}

/**
 * free_myenv - frees the memory allocated for myenv list
 * @h: a pointer to the head of the myenv list
 * Return: nothing
*/

void free_myenv(myenv *h)
{
	myenv *temp = h;

	while (h)
	{
		h = h->next;
		free(temp->name);
		free(temp);
		temp = h;
	}
}

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
