#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
} *start = NULL;

int main()
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    start = first;
    first->value = 13;
    first->next = second;
    second->value = 14;
    second->next = third;
    third->value = 15;
    third->next = NULL;
    struct Node *curr = start;
    while (curr != NULL)
    {
        cout << curr->value << endl;
        curr = curr->next;
    }
    return 0;
}