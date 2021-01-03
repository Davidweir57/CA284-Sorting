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
    
    int t = clock();
    s_sort(array, count);

    printf("\n\nSelection Sort:\n");
    printarray(array, count);

    t = clock() - t;
    // prints the time the program takes
    printf("\nElapsed time for s_sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);

    t = clock();
    mergesort(array, 0, count-1);

    printf("\n\nMerge Sort:\n");
    printarray(array, count);

    t = clock() - t;
    printf("\nElapsed time for s_sort: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);
}

void printarray(int array[], int count)
{
    for(int i=0; i<count; i++)
        printf("%d ", array[i]);
}