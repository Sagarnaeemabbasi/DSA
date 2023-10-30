#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
    int seed = time(nullptr);
    srand(seed);
    int num1 = (rand() % (6 - 1 + 1)) + 1;
    int num2 = (rand() % (6 - 1 + 1)) + 1;
    cout << fixed << setprecision(10) << 12.457865 << endl;
    cout << left;
    cout << setw(10) << "Dice" << setw(10) << "Number" << endl
         << setw(10) << "First"
         << right << setw(10) << num1 << endl
         << left << setw(10)
         << "Second"
         << right << setw(10)
         << num2 << endl;
}