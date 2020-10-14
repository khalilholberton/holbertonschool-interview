#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - verify if a  singly linked list has a cycle
 * @list: pointer
 * Return: 1 if list has a cycle, 0 otherwise.
 **/

int check_cycle(listint_t *list)
{
	listint_t *a;
	listint_t *b;

	if (list->next == NULL)
	{
		return (0);
	}
	if (list == NULL)
	{
		return (0);
	}
	b = list->next->next;
	a = list->next;

	while (a && b  && b->next)
	{
		if (a == b->next)
			return (1);
		a = a->next;
		b = b->next->next;
	}
	return (0);
}
