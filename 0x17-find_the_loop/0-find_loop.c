#include "lists.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
/**
 * find_listint_loop - locate a loop
 * @head: head
 * Return: address of the node
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *x = head;
listint_t *y = head;

if (!head)
{
return (NULL);
}

while (x && y && y->next)
{
x = x->next;
y = y->next->next;
if (x == y)
{
x = head;
while (x != y)
{
x = x->next;
y = y->next;
}

return (x);
}
}
return (0);
}
