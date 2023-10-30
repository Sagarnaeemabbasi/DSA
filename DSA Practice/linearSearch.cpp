#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> arr{34, 54, 65, 12, 3};
    int toSearch = 4;
    int searchFlag = 0;
    int arrayLength = arr.size();
    for (int i = 0; i < arrayLength; i++)
    {
        if (arr[i] == toSearch)
        {
            cout << "found at index : " << i;
            searchFlag = 1;
            break;
        }
    }
    if (searchFlag == 0)
    {
        cout << "Element not found ";
    }
    return 0;
}