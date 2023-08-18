#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/**
 * myenv - a node to hord the name of an environment and its value
 * @name: the name of the environment name
 * @value: a pointer to the value of the name (not a copy)
 * @next: a pointer to the next node of NULL if tail
*/

typedef struct myenv
{
	char *name;
	char *value;
	struct myenv *next;
} myenv;

/**
 * struct node - is a node to hold a string
 * @data: the string to be held by the node
 * @next: a pointer to teh next node
*/

typedef struct strset
{
	char *data;
	struct strset *next;
} strset;

myenv *_environ;

strset *my_PATH;

int _strlen(char *s);

char *_strcat(char *dest, char *src);

char *str_concat(char *s1, char *s2, char *s3);

char *_strncpy(char *dest, char *src, int n);

int _strcmp(char *s1, char *s2);

int _strncmp(char *s1, char *s2, unsigned int n);

void prompt(void);

int _exe(char *cmd_arr[]);

int _getline(char buf[], int fd);

char **get_argv(char *av[], char *buf);

char **_strtok(char *s, char *delim);

char *_which(char *cmd);

strset *PATHset(void);

myenv *set_my_env(void);

char *_getenv(char *name);

#endif
