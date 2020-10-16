#include "menger.h"
#include <stdio.h>
#include <string.h>

/**
 * menger - draws 2D menger sponge
 * @level: level
 */
void menger(int level)
{
char *ptr;
int tr;
tr = 0;

if (level < 0)
{
return;
}
if (level == 0)
{
printf("#\n");
return;
}
ptr = malloc(sizeof(char) * 3);
ptr[0] = '#';
ptr[1] = '\n';
ptr[2] = '\0';
while (tr < level)
{
tr++;
ptr = raise(ptr, tr);
}
printf("%s", ptr);
free(ptr);
}

/**
 * raise - raise the level
 * @bob: string
 * @r: level
 * Return: a string
 */
char *raise(char *bob, int r)
{
double len;

len = pow((double)3, (double)r);
return (do_bob(bob, (int)len));
}

/**
 * do_bob - return the Merge Sponge,
 * @bob: str
 * @ln: size
 * Return: a string
 */
char *do_bob(char *bob, int ln)
{
char *x, *y;
char *n, *t;
int sz, fg, nums;
sz = (ln + 1) * (ln / 3) + 1;
y = malloc(sizeof(char) * sz);
x = malloc(sizeof(char) * sz);
n = strdup((const char *)bob);
t = strtok(n, "\n");
fg = 0;
nums = 0;
while (nums < 3)
{
fg = mix(x, y, fg, t, nums);
nums++;
}
y[fg] = '\n';
x[fg] = '\n';
fg++;
t = strtok(NULL, "\n");
while (t)
{
nums = 0;
while (nums < 3)
{
fg = mix(x, y, fg, t, nums);
nums++;
}
y[fg] = '\n';
x[fg] = '\n';
fg++;
t = strtok(NULL, "\n");
}
y[fg] = '\0';
x[fg] = '\0';
free(n);
free(bob);
bob = unite(x, y, ln);
free(x);
free(y);
return (bob);
}

/**
 * mix - The functio
 * @lim: string
 * @h: string
 * @e: int type
 * @s: char type
 * @a: int ype
 * Return: next char
 */
int mix(char *lim, char *h, int e, char *s, int a)
{
int ctr;

ctr = 0;

while (s[ctr])
{
if (a != 1)
{
h[e] = s[ctr];
}
else
{
h[e] = ' ';
}
lim[e] = s[ctr];
ctr++;
e++;
}
return (e);
}
/**
 * unite - concatenation
 * @x: string
 * @y:string
 * @len: size
 * Return: a string
 */
char *unite(char *x, char *y, int len)
{
int cap;
int count;
int a;
char *bob;
cap = ((len + 1) * len) +1;
bob = malloc(sizeof(char) * cap);
a = 0;
count = 0;
while (x[count])
{
bob[a] = x[count];
a++;
count++;
}

count = 0;
while (y[count])
{
bob[a] = y[count];
a++;
count++;
}
count = 0;
while (x[count])
{
bob[a] = x[count];
a++;
count++;
}
bob[a] = '\0';
return (bob);
}
