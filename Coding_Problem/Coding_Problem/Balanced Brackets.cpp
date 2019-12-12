#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Complete the isBalanced function below.
char changer(char origin)
{
    if (origin == ')')
        return '(';
    if (origin == '}')
        return '{';
    if (origin == ']')
        return '[';
    return '0';
}

string isBalanced(string s) {
    stack<char> ch;

    while (!s.empty())
    {
        char sTmp = *(s.end() - 1);
        if (ch.empty())
        {
            ch.push(changer(sTmp));
            s.pop_back();
            continue;
        }

        if (sTmp == ch.top())
            ch.pop();
        else
        {
            char c = changer(sTmp);
            if (c == '0')
                return "NO";
            ch.push(c);
        }
        s.pop_back();
    }

    if (ch.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}
