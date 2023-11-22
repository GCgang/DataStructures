#include <iostream>

void mySwapREF(int& a, int& b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void mySwapPTR(int* a, int* b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

bool checkSorted(int i, int j)
{
    if (i <= j)
    {
        return (true);
    }
    return (false);
}

int main()
{
    using namespace std;

    {
        int a = 3;
        int b = 2;

        cout << a << " " << b << endl;

        // TODO: a, b Swap
        mySwapREF(a, b);
        cout << a << " " << b << endl;

        mySwapPTR(&a, &b);
        cout << a << " " << b << endl;
    }
    // 정렬(sorting)
    {
        int arr[] = { 4, 2 };

        cout << arr[0] << " " << arr[1] << endl;

        //TODO: 정렬되어 있지 않다면 arr[0], arr[1] Swap
        if (arr[0] > arr[1])
        {
            mySwapPTR(&arr[0], &arr[1]);
        }
        cout << arr[0] << " " << arr[1] << endl;

    }
    // 값과 상관 없이 작은 값이 먼저 출력되게 하려면?
    // 두 값이 같을 때는 순서가 상관 없음 -> 큰 값이 먼저 출력
    {
        int arr[2];

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                arr[0] = i;
                arr[1] = j;

                // swap 사용
                if (arr[0] > arr[1])
                    std::swap(arr[0], arr[1]);
                
                std::cout << std::boolalpha;
                std::cout << arr[0] << " ";
                std::cout << arr[1] << " ";
                std::cout << checkSorted(arr[0], arr[1]) << std::endl;
            }
        }
    }
    return (0);
}
