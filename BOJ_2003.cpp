#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N_size;
    ll M;
    vector<int> N;
    cin >> N_size >> M;
    int x;
    for (int i = 0; i < N_size; i++)
    {
        cin >> x;
        N.push_back(x);
    }
    int num = 0;
    int left = 0;
    int right = 0;
    ll sum = 0;
    while (true)
    {
        if (sum >= M)
        {
            if (sum == M)
            {
                num++;
            }
            sum -= N[left];
            left++;
        }
        else
        {
            if (right == N_size)
            {
                break;
            }
            sum += N[right];
            right++;
        }
    }
    cout << num;
}