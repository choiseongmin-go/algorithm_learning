#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    vector<char> o;
    stack<int> s;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
        if (v[i] < s.top())
        {
            cout << "NO";
            return 0;
        }
        else if (v[i] == s.top())
        {
            o.push_back('-');
            s.pop();
        }
        else
        {
            for (int j = max + 1; j <= v[i]; j++)
            {
                o.push_back('+');
                s.push(j);
            }
            o.push_back('-');
            s.pop();
        }
    }
    for (int i = 0; i < o.size(); i++)
    {
        cout << o[i] << '\n';
    }
    return 0;
}