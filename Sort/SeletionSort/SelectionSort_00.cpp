#include <iostream>

// 3개 숫자 정렬 
bool checkSorted(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return (false);
        }
    }
    return (true);
}

void mySwapPTR(int* a, int* b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void mySort(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                mySwapPTR(&arr[j], &arr[j + 1]);
            }
        }
    }
}

using namespace std;
int main()
{
    for (int k = 0; k < 3; k++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                int arr[3] = { i, j, k };
                int size = sizeof(arr) / sizeof(arr[0]);

                for (int e = 0; e < size; e++)
                {
                    cout << arr[e] << " " << flush;
                }
                
                cout << " --> " << flush;
                // TODO: 정렬 해보기
                // mySort(arr, size);

                if (arr[0] > arr[1])
                    mySwapPTR(&arr[0], &arr[1]);

                if (arr[1] > arr[2])
                    mySwapPTR(&arr[1], &arr[2]);

                if (arr[0] > arr[1])
                    mySwapPTR(&arr[0], &arr[1]);

                for (int e = 0; e < size; e++)
                {
                    cout << arr[e] << " " << flush;
                }

                cout << boolalpha;
                cout << checkSorted(arr, size);
                cout << endl;
            }
        }
    }
    return (0);
}
