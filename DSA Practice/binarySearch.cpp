#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 9> arr{0, 1, 2, 3, 4, 5, 6, 7, 8};
    int toSearch = 2;
    int searchFlag = 0;
    int arrayLength = arr.size();
    int left = 0;
    int right = arrayLength;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == toSearch)
        {
            searchFlag = 1;
            cout << "found element at : " << mid << endl;
            break;
        }
        else if (toSearch < arr[mid])
        {
            right = mid - 1;
            cout << "element is to the right of " << arr[mid] << endl;
        }
        else
        {
            left = mid + 1;
            cout << "element is to the left of " << arr[mid] << endl;
        }
    }
    if (searchFlag == 0)
    {
        cout << "element not found ";
    }
    return 0;
}