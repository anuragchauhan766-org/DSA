
#include <iostream>
using namespace std;
void count_sort(int arr[], int size)
{

    // getting max element in array
    int max = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // creating a count arr of size of (max + 1)
    int count_arr[max + 1];

    // intializing every element to zero
    for (int i = 0; i <= max; i++)
    {
        count_arr[i] = 0;
    }

    // getting count of elements in count arr
    for (int j = 0; j < size; j++)
    {

        count_arr[arr[j]]++;
    }
    // sorting the by using the count array
    int index = 0;
    for (int k = 0; k <= max; k++)
    {
        // while (count_arr[k] != 0)
        // {
        //     arr[index] = k;
        //     index++;
        //     count_arr[k]--;
        // }
        // ** or
        int i = 0;
        while (i < max + 1)
        {
            if (count_arr[i] > 0)
            {
                arr[index] = i;
                index++;
                count_arr[i]--;
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    int arr[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    count_sort(arr, size);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}