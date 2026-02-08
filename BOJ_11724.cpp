#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[1001] = {
    0,
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    stack<int> dfs;
    dfs.push(1);
    int count = 1;
    while (!dfs.empty())
    {
        int cur = dfs.top();
        dfs.pop();
    }
    return 0;
}