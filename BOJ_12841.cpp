#include <iostream>
using namespace std;

typedef long long ll;

ll left_section_sum[100002];
ll right_section_sum[100002];
ll distance_crosswalk[100002];
ll left_distance[100001];
ll right_distance[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> distance_crosswalk[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> left_distance[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> right_distance[i];
    }
    for (int i = 1; i <= n; i++)
    {
        left_section_sum[i] = left_section_sum[i - 1] + left_distance[i - 1];
    }
    right_section_sum[n] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        right_section_sum[i] = right_section_sum[i + 1] + right_distance[i];
    }

    ll min_total_distance = -1;
    int best_crosswalk = -1;

    for (int i = 1; i <= n; i++)
    {
        ll current_total_distance = left_section_sum[i] + distance_crosswalk[i] + right_section_sum[i];

        if (best_crosswalk == -1 || current_total_distance < min_total_distance)
        {
            min_total_distance = current_total_distance;
            best_crosswalk = i;
        }
    }
    cout << best_crosswalk << " " << min_total_distance << "\n";

    return 0;
}