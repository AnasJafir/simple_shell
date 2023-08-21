#include "shell.h"
/**
 * _memcpy - copies memory area
 * @dest: memory area
 * @src: second memory area
 * @n: bytes
 *
 * Return: returns dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; n > 0; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}