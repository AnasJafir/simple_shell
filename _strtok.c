#include "shell.h"
/**
 * _strtok - tokenize a string
 * @str: string
 * @delimiter: the delimiter
 * Return: array of tokens of the string
*/

char **_strtok(char *str, char *delimiter)
{
    char *token;
    char **tokens = NULL;
    int i = 0;

    tokens = malloc(sizeof(char *) * 1024);
	token = strtok(str, delimiter);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	tokens[i] = NULL;
    return (tokens);
}
