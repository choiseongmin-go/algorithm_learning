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
    vector<ll> v;
    int N;
    cin >> N;
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int max_num = 0;
    int left = 0;
    int right = 0;
    while (left < N)
    {
        while (right < N && v[right] - v[left] <= 4)
        {
            right++;
        }
        max_num = max(max_num, right - left);
        left++;
    }
    cout << 5 - max_num;
    return 0;
}