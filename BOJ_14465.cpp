#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N, K, B;
    cin >> N >> K >> B;
    vector<bool> T(N + 1);
    for (int i = 0; i <= N; i++)
    {
        T[i] = true;
    }
    ll x;
    for (int i = 0; i < B; i++)
    {
        cin >> x;
        T[x] = false;
    }
    ll left = 1;
    ll right = K;
    ll min = 0;
    ll fix = 0;
    for (int i = left; i <= right; i++)
    {
        if (T[i] == false)
        {
            min++;
        }
    }
    right++;
    fix = min;
    while (right <= N)
    {
        if (T[left] == false)
        {
            fix--;
        }
        left++;
        if (T[right] == false)
        {
            fix++;
        }
        right++;
        if (fix < min)
        {
            min = fix;
        }
    }
    cout << min;
    return 0;
}