#include <iostream>
using namespace std;

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
    // int arr[] = { 1, 2, 4, 5, 3, 6};
    int arr[] = { 1, 2, 3, 4, 5, 6};
    // int arr[] = { 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Print(arr, n);

    int i, key, j = 0;

    for (i = 1; i < n; i++)
    {
        key = arr[i];

        for (j = i; j > 0 && arr[j - 1] > key; j--) // 조기 종료 가능
        {
            arr[j] = arr[j - 1];

            cout << "Inner ";
            Print(arr, n);
        }

        arr[j] = key;

        cout << "Outer ";
        Print(arr, n);
    }

    return 0;
}