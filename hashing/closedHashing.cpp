#include <iostream>
using namespace std;
int hashFunc(int val, int size)
{
    return (val % size);
}
void linearProbing(int size, int key, int arr[], int val)
{
    int newKey;
    for (int i = 1; i < size; i++)
    {
        newKey = (key + i) % 10;
        if (arr[newKey] == -1)
        {
            arr[newKey] = val;
            return;
        }
    }
}
void quadraticProbing(int size, int key, int arr[], int val)
{
    int newKey;
    for (int i = 1; i < size; i++)
    {
        newKey = (key + (i * i)) % 10;
        if (arr[newKey] == -1)
        {
            arr[newKey] = val;
            return;
        }
        else
        {
            linearProbing(size, key, arr, val);
        }
    }
}
void insert(int arr[], int size, int val)
{
    int key = hashFunc(val, size);
    if (arr[key] == -1)
    {
        arr[key] = val;
    }
    else
    {
        linearProbing(size, key, arr, val);
    }
}
int search(int val, int arr[], int size)
{
    int key = hashFunc(val, size);
    if (arr[key] == val)
    {
        return key;
    }
    else
    {
        int newKey;
        for (int i = 0; i < size; i++)
        {
            newKey = (key + i) % 10;
            if (arr[newKey] == val)
            {
                return newKey;
            }
        }
        return -1;
    }
}
int main()
{
    int size;
    int val;
    int key;
    int *arrPointer;
    cout << "Enter the size of Hash Table" << endl;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element: " << endl;
        cin >> val;
        insert(arr, size, val);
    }
    for (int i = 0; i < size; i++)
    {
        cout << i << " : " << arr[i] << endl;
    }
    cout << "Enter the element to search: " << endl;
    cin >> val;
    int searchedIndex = search(val, arr, size);
    if (searchedIndex == -1)
    {
        cout << "Element Not Found !!" << endl;
    }
    else
    {
        cout << searchedIndex << " : " << arr[searchedIndex] << endl;
    }
    return 0;
}