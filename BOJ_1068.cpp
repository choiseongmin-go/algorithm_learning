#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[51];
bool visited[51];
int answer = 0;
int del;

void dfs(int cur)
{
    if (cur == del)
        return;
    visited[cur] = true;
    int childCount = 0;

    for (auto next : tree[cur])
    {
        if (visited[next])
            continue;

        childCount++;
        dfs(next);
    }

    if (childCount == 0)
        answer++;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int tem;
    for (int i = 1; i < N; i++)
    {
        cin >> tem;
        if (tem == -1)
        {
            cin >> tem;
        }
        tree[tem].push_back(i);
        tree[i].push_back(tem);
    }
    cin >> del;
    for (int i = 0; i < tree[del].size(); i++)
    {
        tem = tree[del].back();
        for (int j = 0; j < N; j++)
        {
            if (j == del)
            {
                continue;
            }
            tree[j].erase(remove(tree[j].begin(), tree[j].end(), del), tree[j].end());
        }
        tree[del].pop_back();
    }
    dfs(0);
    cout << answer;

    return 0;
}