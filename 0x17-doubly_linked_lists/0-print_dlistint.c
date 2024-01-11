#include "lists.h"

/**
 * print_dlistint - print out the content of a dlistint
 * @h: pointer to a dlistint
 * Return: pointer to a dlistint
 */
size_t print_dlistint(const dlistint_t *h)
{
size_t count = 0;

if (!h)
return (0);

while (h->prev)
h = h->prev;

while (h)
{
printf("%d\n", h->n);
h = h->next;
count++;
}
return (count);
}
