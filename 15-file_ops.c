#include "shell.h"
<<<<<<< HEAD
#include <fcntl.h>
#include <stdlib.h>
=======
>>>>>>> 8b6330287104ef2f90cb19006a375dcdf1f10803

/**
 * read_textfile - it reads a file and returns string of what it reads
 * @filename: name of file to read
 * Return: string of what it reads
 */

char *read_textfile(char *filename)
{
	char *buffer;
	int open_file;
	ssize_t l_Read;

	if (!filename)
		return (NULL);
	/* allocate memory for the content of a file */
	buffer = do_mem(4096, NULL);
	/* open file */
	open_file = open(filename, O_RDONLY);
	if (open_file == -1)
	{
		do_mem(0, buffer);
		do_exit(2, _strcat("Can't open ", filename), 127);
	}

	/* read file up to size of the buffer 4096*/
	l_Read = read(open_file, buffer, 4096);
	if (l_Read < 1)
	{
		do_mem(0, buffer);
		close(open_file);
		return (NULL);
	}

	/* check if close failed? */
	close(open_file);

	return (buffer);
}
