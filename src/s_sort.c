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