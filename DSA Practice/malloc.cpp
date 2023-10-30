#include <iostream>
using namespace std;
int *arr(int size)
{
    int value;
    int *ptr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        *(ptr + i) = value;
    }
    return ptr;
}
int main()
{

    int size;
    cin >> size;
    int *arr1 = arr(size);
    for (int i = 0; i < size; i++)
    {

        cout << *(arr1 + i);
    }
    return 0;
}