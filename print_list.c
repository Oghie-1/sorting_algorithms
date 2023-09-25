#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints all the elements of a doubly linked list
 * @list: Pointer to the head of the list
 */

void print_list(const listint_t *list)
{
while (list)
{
printf("%d\n", list->n);
list = list->next;
}
}
