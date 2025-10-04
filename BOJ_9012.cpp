#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    vector<bool> b;
    string str[100];
    for (int i = 0; i < T; i++)
    {
        cin >> str[i];
        stack<char> s;
        for (int j = 0; j < str[i].length(); j++)
        {
            if (str[i][j] == '(')
            {
                s.push('(');
            }
            else
            {
                if (s.empty() == 0 && s.top() == '(')
                {
                    s.pop();
                }
                else
                {
                    s.push(')');
                }
            }
        }
        if (s.empty() == 1)
        {
            b.push_back(true);
        }
        else
        {
            b.push_back(false);
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == true)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    return 0;
}