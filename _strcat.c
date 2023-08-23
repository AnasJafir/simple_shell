#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *new;
	unsigned int len1, len2, len, i, j;

	len1 = 0;
	len2 = 0;
	if (dest == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; dest[len1]; len1++)
			;
	}
	if (src == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; src[len2]; len2++)
			;
	}
	len = len1 + len2 + 2;
	new = malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new[i] = dest[i];
	new[i] = '/';
	for (j = 0; j < len2; j++)
		new[i + 1 + j] = src[j];
	new[len1 + len2 + 1] = '\0';
	return (new);
}
