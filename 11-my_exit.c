#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * do_mem - free, malloc, or free all with a static record
 * @ptr: the pointer to free
 * @size: the size to malloc if non-zero
 *
 * Return: the malloced pointer if malloc
 */

void *do_mem(size_t size, void *ptr)
{
	static shell_list_t *all;
	int d = 0, len = 0;
	void *ret = NULL;

	if (size)
	{
		ret = malloc(size);
		if (!ret)
			do_exit(2, "malloc failed", EXIT_FAILURE);
		for (d = 0; (unsigned int)d < size; d++)
			((char *)ret)[d] = 0;
		__add_node_end(&all, ret);
		return (ret);
	}
	else if (ptr)
	{
		len = __list_len(all);
		for (d = 0; d < len; d++)
		{
			if (__get_node_at_index(all, d)->ptr == ptr)
			{
				__delete_node_at_index(&all, d);
				break;
			}
		}
		free(ptr);
		return (NULL);
	}
	else
	{
		/* if neither size nor ptr, then nuke everything */
		__free_list_full(all);
		return (NULL);
	}
	return (NULL);
}

/**
 * do_exit - custom exit error message, code, and automatic memory cleanuup
 * @fd: the file descriptor to write the message
 * @code: the numerical exit code
 * @msg: the message to print
 */

void do_exit(int fd, char *msg, int code)
{
	if (*msg)
	{
		/* print message */
		write(fd, msg, _strlen(msg));
	}
	/* nuke extra memory */
	do_mem(0, NULL);

	/* exit with code */
	exit(code);
}
