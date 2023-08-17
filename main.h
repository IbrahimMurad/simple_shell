#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt(void);

void _exe(char *cmd_arr[]);

int _getline(char *buf[], int fd);

#endif