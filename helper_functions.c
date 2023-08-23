#include "shell.h"
/**
 * _printer - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _printer(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}

}
/**
 * _int_str - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_int_str(unsigned int count)
{
	char *str;
	unsigned int temp, digit;

	temp = count;
	for (digit = 0; temp != 0; digit++)
		temp /= 10;
	str = malloc(sizeof(char) * (digit + 1));
	if (str == NULL)
	{
		perror("Abandon Ship!!");
		exit(127);
	}
	str[digit] = '\0';
	for (--digit; count; --digit)
	{
		str[digit] = (count % 10) + '0';
		count /= 10;
	}
	return (str);
}
