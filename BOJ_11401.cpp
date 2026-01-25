#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll num = 1000000007;

ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % num;
        a = (a * a) % num;
        b /= 2;
    }
    return res;
}

ll f(ll a)
{
    ll result = 1;
    for (ll i = 2; i <= a; i++)
    {
        result = (result * i) % num;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N, K;
    cin >> N >> K;

    ll a = f(N);
    ll b = (f(K) * f(N - K)) % num;

    ll answer = (a * power(b, num - 2)) % num;

    cout << answer;
    return 0;
}