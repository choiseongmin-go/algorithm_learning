#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int x_move[4] = {1, 0, -1, 0};
int y_move[4] = {0, 1, 0, -1};

int N, M;
string map[101];
int dist[101][101];
queue<pair<int, int>> q;

int BFS()
{

    int start_x = 0;
    int start_y = 0;
    dist[start_x][start_y] = 1;
    q.push({start_x, start_y});

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int cur_x = cur.first;
        int cur_y = cur.second;
        if (cur_x == N - 1 && cur_y == M - 1)
        {
            return dist[cur_x][cur_y];
        }
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + x_move[i];
            int next_y = cur_y + y_move[i];
            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
            {
                continue;
            }
            if (map[next_x][next_y] == '1' && dist[next_x][next_y] == 0)
            {
                dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
                q.push({next_x, next_y});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }
    cout << BFS() << "\n";
    return 0;
}