#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> arr{5, 23, 43, 44, 11};
    for (int k = 0; k < arr.size(); k++)
    {
        for (int i = 0; i < arr.size() - (k + 1); i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
