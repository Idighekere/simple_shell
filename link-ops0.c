#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_len - size of a list_s
 * @h: struct list_s, first node
 * Return: number of nodes
 */
size_t list_len(shell_list_s *h)
{
	int index = 0;

	for (index = 0; h; index++, h = h->next)
		;
	return (index);
}


/**
 * add_node - adds a new node at the beginning of a shell_list_s
 * @head: struct list_s, first node
 * @ptr: the pointer data
 * Return: new list_s
 */
shell_list_s *add_node(shell_list_s **head, char *ptr)
{
	shell_list_s *new_node = NULL;

	new_node = do_mem(sizeof(shell_list_s), NULL);
	if (!new_node)
	{
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->next = *head;

	*head = new_node;
	return (new_node);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: struct list_s, node
 * @ptr: the pointer data
 * Return: new list_s
 */
shell_list_s *add_node_end(shell_list_s **head, char *ptr)
{
	shell_list_s *new_node = NULL, *last = NULL;

	new_node = do_mem(sizeof(shell_list_s), NULL);
	if (!new_node)
	{
		return (NULL);
	}

	new_node->ptr = ptr;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	for (last = *head; last->next != NULL; last = last->next)
		;

	last->next = new_node;
	return (new_node);
}

/**
 * free_list - frees list_s
 * @head: linked list , list_s
 */
void free_list(shell_list_s *head)
{
	shell_list_s *hold_list = NULL;

	while (head != NULL)
	{
		hold_list = head;
		head = head->next;
		do_mem(0, hold_list);
	}
}

