#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll M, N;
    cin >> M >> N;
    vector<bool> num(1000002, 0);
    num[1] = 1;
    for (int i = 2; i * i <= N; i++)
    {
        for (int j = 2; i * j <= N; j++)
        {
            num[i * j] = 1;
        }
    }
    for (int i = M; i <= N; i++)
    {
        if (num[i] == 0)
        {
            cout << i << '\n';
        }
    }
    return 0;
}