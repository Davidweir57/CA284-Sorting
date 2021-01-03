#include <stdio.h>
#include "generator.h"
#include <time.h>
#include "allSorts.h"

void printarray(int array[], int count);

int main()
{
    int *array, count;

    printf("How long is your list of integers:\n");
    scanf("%d", &count);
    
    array = gen(count);
    
    int t = clock(); // initialise t to time the sorting algorithm

    // Code for timing Selection Sort

    s_sort(array, count); // sorts the generated array using selection sort

    printf("\n\nSelection Sort:\n");

    t = clock() - t;
    // prints the time the program takes
    printf("\nElapsed time for Selection Sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    printarray(array, count); // prints array. This is done after the time is calculated so it does not effect our result

    // Code to time Merge Sort

    t = clock(); // reinitialise t
    mergesort(array, 0, count-1); // Calls mergesort algorithm

    printf("\n\nMerge Sort:\n");

    t = clock() - t;
    printf("\nElapsed time for Merge Sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    printarray(array, count);

    // Code to time Quick Sort

    t = clock(); // reinitialise t
    quicksort(array, 0, count-1); // Calls Quick Sort algorithm

    printf("\n\nQuick Sort:\n");

    t = clock() - t;
    printf("\nElapsed time for Quick Sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    printarray(array, count);
}

void printarray(int array[], int count)
{
    for(int i=0; i<count; i++)
        printf("%d ", array[i]);
}
