#include <iostream>
using namespace std;

struct node
{
    int index;
    int data;
    struct node *next;
} *start = NULL;

void printList(struct node *x)
{
    struct node *temp = x;
    while (temp != NULL)
    {
        cout << "[" << temp->index << "] " << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtEnd(struct node *&x, int index)
{
    struct node *newNode = new node();
    cout << "Enter data to insert in new node: ";
    cin >> newNode->data;
    newNode->index = index;
    newNode->next = NULL;
    if (x == NULL)
    {
        x = newNode;
    }
    else
    {
        struct node *temp = x;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtEnd(struct node *x)
{
    struct node *temp = x;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void searchList(struct node *x)
{
    cout << "Enter the number you want to search: ";
    int numberToSearch;
    cin >> numberToSearch;
    struct node *temp = x;
    int searchFlag = 0;
    while (temp != NULL)
    {
        if (temp->data == numberToSearch)
        {
            searchFlag = 1;
            break;
        }
        temp = temp->next;
    }

    searchFlag == 0 ? cout << "Not Found" << endl : cout << "Found at index: " << temp->index << endl;
}

void deleteList(struct node *x)
{
    struct node *current = x;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->next;
        delete temp;
    }
}
void deleteANode()
{
    int searchFlag = 0;
    int deleteIndex;
    cout << "Enter the element you want to delete: " << endl;
    cin >> deleteIndex;
    struct node *curr = start;
    if (deleteIndex == start->index)
    {
        start = start->next;
        free(curr);
        searchFlag = 1;
    }
    else
    {
        struct node *prev = start;
        curr = start->next;
        while (curr != NULL)
        {
            if (curr->index == deleteIndex)
            {
                prev->next = curr->next;
                free(curr);
                searchFlag = 1;
                break;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        if (searchFlag == 0)
        {
            cout << "Element you are trying to delete is not present" << endl;
        }
    }
}

int main()
{
    // struct node *start = new node();
    // start->data = 1;
    // start->index = 0;

    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete the last node\n";
        cout << "3. Search for a node\n";
        cout << "4. Print the linked list\n";
        cout << "5. Delete a node\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int currentIndex = 1;
            do
            {
                insertAtEnd(start, currentIndex);
                currentIndex++;
                cout << "Do you want to insert another node? (1 for yes, 0 for no): ";
                cin >> choice;
            } while (choice == 1);
        }
        else if (choice == 2)
        {
            deleteAtEnd(start);
        }
        else if (choice == 3)
        {
            searchList(start);
        }
        else if (choice == 4)
        {
            printList(start);
        }
        else if (choice == 5)
        {
            deleteANode();
        }
        else if (choice == 6)
        {
            // Exit the loop and end the program
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    // Deallocate memory for the linked list
    deleteList(start);

    return 0;
}
