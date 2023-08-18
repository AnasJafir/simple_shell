#include "shell.h"
/**
 *print_env - prints the environment variables
 *Return : 0 (success)
*/
int print_env(void)
{
	extern char **environ;
	int i;

	for(i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}
