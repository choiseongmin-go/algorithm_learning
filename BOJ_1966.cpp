#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> answer;
    int test_case;
    cin >> test_case;
    for (int j = 0; j < test_case; j++)
    {
        int N, M;
        cin >> N >> M;
        queue<int> q;
        queue<bool> b;
        int level[11];
        for (int i = 0; i < 11; i++)
        {
            level[i] = 0;
        }
        int max = 0;
        int x;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            q.push(x);
            level[x]++;
            if (max < x)
            {
                max = x;
            }
            if (i == M)
            {
                b.push(true);
            }
            else
            {
                b.push(false);
            }
        }
        int num = 1;
        int y;
        bool z;
        while (1)
        {
            if (level[max] == 0)
            {
                for (int a = 9; a >= 1; a--)
                {
                    if (level[a] != 0)
                    {
                        max = a;
                        break;
                    }
                }
            }
            if (max == q.front())
            {
                level[q.front()]--;
                q.pop();
                if (b.front() == true)
                {
                    answer.push_back(num);
                    break;
                }
                b.pop();
                num++;
            }
            else
            {
                y = q.front();
                q.pop();
                q.push(y);
                z = b.front();
                b.pop();
                b.push(z);
            }
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }
    return 0;
}