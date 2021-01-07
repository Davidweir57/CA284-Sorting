#include <stdlib.h>
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int mem1 = mid - left + 1;
    int mem2 = right - mid;
 
    // temp arrays
    // arrays are dynamically allocated memory so they can work on larger numbers (without this issues rise at numbers toughly greater than 500,000)
    int* lst1 = malloc((mem1) * sizeof(int));
    int* lst2 = malloc((mem2) * sizeof(int));

    // fill temp arrays
    for (i = 0; i < mem1; i++)
        lst1[i] = arr[left + i];
    for (j = 0; j < mem2; j++)
        lst2[j] = arr[mid + 1 + j];
 
    // merging
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < mem1 && j < mem2)
    {
        if (lst1[i] <= lst2[j])
        {
            arr[k] = lst1[i];
            i++;
        }
        else
        {
            arr[k] = lst2[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of lst1[]
    while (i < mem1)
    {
        arr[k] = lst1[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of lst2[]
    while (j < mem2)
    {
        arr[k] = lst2[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
 
    }
    int mid = (left + right - 1) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}
 