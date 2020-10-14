#include "binary_trees.h"

/**
 * binary_tree_node - Creates binary tree nodes
 * @parent: pointer
 * @value: value
 * Return: new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;

node = malloc(sizeof(binary_tree_t));
if (!node)
{
return (NULL);
}
node->left = NULL;
node->n = value;
node->right = NULL;
node->parent = parent;
return (node);
}
