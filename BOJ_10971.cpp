#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000 * 10 + 1;

int N;
vector<vector<int>> W;
vector<bool> visited;
int min_cost = MAX;

void dfs(int current_city, int count, int current_cost)
{
    if (current_cost >= min_cost)
    {
        return;
    }

    if (count == N)
    {
        if (W[current_city][0] != 0)
        {
            min_cost = min(min_cost, current_cost + W[current_city][0]);
        }
        return;
    }

    for (int next_city = 0; next_city < N; ++next_city)
    {
        if (!visited[next_city] && W[current_city][next_city] != 0)
        {
            visited[next_city] = true;

            dfs(next_city, count + 1, current_cost + W[current_city][next_city]);

            visited[next_city] = false;
        }
    }
}

void solve()
{
    if (!(cin >> N))
        return;

    W.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> W[i][j];
        }
    }

    visited.resize(N, false);

    visited[0] = true;
    dfs(0, 1, 0);

    cout << min_cost << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}