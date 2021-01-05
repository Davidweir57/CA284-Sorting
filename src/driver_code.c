#include <stdio.h>
#include <stdlib.h>
#include "generator.h"
#include <time.h>
#include "mergesort.h"
#include "quicksort.h"
#include "s_sort.h"

void printarray(int array[], int count);

int main()
{
    int *array, *copy_arr, count;

    printf("How long is your list of integers:\n");
    scanf("%d", &count);

    array = (int*)malloc(count * sizeof(int));
    
    array = gen(count);

    copy_arr = (int*)malloc(count * sizeof(int));;

    // creates a copy of our array so we can "unsort" to test our algorithm
    for(int i=0; i<count; i++)
    {
        copy_arr[i] = array[i];
    }
    
    int t = clock(); // initialise t to time the sorting algorithm

    // Code to time Merge Sort
    
    mergesort(array, 0, count-1); // Calls mergesort algorithm

    t = clock() - t;
    printf("\nElapsed time for merge: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    // Code to time inbuilt standard C implementation of qsort
    t = clock(); // reinitialise t

    qsort(array, count, sizeof(int), compare_ints); // uses C's inbuilt implemetation of quicksort for comparison

    t = clock() - t;
    printf("\nElapsed time for qsort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    for(int i=0; i<count; i++)
    {
        array[i] = copy_arr[i];
    }

    // Code to time Quick Sort

    t = clock(); // reinitialise t
    quicksort(array, 0, count-1); // Calls quicksort algorithm

    t = clock() - t;
    printf("\nElapsed time for Quick Sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    for(int i=0; i<count; i++)
    {
        array[i] = copy_arr[i];
    }

    // Code for timing Selection Sort

    t = clock();
    s_sort(array, count); // sorts the generated array using selection sort

    t = clock() - t;
    //prints the time the program takes
    printf("\nElapsed time for Selection Sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    free(array);

}

void printarray(int array[], int count)
{
    for(int i=0; i<count; i++)
        printf("%d ", array[i]);
    printf("\n");
}

