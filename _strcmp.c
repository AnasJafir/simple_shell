#include "shell.h"
/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if the s1 and s2 are equal
 *         negative integer if s1 is less than s2
 *         positive integer if s1 is greater than s2
*/
int _strcmp(char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}