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
    ll N, X;
    cin >> N >> X;
    vector<ll> V;
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        V.push_back(x);
    }
    ll left = 0;
    ll right = X - 1;
    ll sum = 0;
    ll max = 0;
    for (int i = left; i <= right; i++)
    {
        max += V[i];
    }
    sum = max;
    right++;
    ll count = 1;
    while (right <= N - 1)
    {
        sum -= V[left];
        left++;
        sum += V[right];
        right++;
        if (sum > max)
        {
            max = sum;
            count = 1;
        }
        else if (sum == max)
        {
            count++;
        }
    }
    if (max == 0)
    {
        cout << "SAD";
    }
    else
    {
        cout << max << "\n"
             << count;
    }
    return 0;
}