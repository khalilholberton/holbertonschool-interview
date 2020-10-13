#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a number in a sorted linked list
 * @head: pointer
 * @number: int type
 * Return: new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_n;
	listint_t *ptr;

	if (!head)
	{
		return (NULL);
	}
	new_n = malloc(sizeof(listint_t));
	if (new_n == NULL)
	{
		return (NULL);
	}
	ptr = *head;
	new_n->n = number;
	new_n->next = NULL;

	if (!*head)
	{
		*head = new_n;
		return (new_n);
	}

	if (ptr->n > number)
	{
		*head = new_n;
		new_n->next = ptr;
		return (new_n);
	}

	while (ptr->next && ptr->next->n < number)
		ptr = ptr->next;
	new_n->next = ptr->next;
	ptr->next = new_n;
	return (new_n);
}

