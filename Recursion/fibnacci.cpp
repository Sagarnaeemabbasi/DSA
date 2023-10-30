#include <iostream>;
using namespace std;
int fibnacci(int n)
{
    int prev = 1;
    int curr = 1;
    if (n == 0)
    {
        return 0;
    }

    else if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i < = n; i++)
        {
            curr = curr + prev;
            prev = curr;
        }
        return prev;
    }
}
int main()
{
    cout << fibnacci(5);
}