#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int N, M;
char board[601][601];
bool visited[601][601];

int BFS(int start_r, int start_c)
{
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    int person_count = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int r = cur.first;
        int c = cur.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;
            if (board[nr][nc] != 'X' && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                if (board[nr][nc] == 'P')
                    person_count++;
                q.push({nr, nc});
            }
        }
    }

    return person_count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int start_r, start_c;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'I')
            {
                start_r = i;
                start_c = j;
            }
        }
    }

    int result = BFS(start_r, start_c);

    if (result == 0)
        cout << "TT";
    else
        cout << result;

    return 0;
}