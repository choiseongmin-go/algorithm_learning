#include <iostream>
using namespace std;
typedef long long ll;
ll coor[1000002] = {0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N, K;
    cin >> N >> K;
    ll g, x;
    ll count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> g >> x;
        if (x <= 1000001)
        {
            coor[x] += g;
        }
    } // coor x에 g의 얼음 양이 있음 나머지는 0
    ll max = 0;
    int left = -K;
    int right = K; // 처음에 0에 자리를 잡았다고 가정
    if (K <= 1000001)
    {
        for (int i = 0; i <= K; i++)
        {
            if (coor[i] != 0)
            {
                max += coor[i];
            }
        }
    }

    ll sum = max;
    right++;
    while (right <= 1000001)
    {
        if (left >= 0 && coor[left] != 0)
        {
            sum -= coor[left];
        }
        left++;
        if (coor[right] != 0)
        {
            sum += coor[right];
        }
        right++;
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << max;
    return 0;
}