#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    vector<bool> num(1000000, true);
    num[0] = false;
    num[1] = false;
    for (int i = 2; i * i <= 100001; i++)
    {
        if (num[i] == true)
        {
            for (int j = i * i; j <= 100001; j += i)
            {
                num[j] = false;
            }
        }
    }
    int result = 0;
    for (int i = A; i <= B; i++)
    {
        int count = 0;
        int prime = 2;
        int j = i;
        while (j != 1)
        {
            if (num[prime] == true && j % prime == 0)
            {
                j /= prime;
                count++;
            }
            else
            {
                prime++;
            }
        }
        if (num[count] == true)
        {
            result++;
        }
    }
    cout << result;
    return 0;
}