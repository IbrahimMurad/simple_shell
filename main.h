#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


/* Declaring the current environment passed by the shell */
extern char **environ;

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


/* string library functions but my own reimplementation */
/* twisted a little to suit the current project */

size_t _strlen(const char *s);

char *_strdup(char *str);

char *str_concat(const char *s1, const char *s2, const char *s3);

char *_strncpy(char *dest, const char *src, size_t n);

int _strcmp(const char *s1, const char *s2);

int _strncmp(const char *s1, const char *s2, size_t n);

char *_strchr(char *s, const char c);

char *_strcat(char *dest, char *src);

char *numtostr(char *buf, int num);




/* Essential tools for my simple-shell project */

char **_strtok(char *s, const char *delim);

char *get_token(char **str_ptr, const char *delim);

ssize_t _getline(char buf[], int fd);

char **get_argv(char *av[], char *buf);

void free_strstr(char **tokens);

void free_argv(char *argv[]);




/* Environment-related functions */

void set_my_env(void);

char *_getenv(const char *name);

strset *PATHset(void);

void free_myenv(void);

void free_str_list(strset *h);

strset *add_node(strset **head, char *str);




/* Excution-related functions */

int my_hsh(char *s);

int interactive_mode(char *s);

int non_interactive_mode(char *s);

int get_separator(char *buf, int *index);

int excute_line(char *running_prog, char *line);

int excute_one_cmd(char *prog_name, char *command_line);

int before_exe(char *cmd_arr[]);

int _exe(char *s, char *cmd_arr[]);

char *_which(char *cmd);

int check_cmd(char *argv[]);




/* my built-in functions */

int my_exit(char *argv[]);

int _env(char *argv[]);

int excute_setenv(char *argv[]);

int excute_unsetenv(char *argv[]);

int excute_cd(char *argv[]);

int _setenv(const char *name, const char *value, int overwrite);

int _unsetenv(const char *name);

int _cd(char *argv[]);

void print_count(void);

#endif
