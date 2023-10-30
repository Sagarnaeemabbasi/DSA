#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int *readFile(string a, int *x)
{
    ifstream inputFile(a);
    int size;
    inputFile >> size;
    *x = size;
    inputFile.ignore(); // Consume the newline character left in the stream
    string valuesLine;
    getline(inputFile, valuesLine);
    stringstream ss(valuesLine);
    int value;
    int *ptr = (int *)malloc(size * sizeof(int));
    int i = 0;
    while (ss >> value)
    {
        *(ptr + i) = value;
        i++;
        cout << value << endl;
        if (ss.peek() == ',')
            ss.ignore();
    }
    inputFile.close();
    return ptr;
}
int main()
{
    int *myArray;
    int sizeOfArray;
    int *sizeAddress = &sizeOfArray;
    myArray = readFile("TestCase_01.txt", sizeAddress); // readFile returns the pointer to the list read from txt file
    int arr[sizeOfArray];
    for (int i = 0; i < sizeOfArray; i++)
    {
        arr[i] = *(myArray + i);
    }
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] myArray;

    return 0;
}
