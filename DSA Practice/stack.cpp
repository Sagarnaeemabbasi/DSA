#include <iostream>
using namespace std;

struct node
{
    int index;
    int data;
    struct node *prev;
} *top = NULL;

void printList(struct node *x)
{
    struct node *temp = x;
    while (temp != NULL)
    {
        cout << "[" << temp->index << "] " << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

void push(struct node *&top, int index)
{
    struct node *newNode = new node();
    cout << "Enter data to insert in new node: ";
    cin >> newNode->data;
    newNode->index = index;
    newNode->prev = top;
    top = newNode;
}

void pop(struct node *top)
{
    struct node *temp = top;
    top = top->prev;
    cout << "The Pop deleted " << top->data;
    // free(temp);
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
        temp = temp->prev;
    }

    searchFlag == 0 ? cout << "Not Found" << endl : cout << "Found at index: " << temp->index << endl;
}

void deleteList(struct node *x)
{
    struct node *current = x;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->prev;
        delete temp;
    }
}
void deleteANode()
{
    int searchFlag = 0;
    int deleteIndex;
    cout << "Enter the element you want to delete: " << endl;
    cin >> deleteIndex;
    struct node *curr = top;
    if (deleteIndex == top->index)
    {
        top = top->prev;
        free(curr);
        searchFlag = 1;
    }
    else
    {
        struct node *prev = top;
        curr = top->prev;
        while (curr != NULL)
        {
            if (curr->index == deleteIndex)
            {
                prev->prev = curr->prev;
                free(curr);
                searchFlag = 1;
                break;
            }
            else
            {
                prev = curr;
                curr = curr->prev;
            }
        }
        if (searchFlag == 0)
        {
            cout << "Element you are trying to delete is not present" << endl;
        }
    }
}

// ... (struct definition and function prototypes)

int main()
{
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int currentIndex = 1;
            do
            {
                push(top, currentIndex);
                currentIndex++;
                cout << "Do you want to insert another node? (1 for yes, 0 for no): ";
                cin >> choice;
            } while (choice == 1);
        }
        else if (choice == 2)
        {
            pop(top);
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    // Deallocate memory for the linked list
    deleteList(top);

    return 0;
}
