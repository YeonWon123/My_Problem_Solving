#include<iostream>
#include<stack>
#include<string>
using namespace std;
int len;
bool Checking(string str);
int main(void)
{
    int N;
    cin >> N;
    int k = 1;
    while (N--)
    {
        cin.ignore();
        cin >> len;
        cin.ignore();
        for (int i = 0; i < len; i++)
        {
            string str;
            getline(cin, str);
            cout << str << endl;

            if (Checking(str))
            {
                cout << "#" << k << " " << 1 << "\n";
            }
            else
                cout << "#" << k << " " << 0 << "\n";

            k++;
        }
    }
}
bool Checking(string str)
{
    stack<char> St;
    for (int i = 0; i < len; i++)
    {
        char S = str[i];

        if (S == '(')
        {
            St.push(S);
        }
        else if (S == '[')
        {
            St.push(S);
        }
        else if (S == '<')
        {
            St.push(S);
        }
        else if (S == '{')
        {
            St.push(S);
        }

        else if (S == ']')
        {
            if (!St.empty() && St.top() == '[')
            {
                St.pop();
            }
            else
                return false;
        }
        else if (S == ')')
        {
            if (!St.empty() && St.top() == '(')
            {
                St.pop();
            }
            else
                return false;
        }
        else if (S == '>')
        {
            if (!St.empty() && St.top() == '<')
            {
                St.pop();
            }
            else
                return false;
        }
        else if (S == '}')
        {
            if (!St.empty() && St.top() == '{')
            {
                St.pop();
            }
            else
                return false;
        }


    }
    return St.empty();
}