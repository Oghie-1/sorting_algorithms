#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/* Define the listint_t type
 ** struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 * */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/* Function to print an array of integers */
void print_array(const int *array, size_t size);

/* Bubble Sort function */
void bubble_sort(int *array, size_t size);

/* Insertion sort*/
void insertion_sort_list(listint_t **list);

/* Selection Sort */
void selection_sort(int *array, size_t size);

/* Function to print a list */
void print_list(const listint_t *list);

/* Sorts an array of integers using the quicksort algorithm*/
void quicksort(int *array, int low, int high, size_t size);

/* Function that initiates the quicksort algorithm*/
void quick_sort(int *array, size_t size);


void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/*Function that sorts an array on integers*/
void shell_sort(int *array, size_t size);
#endif /* SORT_H */
