#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> dp[41];

void pre_calculate_fibonacci_calls()
{
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for (int i = 2; i <= 40; ++i)
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre_calculate_fibonacci_calls();

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        cout << dp[N].first << " " << dp[N].second << "\n";
    }

    return 0;
}