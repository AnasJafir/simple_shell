#include "shell.h"

/**
 * get_char - Read a character from a file descriptor
 * @fd: The file descriptor to read from
 * Return: The character read as an unsigned char cast to an int,
 *         or EOF if the end of file is reached or an error occurs.
 */
int get_char(int fd)
{
	char c;
	ssize_t bytes_read = read(fd, &c, 1);

	if (bytes_read == -1)
	{
		return (EOF);
	}
	else if (bytes_read == 0)
	{
		return (EOF);
	}
	return ((unsigned char)c);
}
