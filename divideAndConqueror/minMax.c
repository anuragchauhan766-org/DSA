#include <stdio.h>
#include <stdlib.h>

int *minMan(int arr[], int i, int j)
{
    int *minMax = (int *)malloc(2 * sizeof(int));

    if (i == j)
    {
        minMax[0] = arr[i];
        minMax[1] = arr[i];
        return minMax;
    }

    if (i == j + 1)
    {
        minMax[0] = (arr[i] < arr[j]) ? arr[i] : arr[j];
        minMax[1] = (arr[i] > arr[j]) ? arr[i] : arr[j];
        return minMax;
    }

    int mid = i + (j - i) / 2;
    int *minMaxLeft = minMan(arr, i, mid);
    int *minMaxRight = minMan(arr, mid + 1, j);

    minMax[0] = (minMaxLeft[0] < minMaxRight[0]) ? minMaxLeft[0] : minMaxRight[0];
    minMax[1] = (minMaxLeft[1] > minMaxRight[1]) ? minMaxLeft[1] : minMaxRight[1];

    free(minMaxLeft);
    free(minMaxRight);

    return minMax;
}

int main(void)
{
    int arr[] = {3, 5, 7, 9, 2, 6, 10, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *result = minMan(arr, 0, n - 1);

    printf("Minimum element: %d\n", result[0]);
    printf("Maximum element: %d\n", result[1]);

    free(result);

    return 0;
}
