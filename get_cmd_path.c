#include "shell.h"
/**
 * cmd_dir - get the full path of a command
 * @cmd: the command
 * @program_name: the name of the shell
 * @line_number: number of line in STDIN
 * Return: the full path of command or NULL
*/
char *cmd_dir(char *cmd, char *program_name, int line_number)
{
	char *PATH = _getenv("PATH");
	char *token, *command, line_num_str[20];
	int access_result;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	token = strtok(PATH, ":");
	while (token)
	{
		command = malloc(sizeof(char) * 1024);
		if (command == NULL)
		{
			_puts("Error");
			return (NULL);
		}
		_strcpy(command, token);
		_strcat(command, "/");
		_strcat(command, cmd);
		access_result = access(command, F_OK);
		if (access_result == 0)
			return (command);
		free(command);
		token = strtok(NULL, ":");
	}
	if (isatty(STDIN_FILENO))
	{
		write(2, program_name, _strlen(program_name));
		write(2, ": No such file or directory\n", 29);
	}
	else
	{
		_itoa(line_number, line_num_str);
		write(2, program_name, _strlen(program_name));
		write(2, ": ", 2);
		write(2, line_num_str, _strlen(line_num_str));
		write(2, ": ", 2);
		write(2, cmd, _strlen(cmd));
		write(2, ": not found\n", 13);
	}
	return (NULL);
}
