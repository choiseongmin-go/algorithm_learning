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
    vector<bool> num(1000001, true);
    num[0] = false;
    num[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (num[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                num[j] = false;
            }
        }
    }
    for (int i = M; i <= N; i++)
    {
        if (num[i] == true)
        {
            cout << i << '\n';
        }
    }
    return 0;
}