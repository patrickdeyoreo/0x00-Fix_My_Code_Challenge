#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr = head ? *head : NULL;
	dlistint_t *prev = NULL;
	unsigned int pos = 0;

	if (curr)
	{
		prev = curr;
		curr = curr->next;
		if (index == 0)
		{
			*head = curr;
			if (curr)
				curr->prev = NULL;
			free(prev);
			return (1);
		}
		while (curr && pos < index)
		{
			prev = curr;
			curr = curr->next;
			pos += 1;
		}
		if (index == pos)
		{
			prev->prev->next = curr;
			if (curr)
				curr->prev = prev->prev;
			free(prev);
			return (1);
		}
	}
	return (-1);
}
