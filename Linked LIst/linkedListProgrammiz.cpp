#include <iostream>
using namespace std;

// Node structure for linked list
struct node
{
    int index;         // Index of the node
    int data;          // Data stored in the node
    struct node *next; // Pointer to the next node
};

// Function to print the linked list
void printList(struct node *x)
{
    struct node *temp = x;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct node *x, int index)
{
    struct node *newNode = new node();
    cout << "Enter data to insert in new node: " << endl;
    cin >> newNode->data;
    newNode->index = index;
    newNode->next = NULL;

    struct node *temp = x;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete the last node of the linked list
void deleteAtEnd(struct node *x)
{
    struct node *temp = x;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

// Function to search for a specific number in the linked list
void searchList(struct node *x)
{
    cout << "What number do you want to search for?" << endl;
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

    searchFlag == 0 ? cout << "Not Found" << endl : cout << "Found" << endl;
}

// Function to delete the entire linked list and deallocate memory
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

int main()
{
    // Initialize the head node of the linked list
    struct node *head = new node();
    head->data = 1;

    // Insertion at the end of the linked list
    int input;
    cout << "Do you want to insert a node? If yes, press 1" << endl;
    cin >> input;
    int currentIndex = 0;
    while (input == 1)
    {
        insertAtEnd(head, currentIndex);
        currentIndex++;
        cout << "If you want to insert another node, press 1" << endl;
        cin >> input;
    }

    // Delete the last node if requested
    cout << "Do you want to delete the last node? If yes, press 2" << endl;
    cin >> input;
    if (input == 2)
    {
        deleteAtEnd(head);
    }

    // Print the entire linked list
    printList(head);

    // Search in the linked list if requested
    cout << "Do you want to search for a number? If yes, press 3" << endl;
    cin >> input;
    if (input == 3)
    {
        searchList(head);
    }

    // Deallocate memory for the linked list
    deleteList(head);

    return 0;
}
