#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int L, C;
vector<char> P;
string A;

void backtrack(int c, int v, int i, vector<char> &p, string a)
{
    a.push_back(P[i]);
    if (p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u')
        v++;
    else
        c++;
    if (a.length() == L)
    {
        if (v >= 1 && c >= 2)
        {
            cout << a << endl;
            return;
        }
    }
    for (int j = i + 1; j < C; j++)
        backtrack(c, v, j, p, a);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char trash;
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> trash;
        P.push_back(trash);
    }
    sort(P.begin(), P.end());
    for (int i = 0; i <= C - L; i++)
        backtrack(0, 0, i, P, "");
    return 0;
}