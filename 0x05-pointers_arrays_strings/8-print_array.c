#include "main.h"
#include <stdio.h>
/**
 * print_array - print n elements of an array of integers
 * @a: array to be used
 * @n: number of elements to be printed
 * Return: void
 */
void print_array(int *a, int n)
{
int i;
for (i = 0 ; i < n ; i++)
{
printf("%d", a[i]);
if (i < n - 1)
printf(", ");
}
printf("\n");
}
