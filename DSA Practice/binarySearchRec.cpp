#include <iostream>
#include <array>
using namespace std;
int binarySearch(int array[], int x, int left, int right, int mid)
{
    if (left > right)
    {
        return -1;
    }
    mid = (left + right) / 2;
    if (array[mid] == x)
    {
        return mid;
    }
    else if (x < array[mid])
    {
        return binarySearch(array, x, left, mid - 1, 0);
    }
    else
    {
        return binarySearch(array, x, mid + 1, right, 0);
    }
}

int main()
{
    int array[5] = {1, 2, 3, 4, 5};
    int x = 4;
    int result = binarySearch(array, 4, 0, 4, 0);

    return 0;
}