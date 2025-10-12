#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 16;
int T[MAX_N + 1];
int P[MAX_N + 1];
int DP[MAX_N + 2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; --i)
    {

        int next_day = i + T[i];

        if (next_day <= N + 1)
        {
            int profit_if_do = P[i] + DP[next_day];
            int profit_if_skip = DP[i + 1];
            DP[i] = max(profit_if_do, profit_if_skip);
        }
        else
        {
            DP[i] = DP[i + 1];
        }
    }
    cout << DP[1] << '\n';

    return 0;
}