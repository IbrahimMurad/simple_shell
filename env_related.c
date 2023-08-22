#include "main.h"




/**
 * set_my_env - builds a linked list that stores the env
 *
 * Return: a pointer to the head of the list
*/

void set_my_env(void)
{
	char **temp_environ;
	size_t i = 0;

	temp_environ = (char **) malloc(sizeof(char *) * 200);
	if (temp_environ == NULL)
	{
		return;
	}
	i = 0;
	while (environ[i])
	{
		temp_environ[i] = _strdup(environ[i]);
		i++;
	}
	temp_environ[i] = NULL;
	environ = temp_environ;
}

/**
 * free_myenv - frees the memory allocated for myenv list
 *
 * Return: nothing
*/

void free_myenv(void)
{
	int i;

	for (i = 0; i < 200; i++)
	{
		free(environ[i]);
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
	int i = 0;
	size_t name_len;

	if (name == NULL || *name == '\0')
	{
		return (NULL);
	}
	name_len = _strlen(name);
	while (environ[i])
	{
		if (!_strncmp(environ[i], name, name_len) && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
		i++;
	}
	return (NULL);
}


/**
 * free_str_list - frees the PATH set
 * @h: a pointer to the head of the set
 *
 * Return: nothing
*/

void free_str_list(strset *h)
{
	strset *temp = h;

	while (h)
	{
		h = h->next;
		free(h->data);
		free(temp);
		temp = h;
	}
}
