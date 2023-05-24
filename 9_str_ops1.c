#include "shell.h"
#include <stdio.h>

/**
  * _atoi - converst a string to an integer
  * @s: string to be converted
  * Return: integers in a string
  */

int _atoi(char *s)
{
	int numb, len, num_count, mul, i, neg;

	len = 0;
	i = 0;
	num_count = 0;
	mul = 1;
	neg = 1;
	numb = 0;

	while (s[len] != '\0')
	{
		if (s[len] >= '0' && s[len] <= '9')
		{
			num_count++;
			if (!(s[len + 1] >= '0' && s[len + 1] <= '9'))
				break;
		}
		len++;
	}
	for (; num_count > 1; num_count--)
		mul *= 10;
	for (; i <= len; i++)
	{
		if (s[i] == '-')
			neg *= -1;
		else if (s[i] <= '9' && s[i] >= '0')
		{
			numb += (s[i] - '0') * mul * neg;
			mul /= 10;
		}
	}
	return (numb);
}

/**
  * sizeof_command - returns the size of command, breaks if it hits &&, ||, ;
  * @tokens: standard input tokenized
  * Return: the size of the command
  */
int sizeof_command(char **tokens)
{
	int x = 0;

	if (!tokens)
		return (0);
	for (x = 0; tokens[x]; x++)
	{
		if (tokens[x][0] == '&' && tokens[x][1] == '&')
			break;
		if (tokens[x][0] == '|' && tokens[x][1] == '|')
			break;
		if (tokens[x][0] == ';')
			break;
	}
	return (x);
}

/**
 * _isdigit - check for a digit (0 through 9)
 * @c: digit checked
 * Return: 1 if c is a digit returns 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * has_newline - checks for \n or EOF and returns the index
 * @input: input read from read function in getline
 * Return: the size of command when it reaches \n or EOF
 */
int has_newline(char *input)
{
	int x;

	for (x = 0; input && input[x]; x++)
	{
		/*searches for \n, new line */
		if (input[x] == '\n')
			return (x);

		/* check if EOF */
		/*
		*if (input[1] == '-1')
		*	return (x);
		*/
	}

	return (x);
}

/**
 * shiftbuffer - shifts the buffer to the next command after \n
 *  @input: input from standard input
 *  @newline_index: where there is a new line or EOF
 *  @filled: size filled to
 */
void shiftbuffer(char *input, int newline_index, int filled)
{
	/* might have to make input a double pointer */
	/* shift and place back to beggining */
	int i = newline_index;
	int j = 0;

	for (; i < filled; i++, j++)
	{
		/* copy */
		input[j] = input[i];
	}
	/* fills remainder with '\0' */
	for (; j < 4096; j++)
	{
		input[j] = '\0';
	}
}
