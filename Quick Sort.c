#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int low, int high)
{
    int pivot = nums[low];
    int i = low + 1;
    int j = high;

    while(i <= j)
    {
        while(i <= high && nums[i] <= pivot)
            i++;

        while(nums[j] > pivot)
            j--;

        if(i < j)
            swap(&nums[i], &nums[j]);
    }

    swap(&nums[low], &nums[j]);

    return j;
}

void quickSort(int nums[], int low, int high)
{
    if(low < high)
    {
        int p = partition(nums, low, high);

        quickSort(nums, low, p-1);
        quickSort(nums, p+1, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    int nums[n];
   srand(time(0));


    printf("Generated elements:\n");
    for(int i = 0; i < n; i++)
    {
        nums[i] = rand() % 1000000;
        printf("%d ", nums[i]);
    }

    clock_t start, end;

    start = clock();

    quickSort(nums, 0, n - 1);

    end = clock();

    printf("\n\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
