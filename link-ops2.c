#include "shell.h"

/**
 * arrayify - copy a char * linked list into a char **
 * @head: the head of the linked lst
 * Return: a malloced char **
 */
char **arrayify(shell_list_s *head)
{
	char **ret = NULL, *tmp = NULL, *tmp2 = NULL;
	int len = 0, a = 0;

	len = list_len(head);
	ret = do_mem(sizeof(char *) * (len + 1), NULL);
	for (a = 0; a < len; a++)
	{
		tmp2 = get_node_at_index(head, a)->ptr;
		tmp = do_mem(sizeof(char) * (_strlen(tmp2) + 1), NULL);
		tmp = _strcat(tmp, tmp2);
		ret[a] = tmp;
	}
	ret[a] = NULL;
	return (ret);
}

/**
 * listify - copy a char ** array into a malloced char * linked list
 * @arr: char **
 * Return: a malloced char * linked list
 */

shell_list_s *listify(char **arr)
{
	shell_list_s *ret = NULL;
	char *tmp = NULL;
	int index = 0;

	while (arr[index])
	{
		tmp = do_mem(sizeof(char) * (_strlen(arr[index]) + 1), NULL);
		tmp = _strcat(tmp, arr[index]);
		add_node_end(&ret, tmp);
		index++;
	}
	return (ret);
}

/**
 * free_double_array - frees a double char pointer
 * @list: the double char pointer.
 */

void free_double_array(char **list)
{
	int abc = 0;

	if (list == NULL)
		return;

	for (abc = 0; list[abc] != NULL; abc++)
		do_mem(0, list[abc]);
	do_mem(0, list);
}
