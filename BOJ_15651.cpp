#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sequence;

void dfs(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << sequence[i] << (i == M - 1 ? "" : " ");
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        sequence[k] = i;
        dfs(k + 1);
    }
}

void solve()
{
    if (!(cin >> N >> M))
        return;

    sequence.resize(M);

    dfs(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}