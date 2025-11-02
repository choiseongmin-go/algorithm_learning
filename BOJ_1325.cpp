#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_N = 10001;

vector<int> adj_list[MAX_N];

int hack_counts[MAX_N] = {
    0,
};

int N, M;

int bfs(int start_node)
{
    queue<int> q;
    q.push(start_node);

    bool visited[MAX_N] = {
        false,
    };
    visited[start_node] = true;

    int count = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        count++;

        for (int v : adj_list[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return count;
}

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M))
        return;

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        adj_list[B].push_back(A);
    }

    int max_count = 0;

    for (int i = 1; i <= N; ++i)
    {
        hack_counts[i] = bfs(i);
        max_count = max(max_count, hack_counts[i]);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (hack_counts[i] == max_count)
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}