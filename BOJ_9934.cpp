#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K;
int a[1024];
vector<int> v[11];
void go(int s, int e, int d)
{
    if (s > e)
        return;
    int m = (s + e) / 2;
    v[d].push_back(a[m]);
    go(s, m - 1, d + 1);
    go(m + 1, e, d + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> K;
    int n = (int)pow(2, K) - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    go(0, n - 1, 0);
    for (int i = 0; i < K; i++)
    {
        for (int x : v[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}