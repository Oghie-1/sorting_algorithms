#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



/**
 * struct listint_s - Doubly linked list node structure
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
};

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
`listint_t *current, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
temp = current->next;

while (current->prev != NULL && current->n < current->prev->n)
{
current->prev->next = current->next;
if (current->next != NULL)
current->next->prev = current->prev;
current->next = current->prev;
current->prev = current->prev->prev;
current->next->prev = current;

if (current->prev == NULL)
*list = current;
else
current->prev->next = current;

print_list(*list);
}

current = temp;
}
}
