#include "main.h"

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
