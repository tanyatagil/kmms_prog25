#include "sorting.hpp"

namespace ttv
{
    void insertion_sort(int* arr, int size)
    {
        for (int i = 1;i < size; i++)
        {
            int key = arr[i];
            int prev = i - 1;
            while (prev >= 0 && arr[prev] > key)
            {
                arr[prev + 1] = arr[prev];
                --prev;
            }
            arr[prev + 1] = key;
        }
    }
}
