#include <iostream>
using namespace std;

typedef long long ll;

ll left_section_sum[100002];
ll right_section_sum[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll distance[100002];
    int n;
    cin >> n;
    ll distance_crosswalk[100002];
    ll left_distance[100001];
    ll right_distance[100001];
    for (int i = 1; i <= n; i++)
    {
        cin >> distance_crosswalk[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> left_distance[i];
        left_section_sum[i] = left_section_sum[i - 1] + left_distance[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> right_distance[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        right_section_sum[i] = right_section_sum[i + 1] + right_section_sum[i];
    }
    int cross_point;
    int left, right;
    distance[1] = distance_crosswalk[1] + right_section_sum[1];
    distance[n] = distance_crosswalk[n] + right_section_sum[n - 1];
    for (int i = 2; i <= n - 1; i++)
    {
        cross_point = i;
        left = left_section_sum[i - 1];
        right = right_section_sum[i - 1];
        distance[i] = distance_crosswalk[i] + left + right;
    }
    int short_distance = distance[1];
    int short_distance_point = 1;
    for (int i = 2; i <= n; i++)
    {
        if (distance[i] < short_distance)
        {
            short_distance = distance[i];
            short_distance_point = i;
        }
    }
    cout << short_distance_point << short_distance;
    return 0;
}