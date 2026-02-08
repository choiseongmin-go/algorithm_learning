#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sequence;

void dfs(int k, int start_num)
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

    for (int i = start_num; i <= N; ++i)
    {
        sequence[k] = i;
        dfs(k + 1, i);
    }
}

void solve()
{
    if (!(cin >> N >> M))
        return;

    sequence.resize(M);

    dfs(0, 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}