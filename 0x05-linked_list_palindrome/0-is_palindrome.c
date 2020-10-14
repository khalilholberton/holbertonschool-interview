#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "lists.h"

/**
 * is_palindrome - verify if a singly list is palindrome
 * @head: pointer to pointer
 * Return: 1 if palindrome or 0
 */

int is_palindrome(listint_t **head)
{
	int x = 0;
	int count = 0;
	int y;
	listint_t *hd;
	listint_t *tail;

	if ((*head) == NULL)
	{
		return (1);
	}
	if (head == NULL)
	{
		return (0);
	}
	hd = *head;
	x = x + 1;
	for (tail = *head; tail->next; x++)
	{
		tail = tail->next;
	}
	y = x / 2;
	for (count = 0; count <= y; count++)
	{
		if (hd->n != tail->n)
		{
			return (0);
		}
		hd = hd + 2;
		tail = tail - 2;
	}
	return (1);
}
