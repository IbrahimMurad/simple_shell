#include "main.h"




/**
 * set_my_env - builds a linked list that stores the env
 *
 * Return: a pointer to the head of the list
*/

void set_my_env(void)
{
	char **temp_environ = NULL;
	size_t i = 0;

	temp_environ = (char **) malloc(sizeof(char *) * 200);
	if (temp_environ == NULL)
	{
		exit(-1);
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

	for (i = 0; i < 200 && environ[i] != NULL; i++)
	{
		free(environ[i]);
	}
	free(environ);
}

/**
 * PATHset - creates a set of paths from PATH
 * Return: a pointer to the head of the set
*/

strset *PATHset(void)
{
	strset *head = NULL;
	char *paths[64], *the_path = NULL;
	int i = 0;

	the_path = _getenv("PATH");
	if (the_path == NULL || the_path[0] == '\0')
	{
		return (NULL);
	}
	_strtok(paths, the_path, ":");
	while (paths[i])
	{
		head = add_node(&head, paths[i]);
		i++;
	}
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

	if (h == NULL)
	{
		return;
	}
	while (h->next != NULL)
	{
		temp = h->next;
		free(h->data);
		free(h);
		h = temp;
	}
	free(h->data);
	free(h);
}
