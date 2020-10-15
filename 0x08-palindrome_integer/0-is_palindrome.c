#include "palindrome.h"
/**
 * is_palindrome - this function check if an unsigned integer is a palindrome
 * @n: given int
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
unsigned long z;
unsigned long s;
unsigned long t;

z = n;
s = 0;

if (n == 0)
{
return (1);
}

while (n != 0)
{
t = n % 10;
s = s * 10 + t;
n /= 10;
}
if (z == s)
{
return (1);
}
else
{
return (0);
}

}
