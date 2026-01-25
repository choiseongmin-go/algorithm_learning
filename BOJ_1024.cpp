#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N, L;
    cin >> N >> L;
    for (int i = L; i <= 100; i++)
    {
        ll a = N - i * (i - 1) / 2;
        if (a >= 0 && a % i == 0)
        {
            ll b = a / i;
            for (int j = 0; j < i; j++)
            {
                cout << a + j << ' ';
            }
            return 0;
        }
    }
    cout << -1;
    return 0;
}