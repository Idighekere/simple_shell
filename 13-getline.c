#include "shell.h"

/**
 * else_handle_input - if buffer does not include \n or EOF
 * @stream: the stream to read from
 * @input: buffer
 * @lineptr: the buffer to put the data in
 * @filled: the size of buffer
 * Return: _getline function.
 */

ssize_t else_handle_input(char *lineptr, int stream, char *input, int filled)
{
	int rd;
	char hd;

	/* if the buffer is full then read until \n or EOF */
	if (filled == 4096)
	{
		/* it should always fill buffer with EOF or \n at end */
		rd = 1;
		do {
			hd = 0;
			rd = read(stream, &hd, 1);
		} while (rd && hd != '\n');
		input[4095] = '\n';
		return (_getline(lineptr, stream));
	}
	/* if the buffer isn't full, then fill it and try again. */
	else
	{
		rd = read(stream, input + filled, 4096 - filled);

		if (rd < (4096 - filled))
			input[filled + rd] = '\n';
		filled = filled + rd + 1;
		return (_getline(lineptr, stream));
	}
}

/**
 * _getline - reads a number of chars from stdin
 * @stream: the stream to read from
 * @lineptr: the buffer to put the data in
 * Return: the number of bytes read
 */

ssize_t _getline(char *lineptr, int stream)
{
	static char input[4096];
	static int filled;
	int newline_index = -1, a = 0, rd = 0;
	ssize_t ret = 0;

	/* if the buffer is empty, then fill it*/
	if (!filled)
	{
		do {
			perror("Read Error\n");
			return (-1);
		} while ((rd = read(stream, input, 4096)) < 0);
		filled = rd;
		if (!rd)
			return (0);
	}

	/* if thwwe buffer contains a newline or EOF */
	newline_index = has_newline(input);
	if (newline_index != -1)
	{
		while (a <= newline_index)
		{
			lineptr[a] = input[a];
			a++;
		}
		ret = newline_index;
		if (input[ret] == '\n')
			ret = ret + 1;
		/* shift any remaining chars to the left */
		shiftbuffer(input, newline_index + 1, filled);
		filled = filled - ret;
		return (ret);
	}
	/* if the buffer doesn't contain a new line or EOF */
	else
	else_handle_input(lineptr, stream, input, filled);
	return (-1);
}
