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
    vector<ll> sum;
    ll N_size, M_size;
    cin >> N_size >> M_size;
    int x;
    for (int i = 0; i < N_size; i++)
    {
        cin >> x;
        sum.push_back(x);
    }
    for (int i = 0; i < M_size; i++)
    {
        cin >> x;
        sum.push_back(x);
    }
    sort(sum.begin(), sum.end());
    for (int i = 0; i < N_size + M_size; i++)
    {
        cout << sum[i] << " ";
    }
    return 0;
}