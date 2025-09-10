#include <iostream>
using namespace std;

long long num[100002];
long long sum[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    long long result = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
        sum[i] += sum[i - 1] + num[i];
    }
    for (int i = 2; i <= N; i++)
    {
        result += num[i] * sum[i - 1];
    }
    cout << result << '\n';
    return 0;
}