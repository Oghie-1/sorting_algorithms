#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* Define the listint_t type */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function to print an array of integers */
void print_array(const int *array, size_t size);

/* Bubble Sort function */
void bubble_sort(int *array, size_t size);

/* Insertion sort*/
void insertion_sort_list(listint_t **list);


/* Function to print a list */
void print_list(const listint_t *list);

#endif /* SORT_H */
