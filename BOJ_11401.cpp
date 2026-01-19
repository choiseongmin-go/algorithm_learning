#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll num = 1000000007;

ll f(ll a)
{
    ll result = 1;
    while (a != 1)
    {
        result = (result * a) % num;
        a--;
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
    ll a, b;
    a = f(N);
    b = (f(K) * (f(N - K)));
    b = k;
    ll answer = (f(N) / (f(K) * (f(N - K)))) % num;
    cout << answer;
    return 0;
}