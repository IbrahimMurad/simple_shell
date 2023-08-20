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
 * struct myenv - a node to hord the name of an environment and its value
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
 * struct strset - is a node to hold a string
 * @data: the string to be held by the node
 * @next: a pointer to teh next node
*/

typedef struct strset
{
	char *data;
	struct strset *next;
} strset;

extern myenv *my_environ;

unsigned int _strlen(const char *s);

char *_strcat(char *dest, char *src);

char *str_concat(char *s1, char *s2, char *s3);

char *_strncpy(char *dest, char *src, unsigned int n);

int _strcmp(const char *s1, const char *s2);

int _strncmp(const char *s1, const char *s2, unsigned int n);

char **_strtok(char *s, const char *delim);

void *set_my_env(void);

void set_myenv_n_v(myenv **node, char *s);

char *_getenv(const char *name);

strset *PATHset(void);

void interactive_mode(char *s);

int _exe(char *cmd_arr[]);

ssize_t _getline(char buf[], int fd);

char **get_argv(char *av[], char *buf);

char *_which(char *cmd);

void free_myenv(myenv *h);

void check_cmd(char *argv[]);

void my_exit(char *argv[]);

unsigned int sh_atoi(char *s);

void _printenv(void);

#endif
