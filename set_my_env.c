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
	int i, j = 0;

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
	temp->value = s + i;
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
