#include "lists.h"

static dlistint_t *new_node(const int n);

/**
 * add_dnodeint_end - add a new node to the end of a linked list
 * @head: pointer to a pointer of a linked list
 * @n: value to set the new node to.
 * Return: a pointer to the new node added.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *node, *new;

if (*head)
{
node = *head;
while (node->next)
node = node->next;
new = new_node(n);
if (!new)
return (NULL);
node->next = new;
node->next->prev = node;
}
else
{
node = new_node(n);
if (!node)
return (NULL);
*head = node;
}
return (node);
}

/**
 * new_node - creates a new node and set it to a value given.
 * @n: value to set the new node
 * Return: a pointer to a new node.
 */
static dlistint_t *new_node(const int n)
{
dlistint_t *node;

node = malloc(sizeof(dlistint_t));
if (!node)
return (NULL);
node->n = n;
node->prev = NULL;
node->next = NULL;

return (node);
}
