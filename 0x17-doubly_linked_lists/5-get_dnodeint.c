#include "lists.h"

/**
 * get_dnodeint_at_index - gets a node at an index.
 * @head: pointer of a linked list
 * @index: position at which to get a node form in a list
 * Return: pointer of the found node or else NULL.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
size_t idx = 0;
dlistint_t *node;

if (!head)
return (NULL);
node = head;
if (node->prev)
node = node->prev;
while (idx < index && node)
{
node = node->next;
idx++;
}
return (node);
}
