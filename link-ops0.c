#include "shell.h"

/**
 * list_len - size of a shell_lsit_s
 * @h: struct shell_list_s, 1st node
 * Return: the number of nodes
 */

size_t list_len(shell_list_s *h)
{
	size_t count = 0;
	shell_list_s *current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/**
 * add_node - adds a new node at the beginnig of a shell_list_s list
 * @head: struct shell_list_s, 1st node
 * @ptr: the pointer
 * Return: new shel_list_s
 */

shell_list_s *add_node(shell_list_s **head, char *ptr)
{
	shell_list_s *new_node = NULL;

	if (head == NULL || ptr == NULL)
		return (NULL);

	new_node = do_mem(sizeof(shell_list_s), NULL);
	if (new_node == NULL)
		return (NULL);
	new_node->ptr = ptr;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * add_node_end - adds a new node at the end oof a linked list
 * @ptr: the pointer
 * @head: struct shell_list_s, node
 * Return: new shell_list_s
 */

shell_list_s *add_node_end(shell_list_s **head, char *ptr)
{
	shell_list_s *new_node = NULL, *last_node = NULL;

	/* Allocate memory for the new node */
	new_node = do_mem(sizeof(shell_list_s), NULL);

	if (!new_node)
		return (NULL);

	/* Assign the provided data to the new node */
	new_node->ptr = ptr;
	new_node->next = NULL;

	/* If the list is empty, make the new node the head and return it */
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	/* Tranverse the list to find the laast node */
	last_node = *head;
	while (last_node->next != NULL)
		last_node = last_node->next;
	/* Add the new node at the end of the list */
	last_node->next = new_node;

	return (new_node);
}

/**
 * free_list - it frees a shell_list_s list
 * @head: linked list, shell_list_s
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
