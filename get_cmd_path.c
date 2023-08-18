#include "shell.h"
/**
 * cmd_dir - get the full path of a command
 * @cmd: the command
 * Return: the full path of the command
 *         Otherwise NULL
*/
char *cmd_dir(char *cmd)
{

    char *PATH = _getenv("PATH"); /*string hold the full PATH*/
    char *token; /*to parse the value of PATH*/
    char *command; /*the command with its path*/
    int access_result; /*the return value of access function to see if my command is executable*/

    token = strtok(PATH, ":");
    while (token)
    {
        if (_strcmp(token, cmd) == 0)
        {
            return (cmd);
        }
        command = malloc(_strlen(token) + _strlen(cmd) + 2);
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
            /*free(command);*/
            return(command);
        }
        free(command);
        token = strtok(NULL, ":");
    }
    return (NULL);
}