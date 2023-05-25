#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/**
 * get_prog_name - gets the program name
 * @name: the name of th eprog (on first execution)
 * Return: the name of the program
 */

char *get_prog_name(char *name)
{
	static char *retn;

	if (!retn)
	{
		retn = name;
	}
	return (retn);
}

/**
 * linum - get th ecurrent line number and/or add to it
 * @add: if not 0, add this amt
 * Return: the line number
 */
int linum(int add)
{
	static int line_number;

	line_number += add;
	return (line_number);
}
/**
 * my_error - custom error printing
 * @extra: any extra text
 * @command: the message to print
 * @status: the type of error to print
 */
void my_error(char *command, int status, char *extra)
{
	char *name = NULL;
	char *msg = NULL;
	char *line = NULL;

	line = _itoa(linum(0));
	name = get_prog_name(NULL);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, line, _strlen(line));

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);

	switch (status)
	{
		case 2:
			msg = "not found";
			break;
		case 126:
			msg = "Permission denied";
			break;
		case 127:
			msg = "not found";
			break;
		case 9000:
			/* exit illegal number hould exit with a code of 2*/
			msg = "Illegal number: ";
			break;
		default:
			msg = "Unknown error occured.";
	}

	write(STDERR_FILENO, msg, _strlen(msg));

	if (extra)
		write(STDERR_FILENO, extra, _strlen(extra));

	write(STDERR_FILENO, "\n", 1);
}

/**
 * main - simplw shell
 * @argv: list of arguments
 * @argc: number of arguments
 * @envp: environment
 * Return: 0 if successful
 */

int main(int argc, char **argv, char **envp)
{
	char *filename = NULL;

	get_prog_name(argv[0]);

	/* argc the right amount of arguments */
	if (argc > 2)
		return (-1);

	/* check if argv[1] is a file */
	if (argv && argv[1])
		filename = argv[1];
	/* signal handler */
	signal(SIGINT, signal_handler);
	/* initialize the envireonment */
	do_env((char *)envp, NULL);

	/* initialize the linum */
	linum(1);

	/* read, tokenize, execute loop */
	main_loop(filename);

	/* clean up */

	return (0);
}
