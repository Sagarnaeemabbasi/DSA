#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> arr{5, 4, 6, 2, 1};
    int min = 0;
    for (int step = 0; step < arr.size(); step++)
    {
        for (int i = step + 1; i < arr.size(); i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        swap(arr[min], arr[step]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}