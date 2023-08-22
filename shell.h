#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

extern char **environ;

int mul(int a, int b);
int print_env(void);
int main(int ac, char **av, char **env);
char *cmd_dir(char *cmd, char *shell_name, int line_number);
char *_getenv(const char *name);
int _putchar(char c);
void _puts(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char **_split(char *str, char *delimiter);
char *_memcpy(char *dest, char *src, unsigned int n);
ssize_t _getline(char **lineptr, size_t *n, int fd);
void *_realloc(void *ptr, size_t size);
void _itoa(int num, char *str);
int get_char(int fd);

#endif
