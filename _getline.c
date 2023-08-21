#include "shell.h"
/**
 * _getline - reads entire line from stream
 * @lineptr: a buffer to store the text
 * @n: a pointer to the variable that hold the size of the buffer
 * @stream: the input to read from
 * Return: the number of characters read on success, -1 on failure
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    static char buffer[BUFFER_SIZE];
    static size_t buffer_pos = 0;
    static size_t bytes_read = 0;
    char c;
    char *line = NULL;
    size_t line_pos = 0;
    (void)stream;
    (void)n;

    while (1) {
        if (buffer_pos >= bytes_read)
        {
            bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
            {
                if (line_pos > 0)
                {
                    line = malloc(line_pos + 1);
                    _memcpy(line, buffer, line_pos);
                    line[line_pos] = '\0';
                    *lineptr = line;
                    return line_pos;
                }
                return -1;
            }
            buffer_pos = 0;
        }

        c = buffer[buffer_pos++];
        if (c == '\n')
        {
            line = malloc(line_pos + 1);
            _memcpy(line, buffer, line_pos);
            line[line_pos] = '\0';
            *lineptr = line;
            buffer_pos++;
            return line_pos;
        }

        if (!line)
        {
            line = malloc(line_pos + 1);
        } else
        {
            line = _realloc(line, line_pos + 1);
        }
        if (!line)
        {
            perror("malloc/realloc");
            exit(EXIT_FAILURE);
        }
        line[line_pos++] = c;
    }
}
