#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BS(const int N[], int size, int num)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (N[mid] == num)
        {
            return 1;
        }
        else if (N[mid] < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> n;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        n.push_back(x);
    }
    sort(n.begin(), n.end());
    vector<int> A;
    int M;
    cin >> M;
    vector<int> answer;
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        answer.push_back(BS(n.data(), N, x));
    }
    for (int i = 0; i < M; i++)
    {
        cout << answer[i] << '\n';
    }
    return 0;
}