#include "shell.h"

/**
 *_puts - prints a string
 *@s: is a character
 *Return: number of printed chars or -1 on failure
 */

ssize_t _puts(char *s)
{
	ssize_t num, len;

	num = _strlen(s);
	len = write(STDOUT_FILENO, s, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
