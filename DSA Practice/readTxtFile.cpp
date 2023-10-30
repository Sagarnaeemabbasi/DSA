#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct ReadFileClass
{
    static int *readFile(string a, int *x)
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
            if (ss.peek() == ',')
                ss.ignore();
        }
        inputFile.close();
        return ptr;
    }
};
int main()
{
    cout << "hello world";
    int *myArray;
    int sizeOfArray;
    int *sizeAddress = &sizeOfArray;
    ReadFileClass obj;
    myArray = obj.readFile("input.txt", sizeAddress);
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << *(myArray + i) << " ";
    }
    cout << endl;
    return 0;
}