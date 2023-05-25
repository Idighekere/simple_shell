#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * __free_list_full - frees list_t and all contained pointers
 * @head: linked list , list_t
 */
void __free_list_full(shell_list_t *head)
{
	shell_list_t *hold = NULL;

	while (head != NULL)
	{
		hold = head;
		head = head->next;
		/* printf("EXITMEMORY: %s\n", (char *)(hold->ptr)); */
		free(hold->ptr);
		free(hold);
	}
}

/**
 * __get_node_at_index - return nth node of a linked list
 * @head: pointer to the start of linked list
 * @index: index
 * Return: the nth node
 */
shell_list_t *__get_node_at_index(shell_list_t *head, unsigned int index)
{
	unsigned int i = 0;

	for (i = 0; head; i++, head = (*head).next)
		if (i == index)
			return (head);
	return (NULL);
}

/**
 * _insert_node - inserts a new node at a given position
 * @head: pointer to the beginning of linked list
 * @idx: index where to insert
 * @ptr: value for ptr
 * Return: address of new node or NULL if fails
 */
shell_list_t *_insert_node(shell_list_t **head, unsigned int idx, void *ptr)
{
	shell_list_t *new = NULL, *hold = *head;
	unsigned int i = 0;

	if (!idx)
	{
		new = malloc(sizeof(shell_list_t));
		if (!new)
			return (NULL);

		(*new).ptr = ptr;
		(*new).next = *head;

		*head = new;

		return (*head);
	}

	while (hold)
	{
		if (i == (idx - 1))
		{
			new = malloc(sizeof(shell_list_t));
			if (!new)
				return (NULL);
			(*new).ptr = ptr;
			(*new).next = (*hold).next;
			(*hold).next = new;
			return (new);
		}
		hold = (*hold).next;
		i++;
	}
	return (NULL);
}

/**
 * __delete_node_at_index - deletes a node at a given position
 * @head: pointer to the beginning of linked list
 * @index: index to be deleted
 * Return: 1 if succesful -1 if fails
 */
int __delete_node_at_index(shell_list_t **head, unsigned int index)
{
	shell_list_t *hold = NULL, *delete = NULL;
	unsigned int i = 0, action = 0;

	if (!*head)
		return (-1);
	for (i = 0, hold = *head; hold && index; i++, hold = (*hold).next)
		if (i == (index - 1))
		{
			action = 1;
			break;
		}

	if (action)
	{
		delete = (*hold).next;
		(*hold).next = (*delete).next;
		free(delete);
		return (1);
	}
	else if (!index && (**head).next)
	{
		delete = *head;
		*head = (*delete).next;
		free(delete);
		return (1);
	}
	else if (!index && *head)
	{
		*head = NULL;
		free(*head);
		return (1);
	}
	return (-1);
}
