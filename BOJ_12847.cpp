#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<ll> T;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        T.push_back(x);
    }
    ll money = 0;
    ll max_m = 0;
    ll left = 0;
    ll right = m - 1;
    for (int i = left; i <= right; i++)
    {
        max_m += T[i];
    }
    right++;
    money = max_m;
    while (right <= n - 1)
    {
        money -= T[left];
        left++;
        money += T[right];
        if (money > max_m)
        {
            max_m = money;
        }
        right++;
    }
    cout << max_m;
    return 0;
}
