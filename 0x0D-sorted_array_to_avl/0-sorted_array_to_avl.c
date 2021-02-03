#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: array
 * @size: size
 * Return: pointer to root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;
	head = NULL;

	head = add(&head, size - 1, 0, array);
	return head;
}


/**
 * create - create a avl  tree
 * @parent: node to add new node
 * @data: data to insert
 * Return: pointer
 */
avl_t *create(avl_t *parent, int data)
{
	avl_t *node;
	node = NULL;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
	{
		return (NULL);
	}

	node->n = data;
	node->parent = parent;
	node->right = NULL;
	node->left = NULL;
	return node;
}
/**
 * add - add a new node
 * @head: the head of the b tree
 * @array: array
 * @finish: end of array
 * @begin: start of array
 * Return: pointer
 */
avl_t *add(avl_t **head, int finish, int begin, int *array)
{
	int center;
	avl_t *newNode;
	newNode = NULL;

	if (begin > finish)
	{
		return (NULL);
	}
	center = (begin + finish) / 2;
	newNode = create(*head, array[center]);
	if (center != begin)
	{
		newNode->left = add(&newNode, center - 1, begin, array);
	}
	if (center != finish)
	{
		newNode->right = add(&newNode, finish, center + 1, array);
	}
	return newNode;
}
