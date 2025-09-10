#include <iostream>
using namespace std;

int num[100002];
int sum[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
        sum[i] += sum[i - 1] + num[i];
    }
    for (int i = 2; i <= N; i++)
    {
        result += num[i] * sum[i - 1];
    }
    cout << result << endl;
    return 0;
}