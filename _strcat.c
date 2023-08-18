#include "shell.h"

/**
 * _strcat - function that appends a string to another
 *
 * @dest: first string
 * @src: second string
 *
 * Return: returns the pointer of the first string
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i++] = src[j];
		j++;
	}
	return (dest);
}