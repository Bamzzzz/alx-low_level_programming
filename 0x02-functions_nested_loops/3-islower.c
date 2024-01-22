#include "main.h"
/**
 * _islower - checks for lowercase character
 * @c: parameter to be checked
 * Return 1 for lowercase character or 0 for anthing else
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
