#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<bool> num(10000001, true);
    num[0] = false;
    num[1] = false;
    for (int i = 2; i * i <= 10000001; i++)
    {
        if (num[i] == true)
        {
            for (int j = i * i; j <= 10000001; j += i)
            {
                num[j] = false;
            }
        }
    }
    int result;
    while (1)
    {
        string n;
        string n_rev;
        int len;
        n = to_string(N);
        len = n.length();
        for (int i = len - 1; i >= 0; i--)
        {
            n_rev.push_back(n[i]);
        }
        if (n == n_rev && num[N] == true)
        {
            result = N;
            break;
        }
        else
        {
            N++;
        }
    }
    cout << result;
    return 0;
}