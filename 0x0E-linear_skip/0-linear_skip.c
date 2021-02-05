#include "search.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/**
 * linear_skip - searches for a value
 * @list: list
 * @value: integer.
 * Return: the pointer or null
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *var;
skiplist_t *point;
char *m = "Value checked at index [%lu] = [%d]\n";
char *t = "Value found between indexes [%lu] and [%lu]\n";

if (list == NULL)
return (NULL);
var = list->express;
point = list;
while (var)
{
printf(m, var->index, var->n);
if (!var->express || var->n >= value)
{
if (!var->express && var->n < value)
{
point = var;
while (var->next)
var = var->next;
}
printf(t, point->index, var->index);
while (point)
{
printf(m, point->index, point->n);
if (point->n == value)
{
return (point);
}
if (point->n > value)
{
return (NULL);
}
point = point->next;
}
break;
}
point = var;
var = var->express;
}
return (NULL);
}
