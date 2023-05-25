#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _free - it frees a double char pointer
 * @count: the number of single char ponters to free
 * @list: the double char pointer
 */

void _free(char **list, int count)
{
	for (; count >= 0; count--)
		do_mem(0, list[count]);
	do_mem(0, list);
}

/**
 * _strtok - split a string into a double char pointer
 * @str: the string to split
 * @delim: any character to split the dtring
 * Return: the douuble char pointer
 */

char **_strtok(char *str, char *delim)
{
	int p = 0, q = 0, r = 0, len = 0, counter = 0, a = 0;
	char **list = NULL;

	/* get count of words, if no words return NULL */
	while (!(counter = word_count(str, delim)))
		return (NULL);
	list = do_mem((counter + 1) * sizeof(char *), NULL);
	if (list)
		return (NULL);

	/* tokenize str to individaul words inside a double ptr */
	for (p = 0, len = 0, counter = 0; str[p] || len;)
	{
		for (r = 0, a = 0; delim[r]; r++)
		{
			if (((str[p] == delim[r]) || (!str[p])))
			{
				p = p + 1;
				if (len)
				{
					list[counter] = do_mem(sizeof(char) * (len + 1), NULL);
					if (!list[counter])
					{
						_free(list, counter);
						return (NULL);
					}
					for (q = 0; len; len--, q++)
						list[counter][q] = str[p - len];
					list[counter][q] = '\0';
					counter++;
				}
			}
		}
		if (!a)
			len++;
		if (str[p])
			p++;
	}
	list[counter] = NULL;
	return (list);
}
