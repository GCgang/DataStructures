#include <iostream>
#include <algorithm>

void Print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i, j;

    for (i = 0; i < size - 1; i++)
    {
        bool swapped = false;

        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
            Print(arr, size);
        }
        std::cout << std::endl;

        if (swapped == false)
            break;
    } 
    return (0);
}