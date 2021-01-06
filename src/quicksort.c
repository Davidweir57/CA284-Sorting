#include "quicksort.h"

int partition(int arr[], int lo, int hi)
{
    int pivot = arr[hi]; // pivot is set as the last element of the array
    int i = (lo - 1); // index of smaller element

    for(int j=lo; j <= hi-1; j++)
    {
        // if our current element is smaller than the pivot we swap the smaller element and our current element
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[hi]);
    return (i+1);
}

// recursive quicksort
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);

        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1, end);
    }
}

void swap(int* e1, int* e2)
{
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}