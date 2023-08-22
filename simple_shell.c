#include "shell.h"
/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 * Return: 0 (success)
*/
int main(int ac, char **av, char **env)
{
	int total = 0, line_number = 0;
	char *buffer = NULL, **tokens = NULL, *cmd;
	size_t buf_size = 0;
	pid_t pid;
	(void)ac;

	while (1)
	{
		line_number++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		total = _getline(&buffer, &buf_size, STDIN_FILENO);
		if (total == -1)
			exit(EXIT_FAILURE);
		tokens = _split(buffer, " \t\n");
		if (_strcmp(tokens[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		else if (_strcmp(tokens[0], "env") == 0)
			print_env();
		else
		{
			pid = fork();
			if (pid == 0)
			{
				cmd = cmd_dir(tokens[0], av[0], line_number);
				if (cmd)
				{
					execve(cmd, tokens, env);
					exit(EXIT_SUCCESS);
				}
				else
					exit(EXIT_FAILURE);
			}
			else
				wait(NULL);
		}
		free(tokens);
	}
	return (0);
}
