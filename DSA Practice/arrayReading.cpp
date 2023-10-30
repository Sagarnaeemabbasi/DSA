#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");

    // if (!inputFile.is_open())
    // {
    //     cerr << "Failed to open the input file." << endl;
    //     return 1;
    // }

    int size;
    inputFile >> size;
    inputFile.ignore(); // Consume the newline character left in the stream

    string valuesLine;
    getline(inputFile, valuesLine);
    stringstream ss(valuesLine);
    int value;
    // vector<int> values;
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

    // cout << "Size of array: " << size << endl;
    // cout << "Values read: ";
    // for (int val : values)
    // {
    //     cout << val << " ";
    // }
    // cout << endl;

    // if (size != values.size())
    // {
    //     cerr << "Mismatch in array size and number of values." << endl;
    //     return 1;
    // }

    int myArray[size];
    for (int i = 0; i < size; i++)
    {
        myArray[i] = *(ptr + i);
    }

    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}
