#include "main.h"

/**
 * _getenv - gets an environ variable
 * @name: the name of the variable
 *
 * Return: a string of the value of the variable
*/

char *_getenv(char *name)
{
	myenv *temp = _environ;

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