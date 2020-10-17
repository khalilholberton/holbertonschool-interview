#include "binary_trees.h"

/**
 * insert - represents where to add the new node
 * @root: pointer
 * Return: pointer.
 */
heap_t *insert(heap_t *root)
{


int bx = 0, ax = 0;
heap_t *last_n[50];
heap_t *rec = root;

while (rec && rec->left && rec->right)
{
last_n[ax] = rec->left;
ax = ax + 1;
if (ax >= 49)
{
ax = 0;
}
last_n[ax] = rec->right;
ax = ax + 1;
if (ax >= 49)
{
ax = 0;
}
rec = last_n[bx];
bx = bx + 1;
if (bx >= 49)
{
bx = 0;
		}

}

return (rec);
}

/**
 * heap_insert - function to add a value
 * @root: pointer to pointer
 * @value: value
 * Return: pointer
 */
heap_t *heap_insert(heap_t **root, int value)
{

int elem;
heap_t *rt;
heap_t *adr;

if (root == NULL)
{
return (NULL);
}

if (*root == NULL)
{
rt = binary_tree_node(*root, value);
*root = rt;
return (rt);
}

adr = insert(*root);
rt = binary_tree_node(adr, value);
if (!adr->left)
{
adr->left = rt;
}
else
{
adr->right = rt;
}

while (rt->parent && rt->n > rt->parent->n)
{
elem = rt->parent->n;
rt->parent->n = rt->n;
rt->n = elem;
rt = rt->parent;
}
return (rt);
}
