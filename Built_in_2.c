#include "main.h"

/**
 * excute_setenv - adds a variable to the environment (NAME=VALUE)
 * @argv: an array of strings that holds the running program's name
 * the command and its argumens
 *
 * Return: 0 on success or -1 on error
 */

int excute_setenv(char *argv[])
{
	char *err_msg_h = str_concat(argv[0], ": ", argv[1]);

	if (argv[2] == NULL || argv[2][0] == '\0')
	{
		write(STDERR_FILENO, err_msg_h, 1024);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "no name has been passed", 24);
		errno = 2;
		return (errno);
	}
	errno = _setenv(argv[2], argv[3], 0);
	if (errno == 2)
	{
		write(STDERR_FILENO, err_msg_h, 1024);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "the name can not contain '='\n", 30);
		return (errno);
	}
	free(err_msg_h);
	errno = 0;
	return (errno);
}

/**
 * excute_unsetenv - removes a variable from the current environment
 * @argv: an array of strings that holds the running program's name
 * the command and its argumens
 * (where the third argument is the variable's name)
 *
 * Return: 0 on success or -1 on error
 */

int excute_unsetenv(char *argv[])
{
	char *err_msg_h = str_concat(argv[0], ": ", argv[1]);

	if (argv[2] == NULL || argv[2][0] == '\0')
	{
		write(STDERR_FILENO, err_msg_h, 1024);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "no name has been passed", 24);
		errno = 2;
		return (errno);
	}
	errno = _unsetenv(argv[2]);
	if (errno == 2)
	{
		write(STDERR_FILENO, err_msg_h, 1024);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "the name can not contain '='\n", 30);
		return (errno);
	}
	free(err_msg_h);
	return (errno);
}

/**
 * _setenv - adds a variable to the environment
 * or changes its value if it does exist.
 * @name: the name of the variable.
 * @value: the value of the variable.
 * @overwrite: an integer that indecates if the already existing variable
 * can be changed or not
 *
 * Return: 0 on success or -1 on error.
*/

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len, vallen, i = 0;

	name_len = _strlen(name);
	vallen = _strlen(value);
	for (i = 0; i < name_len; i++)
	{
		if (name[i] == '=')
		{
			errno = 2;
			return (errno);
		}
	}
	i = 0;
	while (environ[i])
	{
		if (!_strncmp(environ[i], name, name_len) && environ[i][name_len] == '=')
		{
			if (overwrite == 0)
			{
				_strncpy(environ[i] + name_len + 1, value, _strlen(value));
			}
			errno = 0;
			return (errno);
		}
		i++;
	}
	environ[i] = (char *) malloc(name_len + vallen + 2);
	_strncpy(environ[i], name, name_len);
	_strncpy(environ[i] + name_len, "=", 1);
	_strncpy(environ[i] + name_len + 1, value, vallen);
	environ[i + 1] = NULL;
	errno = 0;
	return (errno);
}



/**
 * _unsetenv - removes a variable from the environment
 * if it does exist.
 * @name: the name of the variable.
 *
 * Return: 0 on success or -1 on error.
*/
int _unsetenv(const char *name)
{
	size_t name_len, i = 0;

	name_len = _strlen(name);
	for (i = 0; i < name_len; i++)
	{
		if (name[i] == '=')
		{
			errno = 2;
			return (errno);
		}
	}
	while (environ[i])
	{
		if (!_strncmp(environ[i], name, name_len) && environ[i][name_len] == '=')
		{
			free(environ[i]);
			for (; environ[i + 1] != NULL; i++)
			{
				environ[i] = environ[i + 1];
			}
			environ[i] = environ[i + 1];
			errno = 0;
			return (errno);
		}
		i++;
	}
	errno = 0;
	return (errno);
}
