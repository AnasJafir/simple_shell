#include "shell.h"
/**
 * _itoa - convert integer to string
 * @num: integer to convert
 * @str: string
 * Return: void
 */
void _itoa(int num, char *str)
{
	int i = 0, length;
	int is_negative = 0, j;
	char temp;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	if (is_negative)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	length = i;
	for (j = 0; j < length / 2; j++)
	{
		temp = str[j];
		str[j] = str[length - j - 1];
		str[length - j - 1] = temp;
	}
}
