#include <iostream>
using namespace std;

typedef long long ll;
ll section_sum[100002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M, num;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        section_sum[i] = section_sum[i - 1] + num;
    }
    cin >> M;
    int a, b;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        cout << section_sum[b] - section_sum[a - 1] << '\n';
    }
    return 0;
}