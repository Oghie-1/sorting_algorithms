#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints all the elements of a doubly linked list
 * @list: Pointer to the head of the list
 */

void print_list(const listint_t *list)
{
const listint_t *current = list;

while (current != NULL)
{
printf("%d", current->n);
current = current->next;
if (current != NULL)
printf(", ");
}
printf("\n");
}
