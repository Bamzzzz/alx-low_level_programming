#include "lists.h"

/**
 * dlistint_len - count the number of elements in a link list
 * @h: a pointer to head
 * Return: return the number of elements.
 */
size_t dlistint_len(const dlistint_t *h)
{
size_t count = 0;

if (!h)
return (0);
while (h->prev)
h = h->prev;
while (h)
{
count++;
h = h->next;
}
return (count);
}
