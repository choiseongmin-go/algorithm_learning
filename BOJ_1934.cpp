#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int c;
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b)
{
    int result;
    result = a * b / GCD(a, b);
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, A, B;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        cout << LCM(A, B) << '\n';
    }
    return 0;
}