#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
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
        int GCD = gcd(A, B);
        cout << (A / GCD) * B << endl;
    }
    return 0;
}