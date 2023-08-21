#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int mul(int a, int b);
int print_env(void);
int main(int ac, char **av, char **env);
char *cmd_dir(char *cmd);
char *_getenv(const char *name);
int _putchar(char c);
void _puts(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, const char *s2);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
char **_split(char *str, char *delimiter);
char *_memcpy(char *dest, char *src, unsigned int n);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);

#endif
