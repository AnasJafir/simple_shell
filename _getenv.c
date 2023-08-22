#include "shell.h"
/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * Return: the value of the environment variable
 *         Otherwise NULL
*/
char *_getenv(const char *name)
{
	int i = 0;
	char *token;

	while (environ[i])
	{
		token = strtok(environ[i], "=");
		if (_strcmp(token, name) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}
