#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> U;
int cur = 0;
vector<bool> visited(N, false);
int answer = 0;

void dfs(int n, vector<int> &u, int d)
{
    d += u[cur];
    visited[cur] = true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int trash;
    int Default = 500;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> trash;
        U.push_back(trash - K);
    }
    dfs(N, U, Default);
    return 0;
}