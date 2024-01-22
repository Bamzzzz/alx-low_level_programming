#include "main.h"
/**
 * print_lines - prints straight line on the  terminal
 * @n: number of times the character '_' will be printed
 * Return: void
 */
void print_line(int n)
{
if (n <= 0)
_putchar('_');
else
{
int i;
for (i = 1; i <= n; i++)
_putchar('_');
_putchar('\n');
}
}
