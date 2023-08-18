#include "main.h"

/**
 * free_myenv - frees the memory allocated for myenv list
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