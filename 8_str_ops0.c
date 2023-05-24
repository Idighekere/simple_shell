#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: a negative or a postive number or zero
 */
int _strcmp(char *str1, char *str2)
{
	char *s1;
	char *s2;

	s1 = str1;
	s2 = str2;
	if (!str1 && !str2)
		return (0);

	if (!str1 || !str2)
		return (-1);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			break;
		if (*s2 == '\0')
			break;
		s1 = s1 + 1;
		s2 = s2 + 1;
	}
	if (*s1 < *s2)
		return (*s1 - *s2);
	if (*s1 > *s2)
		return (*s1 - *s2);
	return (0);
}
/**
 * _strlen - get the length of a string
 * @s: the string
 * Return: the number of characters in the string minus the null char
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s && s[len] != '\0')
		len++;
	return (len);
}
/**
  * word_count - counts the number of words seperated by a delim
  * @str: string to count the words
  * @delim: separator between words
  * Return: number of words
  */
int word_count(char *str, char *delim)
{
	int i, x = 0, counter = 0;

	for (i = 0; str && str[i]; i++)
	{
		if ((str[i] == delim[0]) && x)
		{
			counter++;
			x = 0;
		}
		else if (str[i] != delim[0])
			x = 1;
	}
	if (str && str[0])
		counter++;
	return (counter);
}
/**
 * _strcat - Concats two strings
 * @dest: The destination
 * @src: The source
 *
 * Return: The destination string
 */
char *_strcat(char *dest, char *src)
{
	char *wr;
	char *s;

	if (!src)
		return (dest);
	if (!dest)
		return (src);
	wr = dest;
	s = src;
	for (; *wr != '\0'; wr++)
	{
	}
	for (; *s != '\0'; s++)
	{
		*wr = *s;
		wr++;
	}
	*wr = '\0';
	return (dest);
}
/**
  * _strcpy - copy src into dest
  * @dest: destination for copied string
  * @src: string to copy
  * Return: copied string
  */
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; x <= _strlen(src); x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}
