#include <iostream>
using namespace std;

struct QueueNode
{
    int data;
    struct QueueNode *prev;
} *front = nullptr, *rear = nullptr;

void enqueue()
{
    struct QueueNode *temp = new QueueNode();
    cout << "Enter The Data: " << endl;
    cin >> temp->data;
    temp->prev = nullptr;
    if (rear == nullptr && front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->prev = temp;
        rear = temp;
    }
}

void dequeue()
{
    struct QueueNode *temp = front;
    if (temp != nullptr)
    {
        front = front->prev;
        cout << "Dequeued : " << temp->data << endl;
        delete temp;
    }
    else
    {
        cout << "Error : Empty Queue" << endl;
    }
}
void print()
{
    struct QueueNode *temp = front;
    while (temp != nullptr)
    {
        cout << temp->data << " | ";
        temp = temp->prev;
    }
    cout << endl;
}
int main()
{
    int input;
    do
    {

        cout << "Menu"
             << endl;
        cout << "1.Enque"
             << " | ";
        cout << "2.DeQueue"
             << " | ";
        cout << "3.Print"
             << " | ";
        cout << "4.Exit" << endl;
        cout << "Enter Your Choice : " << endl;
        cin >> input;
        if (input == 1)
        {
            enqueue();
        }
        else if (input == 2)
        {
            dequeue();
        }
        else if (input == 3)
        {
            print();
        }
        else if (input == 4)
        {
        }
        else
        {
            cout << "Invalid Input" << endl;
        }

    } while (input != 4);
    return 0;
}