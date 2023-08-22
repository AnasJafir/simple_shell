#include "shell.h"
/**
 * _getline - reads entire line from stream
 * @lineptr: a buffer to store the text
 * @n: a pointer to the variable that hold the size of the buffer
 * @fd: the file descriptor to read from
 * Return: the number of characters read on success, -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t line_pos = 0;
	char *line = NULL;
	int c;
	(void)n;

	while (1)
	{
		c = get_char(fd);
		if (c == EOF || c == '\n')
		{
			if (line_pos > 0 || c == '\n')
			{
				line = _realloc(line, line_pos + 1);
				if (!line)
				{
					perror("realloc");
					exit(EXIT_FAILURE);
				}
				line[line_pos] = '\0';
				*lineptr = line;
				return (line_pos);
			}
			if (c == EOF)
			{
				free(line);
				return (-1);
			}
		}
		else
		{
			line = _realloc(line, line_pos + 1);
			if (!line)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			line[line_pos++] = c;
		}
	}
}
