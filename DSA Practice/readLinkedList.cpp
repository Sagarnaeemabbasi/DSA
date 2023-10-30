#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
string *readFile(string a, int *size_of_arr)
{
    cout << "now" << endl;
    int size;
    int value;
    string *ptr;

    ifstream inputFile(a);

    // reading the size of array

    inputFile >> size;
    *size_of_arr = size;
    inputFile.ignore(); // Consume the newline character left in the stream

    // reading the array

    string valuesLine;
    getline(inputFile, valuesLine);
    stringstream ss(valuesLine);
    ptr = (string *)malloc(size * sizeof(int));
    int i = 0;
    while (ss >> value)
    {
        cout << "now" << endl;
        *(ptr + i) = value;
        i++;
        if (ss.peek() == ' ' || ss.peek() == '\n')
            ss.ignore();
        cout << "now" << endl;
    }
    inputFile.close();
    return ptr;
}
int main()
{
    cout << "hello world";
    string *myArray;
    int sizeOfArray;
    int *sizeAddress = &sizeOfArray;
    myArray = readFile("ll.txt", sizeAddress);
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << *(myArray + i) << " ";
    }
    cout << endl;
    return 0;
}