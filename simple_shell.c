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
	int total = 0;
	char *buffer = NULL, **tokens = NULL, *cmd;
	size_t buf_size = 0;
	pid_t pid;
	(void)av;
	(void)ac;

	while (1)
	{
		write(1, "$ ", 2);
		total = _getline(&buffer, &buf_size, stdin);
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
				cmd = cmd_dir(tokens[0]);
				if (cmd)
				{
					execve(cmd, tokens, env);
					exit(EXIT_SUCCESS);
				}
				else
				{
					perror(av[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(NULL);
		}
		free(tokens);
	}
	return (0);
}
