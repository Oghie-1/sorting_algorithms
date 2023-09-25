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

/*Swap two integers in array*/
void swap_ints(int *a, int *b)

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

/* Function to swap two integers in an array */
void swap(int *a, int *b);

/* Lomuto partititonn scheme*/
int lomuto_partition(int *array, int low, int high, size_t size);

/* Sorts an array of integers using the quicksort algorithm*/
void quicksort(int *array, int low, int high, size_t size);

/* Function that initiates the quicksort algorithm*/
void quick_sort(int *array, size_t size);

/*Function that sorts an array on integers*/
void shell_sort(int *array, size_t size);
#endif /* SORT_H */
