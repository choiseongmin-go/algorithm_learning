#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin >> N;
    ll left_point = 1;
    ll right_point = 1;
    ll sum = 0;
    ll ways_num = 0;
    while (left_point <= right_point && right_point < N + 2)
    {
        if (sum < N)
        {
            sum += right_point;
            right_point++;
        }
        else if (sum == N)
        {
            ways_num++;
            sum += right_point;
            right_point++;
        }
        else
        {
            sum -= left_point;
            left_point++;
        }
    }
    cout << ways_num;
    return 0;
}