#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: the string
 * @c: the character to be located
 * Return: returns s[], otherwise NULL
*/
char *_strchr(char *s, char c)
{
	int i = 0;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return ('\0');
}