#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: head
 * Return: The address of the node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *x = head;
	listint_t *y = head;

	if (!head)
		return (NULL);
	if (!(head->next))
		return (NULL);

	while (x && y && y->next)
	{
		x = x->next;
		y = y->next->next;

		if (x == y)
		{
			x = head;
			while (x != fast)
			{
				x = x->next;
				y = y->next;
			}

			return (x);
		}
	}
	return (0);
}
