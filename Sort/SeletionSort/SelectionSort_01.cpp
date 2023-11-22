#include <iostream>
#include <fstream>
#include <algorithm> 

// 여러개 숫자 정렬
using namespace std;

struct Element
{
    int key;
    char value;
};

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

void Print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void Print(Element* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].key << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].value << " ";
    }
    cout << endl;
}

int main()
{
    // 가장 작은 수 찾기
    {
        int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
        int size = sizeof(arr) / sizeof(arr[0]);

        assert(size > 0); // 사이즈가 1 이상이라고 가정

        TODO:
        int minValue = arr[0];
        // int minValue = INT_MAX;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] < minValue)
            {
                minValue = arr[i];
            }
            // minValue = arr[i] < minValue ? arr[i] : minValue;
            // minValue = std::min(arr[i], minValue);
        }
        cout << "Minimun number is " << minValue << endl;
    }

    // 가장 작은 수의 인덱스 찾기
    {

        int arr[] = { 8, 3, 2, 5, 5, 3, 2, 5, 8, 1 };
        int size = sizeof(arr) / sizeof(arr[0]);

        assert(size > 0); // 사이즈가 1 이상이라고 가정
        
        // int minValue = arr[0];
        int minValue = INT_MAX;
        int minIndex = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] < arr[minIndex])
            {
                minIndex = i;
            }
        }
        cout << "The index of min is " << minIndex << endl;
        cout << "Minimun number is " << arr[minIndex] << endl;
    }

    // Selection Sort
    {
        int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
        int size = sizeof(arr) / sizeof(arr[0]);
        Print(arr, size);
        cout << endl;
        cout << endl;

        assert(size > 0); // 사이즈가 1 이상이라고 가정

        int minIndex;
        for (int i = 0; i < size - 1; i++)
        {
            minIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            // mySwapPTR(&arr[i], &arr[minIndex]);
            swap(arr[i], arr[minIndex]);

            Print(arr, size);
            cout << boolalpha;
            cout << checkSorted(arr, size);
            cout << endl;
        }

    }
    
    // 비교 횟수 세보기
    {
        ofstream ofile("log.txt");
        for (int size = 1; size < 1000; size++)
        {
            int count = 0;
            int* arr = new int[size];
            for (int s = 0; s < size; s++)
            {
                arr[s] = size - s;
            }

            int minIndex;
            for (int i = 0; i < size - 1; i++)
            {
                minIndex = i;
                for (int j = i + 1; j < size; j++)
                {
                    count++;

                    if (arr[j] < arr[minIndex])
                        minIndex = j;
                }
                swap(arr[i], arr[minIndex]);
            }
            ofile << size << ", " << count << endl;

            delete[] arr;
        }
        ofile.close();
    }

    // 안정성 확인(unstable)
    {
        
        Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
        int size = sizeof(arr) / sizeof(arr[0]);

        Print(arr, size);

        int minIndex;
        for (int i = 0; i < size - 1; i++)
        {
            minIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j].key < arr[minIndex].key)
                    minIndex = j;
            }
            swap(arr[i], arr[minIndex]);

            Print(arr, size);
        }
    }
    return (0);
}