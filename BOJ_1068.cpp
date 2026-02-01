#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[51];
int N, del, root, answer = 0;

void dfs(int cur)
{
    if (cur == del)
        return;

    int childCount = 0;
    for (int next : tree[cur])
    {
        if (next == del)
            continue;

        childCount++;
        dfs(next);
    }

    if (childCount == 0)
    {
        answer++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;
        if (parent == -1)
        {
            root = i;
        }
        else
        {
            tree[parent].push_back(i);
        }
    }

    cin >> del;

    if (del == root)
    {
        cout << 0 << "\n";
    }
    else
    {
        dfs(root);
        cout << answer << "\n";
    }

    return 0;
}