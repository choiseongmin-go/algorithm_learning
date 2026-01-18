#include <iostream>
#include <vector>
using namespace std;

const int MOD = 10007;
const int MAX_N = 1001;
int dp[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    if (N == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; ++i)
    {

        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[N] << "\n";

    return 0;
}