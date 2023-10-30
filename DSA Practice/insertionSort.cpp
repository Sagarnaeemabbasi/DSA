#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> arr{5, 4, 6, 2, 1};
    int key, j;
    for (int i = 1; i < arr.size(); i++)
    {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}