#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_vertices, num_edges, start_node;
vector<int> adj_list[100001];
int visit_order[100001];
int visit_count = 0;

void run_dfs(int current_node)
{
    visit_order[current_node] = ++visit_count;

    for (int next_node : adj_list[current_node])
    {
        if (visit_order[next_node] == 0)
            run_dfs(next_node);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_vertices >> num_edges >> start_node;

    for (int i = 0; i < num_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 1; i <= num_vertices; i++)
    {
        sort(adj_list[i].begin(), adj_list[i].end(), [](int a, int b)
             { return a > b; });
    }

    run_dfs(start_node);

    for (int i = 1; i <= num_vertices; i++)
    {
        cout << visit_order[i] << '\n';
    }

    return 0;
}