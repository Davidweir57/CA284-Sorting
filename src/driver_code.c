#include <stdio.h>
#include "generator.h"
#include <time.h>
#include "allSorts.h"

int main()
{
    int *array, count;

    printf("How long is your list of integers:\n");
    scanf("%d", &count);
    
    array = gen(count);
    
    int t = clock();
    s_sort(array, count);

    printf("\nSorted:\n");
    for(int j=0; j<count; j++)
        printf("%d ", array[j]);

    t = clock() - t;
    // prints the time the program takes
    printf("\nElapsed time: %f seconds\n", ((double)t) / CLOCKS_PER_SEC);
}