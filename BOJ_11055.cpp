#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> dp(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i] = A[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                if (dp[i] < dp[j] + A[i])
                {
                    dp[i] = dp[j] + A[i];
                }
            }
        }
    }
    int max_sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (max_sum < dp[i])
            max_sum = dp[i];
    }

    cout << max_sum;
    return 0;
}