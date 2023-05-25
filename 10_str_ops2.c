#include "shell.h"
#include <stdio.h>

/**
 * _reverse - reverses the content of the string
 * @str: the string to reverse
 * @n: the length of the string
 * Return: the reversed string
 */

char *_reverse(char *str, int n)
{
	char *_start = str;
	char *_end;
	char tempo;

	_end = str + n - 1;
	for (; _start < _end; _start++, _end--)
	{
		tempo = *_end;
		*_end = *_start;
		*_start = tempo;
	}
	return (str);
}

/**
 * _itoa - converts an integer base to a string
 * @num: integer to convert
 * Return: integer in string format
 */

char *_itoa(int num)
{
	int a = 0, neg = 0, c_num = num, len, rem = 0;
	char *strn;

	for (len = 0; c_num; c_num = c_num / 10)
		;

	/* check if num is 0 */
	if (num == 0)
	{
		strn = do_mem(2 * sizeof(char), NULL);
		strn[a++] = '0';
		strn[a] = '\0';
		return (strn);
	}
	/* checking if negative number */
	if (num < 0)
	{
		neg = 1;
		num = -num;

		len++;
	}
	/* malloc for size of string */
	strn = do_mem((len + 1) * sizeof(char), '\0');
	/* handle individaual numbers */
	while (num != 0)
	{
		rem = num % 10;
		strn[a++] = rem + '0';
		num /= 10;
	}
	/* Add negative sihn if negative */
	if (neg)
		strn[a++] = '-';
	/* add null bite */
	strn[a] = '\0';
	/* reverse string */
	_reverse(strn, a);

	return (strn);
}

/**
 * _memset - memset function
 * @s: start point of string to change
 * @b: value that will replace
 * @n: the number of bytes to change
 * Return: changed pointer
 */

char *_memset(char *s, char b, int n)
{
	char *a = s;

	for (; n != 0; a++, n--)
		*a = b;
	return (s);
}
