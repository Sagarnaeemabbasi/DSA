#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    struct StackNode *next;
} *top = nullptr;

void push()
{
    struct StackNode *temp = new StackNode();
    cout << "Enter The Data :" << endl;
    cin >> temp->data;
    temp->next = top;
    top = temp;
}
void pop()
{
    struct StackNode *temp = top;
    if (top != nullptr)
    {
        top = top->next;
        cout << "Popped Value : " << temp->data << endl;
        delete temp;
    }
    else
    {
        cout << "Error : Stack Under Flow" << endl;
    }
}

void print()
{
    struct StackNode *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " | ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int input;
    do
    {

        cout << "Menu" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Print" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter Your Choice : " << endl;
        cin >> input;
        if (input == 1)
        {
            push();
        }
        else if (input == 2)
        {
            pop();
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