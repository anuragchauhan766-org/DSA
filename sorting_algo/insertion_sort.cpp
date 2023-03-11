
#include <iostream>
using namespace std;

// working

/*
   index ==   0    1   2   3   4   5

   array      12,| 45, 23, 51, 19, 8      pass =1 ,key =45 ,j=0
              12,| 45, 23, 51, 19, 8      1 st pass done

              12, 45,| 23, 51, 19, 8      pass=2 key =23,j=1
              12, 45,| 45, 51, 19, 8      pass =2 key =23 j=0
              12, 23,| 45, 51, 19, 8      pass 2 done

              12, 23, 45,| 51, 19, 8      pass = 3, key = 51 , j=2
              12, 23, 45,| 51, 19, 8        pass 3 done

              12, 23, 45, 51,| 19, 8      pass =4 key = 19,j=3
              12, 23, 45, 51,| 51, 8      pass =4 key = 19,j=2
              12, 23, 45, 45,| 51, 8      pass =4 key = 19,j=1
              12, 23, 23, 45,| 51, 8      pass =4 key = 19,j=0
              12, 19, 23, 45,| 51, 8      pass 4 done

              12, 19, 23, 45, 51,| 8      pass=5 key = 8 ,j=4
              12, 19, 23, 45, 51,| 51      pass=5 key = 8 ,j=3
              12, 19, 23, 45, 45,| 51      pass=5 key = 8 ,j=2
              12, 19, 23, 23, 45,| 51      pass=5 key = 8 ,j=1
              12, 19, 19 , 23, 45,| 51      pass=5 key = 8 ,j=0
              8, 12, 19 , 23, 45,| 51     pass 5 done

              array sorted complete
*/

void insertion_sort(int arr[], int size)
{
    int key, j;
    for (int pass = 1; pass < size; pass++)
    {
        key = arr[pass];
        j = pass - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[++j] = key;
    }
}
int main()
{
    int arr[] = {12, 45, 23, 51, 19, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}