#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int _strlen(char *s);

char *_strncpy(char *dest, char *src, int n);

int _strcmp(char *s1, char *s2);

int _strncmp(char *s1, char *s2, unsigned int n);

void prompt(void);

void _exe(char *cmd_arr[]);

int _getline(char buf[], int fd);

char **get_argv(char *av[], char *buf);

char **_strtok(char *s, char *delim);

#endif
