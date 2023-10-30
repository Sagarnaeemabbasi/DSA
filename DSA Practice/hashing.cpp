#include <iostream>
using namespace std;
// int size = 50;
int arr[50];
void insert()
{
    int input;
    cout << "Enter the number between 0 and 50 including the boundry" << endl;
    cin >> input;
    arr[input] = input;
}
void search()
{
    int input;
    cout << "Enter the number you want to search : " << endl;
    cin >> input;
    if (input <= 50 && input >= 0)
    {
        cout << "The number is : " << arr[input] << endl;
    }
    else
    {
        cout << "The number is not present in array" << endl;
    }
}
int main()
{
    for (int i = 0; i < 51; i++)
    {
        arr[i] = i;
    }
    search();
    search();
    search();
    search();
    search();
    search();
    search();
    search();
    search();
    search();
    search();
    search();
    search();
    return 0;
}