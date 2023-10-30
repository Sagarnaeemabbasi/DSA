#include <iostream>
using namespace std;
struct doubleLinkedList
{
    int marks, id;
    struct doubleLinkedList *next;
    struct doubleLinkedList *prev;
} *start = NULL;

void insert()
{
    if (start == NULL)
    {
        struct doubleLinkedList *temp = (struct doubleLinkedList *)malloc(sizeof(struct doubleLinkedList));
        temp->next = NULL;
        temp->prev = NULL;
        cout << "Enter marks: " << endl;
        cin >> temp->marks;
        cout << "Enter id: " << endl;
        cin >> temp->id;
        start = temp;
    }
    else
    {
        struct doubleLinkedList *curr = start;
        struct doubleLinkedList *temp = (struct doubleLinkedList *)malloc(sizeof(struct doubleLinkedList));
        temp->next = NULL;
        temp->prev = NULL;
        cout << "Enter marks: " << endl;
        cin >> temp->marks;
        cout << "Enter id: " << endl;
        cin >> temp->id;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}
void print()
{
    struct doubleLinkedList *curr = start;
    while (curr != NULL)
    {
        cout << "ID: " << curr->id << " | Marks: " << curr->marks << endl;
        curr = curr->next;
    }
}
void deleteNode()
{
    int deleteId;
    cout << "Enter the ID of element to delete: " << endl;
    cin >> deleteId;
    int searchFlag = 0;
    struct doubleLinkedList *curr = start;
    if (deleteId == start->id)
    {
        start = start->next;
        free(curr);
        searchFlag = 1;
    }
    else
    {

        curr = start->next;
        while (curr != NULL)
        {
            if (deleteId == curr->id)
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
                searchFlag = 1;
                break;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    if (searchFlag == 0)
    {
        cout << "Not Present in List" << endl;
    }
}
void deleteAtEnd()
{
    if (start == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    struct doubleLinkedList *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp == start)
    {
        // Only one node in the list
        delete start;
        start = NULL;
    }
    else
    {
        temp->prev->next = NULL; // Update previous node's 'next'
        delete temp;
    }
}

void search()
{
    int toSearchId;
    int searchFlag = 0;
    cout << "Enter the ID of element you want to search: " << endl;
    cin >> toSearchId;
    struct doubleLinkedList *curr = start;
    while (curr != NULL)
    {
        if (curr->id == toSearchId)
        {
            searchFlag = 1;

            break;
        }
        curr = curr->next;
    }
    if (searchFlag == 0)
    {
        cout << "Element not present in list" << endl;
    }
    else
    {
        cout << "found |Marks are: " << curr->marks << endl;
    }
}
void printMenu()
{
    cout << "Menu:\n";
    cout << "1. Insert a node\n";
    cout << "2. Delete a node\n";
    cout << "3. Search for a node\n";
    cout << "4. Print the linked list\n";
    cout << "5.See the Menu again.\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    int input;
    cout << "For Menu Press 5 To Exit Press 6\n";
    cin >> input;
    if (input == 5)
    {
        printMenu();
    }
    cin >> input;
    while (input != 6)
    {
        if (input == 1)
        {
            while (input == 1)
            {
                insert();
                cout << "Do you want to enter a node if yes press 1" << endl;
                cin >> input;
            }
        }
        else if (input == 4)
        {
            print();
        }
        else if (input == 2)
        {
            deleteAtEnd();
        }
        else if (input == 3)
        {
            search();
        }
        else if (input == 6)
        {
            break;
        }
        else if (input == 5)
        {
            printMenu();
        }
        else
        {
            cout << "Invalid Choice.." << endl;
        }
        cout << "For Menu Press 5 To Exit Press 6\n";
        cin >> input;
    }
    return 0;
}