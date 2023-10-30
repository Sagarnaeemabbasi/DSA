#include <iostream>
using namespace std;
#include <stack>
stack<char> stringStack;
int presidenceFind(char a)
{
    char temp1 = '^';
    char temp2 = '*';
    char temp3 = '/';
    char temp4 = '+';
    char temp5 = '-';
    if (a == temp1)
    {
        return 1;
    }
    else if (a == temp2 || a == temp3)
    {
        return 2;
    }
    else if (a == temp4 || a == temp5)
    {
        return 3;
    }
}
int main()
{
    string infixEq = "A^B-C*D";
    string postfixEq = "";
    string temp;
    int presidence;
    for (int i = 0; i < 7; i++)
    {
        char c = infixEq[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            cout << c << endl;
            postfixEq += c;
        }
        else if ((stringStack.size()) != 0)
        {
            while ((stringStack.size()) > 0)
                cout << "agaya " << endl;
            {
                if (presidenceFind(c) <= presidenceFind(stringStack.top()))
                {
                    cout << c << endl;
                    stringStack.push(c);
                    break;
                }
                postfixEq += stringStack.top();
                stringStack.pop();
            }
        }
        else
        {
            stringStack.push(c);
        }
    }
    for (int j = 0; j < (stringStack.size()); j++)
    {
        postfixEq += stringStack.top();
        stringStack.pop();
    }
    cout << postfixEq;
    return 0;
}