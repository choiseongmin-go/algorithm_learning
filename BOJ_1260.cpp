#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> Adj;
vector<bool> Visited;
vector<int> DFS_Path;
vector<int> BFS_Path;

int N, M, V;

void DFS(int curr)
{
    Visited[curr] = true;
    DFS_Path.push_back(curr);

    for (int next : Adj[curr])
    {
        if (!Visited[next])
        {
            DFS(next);
        }
    }
}

void BFS(int start)
{
    queue<int> Q;
    Q.push(start);
    Visited[start] = true;
    BFS_Path.push_back(start);

    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();

        for (int next : Adj[curr])
        {
            if (!Visited[next])
            {
                Visited[next] = true;
                Q.push(next);
                BFS_Path.push_back(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;
    Adj.resize(N + 1);
    Visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(Adj[i].begin(), Adj[i].end());
    }

    if (V >= 1 && V <= N)
    {
        DFS(V);
    }

    fill(Visited.begin(), Visited.end(), false);

    if (V >= 1 && V <= N)
    {
        BFS(V);
    }

    for (auto &node : DFS_Path)
        cout << node << " ";
    cout << "\n";

    for (auto &node : BFS_Path)
        cout << node << " ";
    cout << "\n";

    return 0;
}