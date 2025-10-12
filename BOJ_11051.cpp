#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 10007;
const int MAX_N = 1001;
int dp[MAX_N][MAX_N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    if (K == 0 || K == N)
    {
        cout << 1 << "\n";
        return 0;
    }
    if (K < 0 || K > N)
    {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
    }
    cout << dp[N][K] << "\n";

    return 0;
}