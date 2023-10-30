#include <iostream>
using namespace std;
struct HashNode
{
    int val = -1;
    struct HashNode *next = nullptr;
};
int hashFunc(int val, int size)
{
    return (val % size);
}
void insert(int val, int size, HashNode arr[])
{
    int key = hashFunc(val, size);
    if (arr[key].val == -1)
    {
        arr[key].val = val;
        return;
    }
    struct HashNode *curr = arr[key].next;
    struct HashNode *temp = new HashNode();
    temp->val = val;
    temp->next = nullptr;
    if (arr[key].next == nullptr)
    {
        arr[key].next = temp;
        return;
    }
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = temp;
}
void print(HashNode arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i << " : ";
        struct HashNode *curr = &arr[i];

        while (curr != nullptr)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}
int search(HashNode arr[], int size, int value, HashNode *nodeNo, int *point)
{
    int key = hashFunc(value, size);
    int count = 1;
    if (arr[key].val == value)
    {
        return key;
    }
    struct HashNode *curr = &arr[key];
    while (curr != nullptr)
    {
        if (curr->val == value)
        {
            nodeNo = curr;
            point = &count;
            return key;
        }
        curr = curr->next;
        count++;
    }
    return -1;
}

int main()
{
    int size = 4;
    int val;
    int *point = nullptr;
    HashNode *nodeNo = nullptr;
    struct HashNode hashTable[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value to enter : ";
        cin >> val;
        cout << endl;
        insert(val, size, hashTable);
    }
    cout << "Enter the value to search : " << endl;
    cin >> val;
    int searchedIndex = search(hashTable, size, val, nodeNo, point);
    if (searchedIndex != -1)
    {
        if (nodeNo == nullptr)
        {
            cout << searchedIndex << " : " << hashTable[searchedIndex].val << endl;
        }
        else
        {
            struct HashNode *curr = &hashTable[searchedIndex];
            for (int i = 0; i < *point; i++)
            {
                curr = curr->next;
            }
            cout << searchedIndex << " : " << curr->val << endl;
        }
    }
    else
    {
        cout << "Not Found In The List" << endl;
    }
    print(hashTable, size);
    return 0;
}