#include "shell.h"
/**
 * print_env - print the environment variables
 * Return: 0 ( Success)
*/
int print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}
