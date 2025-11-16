#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int x_move[4] = {-1, 1, 0, 0};
int y_move[4] = {0, 0, -1, 1};

int N, M;
int map[501][501];
int visited[501][501];
queue<pair<int, int>> q;

int BFS(int start_r, int start_c)
{
    q.push({start_r, start_c});
    visited[start_r][start_c] = 1;
    int area = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        area++;

        int cur_r = cur.first;
        int cur_c = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int next_r = cur_r + x_move[i];
            int next_c = cur_c + y_move[i];

            if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M)
            {
                continue;
            }

            if (map[next_r][next_c] == 1 && visited[next_r][next_c] == 0)
            {
                visited[next_r][next_c] = 1;
                q.push({next_r, next_c});
            }
        }
    }

    return area;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int picture_count = 0;
    int max_area = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == 0)
            {
                picture_count++;
                int current_area = BFS(i, j);
                max_area = max(max_area, current_area);
            }
        }
    }

    cout << picture_count << "\n"
         << max_area;

    return 0;
}