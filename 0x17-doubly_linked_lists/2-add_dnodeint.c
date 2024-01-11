#include "lists.h"

static dlistint_t *new_node(dlistint_t **head, const int n);

/**
 * add_dnodeint - add a new at the start of a linklist
 * @head: pointer to a pointer of a linked list
 * @n: value to set the node to
 * Return: a pointer to the new node created.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
dlistint_t *node;

node = new_node(head, n);
if (!node)
return (NULL);
*head = node;
return (node);
}

/**
 * new_node - create a new node
 * @head: pointer to a pointer of a linked list
 * @n: value to set the new node
 * Return: pointer to a new node on Sucess else NULL.
 */
static dlistint_t *new_node(dlistint_t **head, const int n)
{
dlistint_t *node;

node = malloc(sizeof(dlistint_t));
if (!node)
return (NULL);
node->n = n;
node->prev = NULL;
node->next = NULL;

if (*head)
{
node->next = *head;
(*head)->prev = node;
}

return (node);
}
