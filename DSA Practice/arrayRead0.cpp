#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream in1;
    in1.open("array.txt");
    int size;
    char n1;
    in1 >> size;
    cout << size << endl;
    char arr[size];
    for (int i = 0; i < (17); i++)
    {
        in1.get(n1);
        if (n1 != ',')
        {
            arr[i] = n1;
            cout << n1;
        }
        // in1 >> arr[i];
    }

    for (int i = 0; i < 17; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << (sizeof(arr) / sizeof(int));
    return 0;
}