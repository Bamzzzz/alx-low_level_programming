#include "lists.h"

static dlistint_t *new_node(int n);

/**
 * insert_dnodeint_at_index - inserts a node at a choosen postion
 * @h: pointer of a pointer to linked list.
 * @idx: position to add the new node at.
 * @n: value to set the new node to.
 * Return: a pointer to the add node else NULL if fail.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *node, *new;
size_t i = 0;

if (!(*h) && !idx)
return (*h = new_node(n));
else if (!idx)
return (*h = add_dnodeint(h, n));
node = *h;
if (node->prev)
while (node->prev)
node = node->prev;
else if (!node->next)
while (node->prev)
node = node->prev;

while (++i < idx && node->next)
{
node = node->next;
}
if (i < idx)
return (NULL);
else if (node)
{
new = new_node(n);
if (!new)
return (NULL);
if (node->next)
node->next->prev = new;
new->prev = node;
new->next = node->next;
node->next = new;
}
return (new);
}

/**
 * new_node - creates a new node
 * @n: value to set the new node to
 * Return: pointer to a new node
 */
static dlistint_t *new_node(int n)
{
dlistint_t *node;

node = malloc(sizeof(dlistint_t));
if (!node)
return (NULL);
node->n = n;
node->next = node->prev = NULL;

return (node);
}
