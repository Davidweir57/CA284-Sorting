#include <stdio.h>
#include <time.h>

void s_sort(int arr[], int len);
void merge(int arr[], int left, int mid, int right);
void mergesort(int arr[], int left, int right);
void quicksort(int arr[], int start, int end);
int partition(int arr[], int lo, int hi);
void swap(int* e1, int* e2);

void s_sort(int arr[], int len)
{
    int i, j, pos, tmp;

    for (i=0; i<len; i++)
    {
        pos = i;

        // finds the smallest element of the unsorted array
        for (j=i+1; j < len; j++)
        {
            if (arr[pos] > arr[j])
                pos = j;
        }

        // swaps the smallest element of the unsorted array with the element in it's position
        if (pos != i)
        {
            tmp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = tmp;
        }
    }

}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, start;
    int mem1 = mid - left + 1;
    int mem2 = right - mid;
 
    // create temp arrays
    int lst1[mem1], lst2[mem2];
 
    // Copy data to temp arrays lst1[] and lst2[]
    for (i = 0; i < mem1; i++)
        lst1[i] = arr[left + i];
    for (j = 0; j < mem2; j++)
        lst2[j] = arr[mid + 1 + j];
 
    i = 0;
    j = 0;
    start = left; 
    while (i < mem1 && j < mem2) {
        if (lst1[i] <= lst2[j]) {
            arr[start] = lst1[i];
            i++;
        }
        else {
            arr[start] = lst2[j];
            j++;
        }
        start++;
    }

    //copies remaining elements of both subarrays to the merged array
    while (i < mem1) {
        arr[start] = lst1[i];
        i++;
        start++;
    }
 
    while (j < mem2) {
        arr[start] = lst2[j];
        j++;
        start++;
    }
}
 
// recursive mergesort
void mergesort(int arr[], int left, int right)
{
    if (left < right) {

        int mid = left + (right - left) / 2;
 
        // Sort first and second halves
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
 
        merge(arr, left, mid, right);
    }
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

void swap(int* e1, int* e2)
{
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}