#include "main.h"
/**
 * _strcmp - Compares pointer to two strings
 * @s1: parameter 1
 * @s2: parameter 2
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}
return (*s1 - *s2);
}

