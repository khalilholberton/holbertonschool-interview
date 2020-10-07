#include "slide_line.h"
/**
 * slide_line - function that slides and merges an array of integers
 * @line: array of integers
 * @size: size
 * @direction: LEFT or RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t as = 0, bs = 1, ref = 0;
	size_t x, y;
	size_t back;
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	if (direction == SLIDE_RIGHT)
	{
		as = size - 1;
		bs = size - 2;
	}
	x = 0;
	while (x < size)
	{
		back = bs;
		ref = 0;
		y = x + 1;
		while ( y < size)
		{
			if (line[as] != 0)
			{
				if (line[bs] == line[as])
				{
					line[as] *= 2;
					line[bs] = 0;
					break;
				}
			}
			if (line[as] == 0 && line[bs] != 0)
			{
				line[as] = line[bs];
				line[bs] = 0;
				ref = 1;
				bs = back;
				x--;
				break;
			}
			if (line[bs] != 0)
				break;
			direction == SLIDE_LEFT ? bs++ : bs--;
			y++;
		}
		if (line[as] == 0)
			break;
		if (ref == 0)
		{
			if (direction == SLIDE_LEFT)
			{
				as++;
				bs = as + 1;
			}
			else if (direction == SLIDE_RIGHT)
			{
				as--;
				bs = as - 1;
			}
		}
		x++;
	}
	return (1);
}
