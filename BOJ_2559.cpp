#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N, K;
    cin >> N >> K;
    ll tem;
    vector<ll> sum;
    sum.push_back(0);
    ll x = 0;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> tem;
        x = sum[i - 1] + tem;
        sum.push_back(x);
    }
    ll max = -10000000;
    ll y;
    for (int i = 1; i <= N - K + 1; i++)
    {
        y = sum[i + K - 1] - sum[i - 1];
        if (y > max)
        {
            max = y;
        }
    }
    cout << max;
    return 0;
}