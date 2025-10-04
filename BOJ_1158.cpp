#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    vector<int> answer;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
    int x;
    while (1)
    {
        if (q.empty() == 1)
        {
            break;
        }
        for (int i = 0; i < K - 1; i++)
        {
            x = q.front();
            q.pop();
            q.push(x);
        }
        answer.push_back(q.front());
        q.pop();
    }
    cout << '<';
    for (int i = 0; i < answer.size() - 1; i++)
    {
        cout << answer[i] << ", ";
    }
    cout << answer[answer.size() - 1] << '>';
    return 0;
}