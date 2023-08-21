#include "main.h"


myenv *my_environ;

/**
 * set_myenv_n_v - sets the name and the value of myenv node
 * @s: the environ string that is in the form NAME=VALUE
 * @node: a pointer to a pointer to the node of the myenv list
 * to set its name and value
 *
 * Return: a pointer to the node
*/

void set_myenv_n_v(myenv **node, char *s)
{
	int i;

	*node = (myenv *) malloc(sizeof(myenv));
	(*node)->name = (char *) malloc(64);
	if (node == NULL || (*node)->name == NULL)
	{
		return;
	}
	for (i = 0; s[i] != '='; i++)
	{
		(*node)->name[i] = s[i];
	}
	(*node)->name[i] = '\0';
	(*node)->value = s + i + 1;
	(*node)->next = NULL;
}
/**
 * set_my_env - builds a linked list that stores the env
 *
 * Return: a pointer to the head of the list
*/

void set_my_env(void)
{
	myenv *node = NULL;
	myenv *New = NULL;
	int i;

	set_myenv_n_v(&my_environ, environ[0]);
	node = my_environ;
	for (i = 1; environ[i] != NULL; i++)
	{
		set_myenv_n_v(&New, environ[i]);
		node->next = New;
		node = node->next;
	}
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

/**
 * _getenv - gets an environ variable
 * @name: the name of the variable
 *
 * Return: a string of the value of the variable
*/

char *_getenv(const char *name)
{
	myenv *temp = my_environ;

	while (temp)
	{
		if (_strcmp(temp->name, name) == 0)
		{
			return (temp->value);
		}
		temp = temp->next;
	}
	return (NULL);
}
