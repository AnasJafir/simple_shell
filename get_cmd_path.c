#include "shell.h"
/**
 * cmd_dir - get the full path of a command
 * @cmd: the command
 * Return: the full path of the command
 *         Otherwise NULL
*/
char *cmd_dir(char *cmd)
{
    char *PATH = _getenv("PATH");
    char *token;
    char *command;
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
        {
            return(command);
        }
        free(command);
        token = strtok(NULL, ":");
    }
    return (NULL);
}