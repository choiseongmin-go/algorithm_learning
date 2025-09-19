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
    int N;
    ll M;
    vector<ll> v;
    ll sum = 0;
    ll num = 0;
    cin >> N >> M;
    int left_point = 0;
    int right_point = N - 1;
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    while (left_point < right_point)
    {
        sum = v[left_point] + v[right_point];
        if (sum == M)
        {
            left_point++;
            right_point--;
            num++;
        }
        else if (sum > M)
        {
            right_point--;
        }
        else
        {
            left_point++;
        }
    }
    cout << num;
    return 0;
}