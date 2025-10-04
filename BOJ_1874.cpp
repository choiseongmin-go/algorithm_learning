#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<int> s;
    vector<int> str;
    vector<char> out;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        str.push_back(x);
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.empty() == 0 && str[i] < s.top())
        {
            cout << "NO";
            return 0;
        }
        else if (s.empty() == 0 && str[i] == s.top())
        {
            out.push_back('-');
            s.pop();
        }
        else
        {
            for (int j = max + 1; j <= str[i]; j++)
            {
                out.push_back('+');
                s.push(j);
            }
            out.push_back('-');
            s.pop();
        }
        if (max < str[i])
        {
            max = str[i];
        }
    }
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << '\n';
    }
    return 0;
}