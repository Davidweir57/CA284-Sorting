void swap(int* e1, int* e2)
{
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
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

// recursive quicksort
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        // reducing recursion depth by using recursion for smaller partitions and iteration for the larger parts.
        // This is because previous code caused a platform limit at larger numbers
        // Without this issues arised on numbers over 100,000 on sorted and reverse sorted arrays
        int pivot = partition(arr, start, end);
        if (pivot - start < end - pivot)
        {
            quicksort(arr, start, pivot - 1);
            start = pivot + 1;
        }
        else
        {
            quicksort(arr, pivot + 1, end);
            end = pivot - 1;
        }
    }
}
