#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll S, P;
    cin >> S >> P;
    vector<char> dna;
    dna.push_back('S');
    for (int i = 1; i <= S; i++)
    {
        char x;
        cin >> x;
        dna.push_back(x);
    }
    ll A, C, G, T;
    cin >> A >> C >> G >> T;
    ll left = 1;
    ll right = P + 1;
    ll pw = 0;
    ll a, c, g, t = 0;
    for (int i = 1; i <= P; i++)
    {
        switch (dna[i])
        {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;
        }
    }
    if (a >= A && c >= C && g >= G && t >= T)
        pw++;
    for (int i = 1; i <= S - P; i++)
    {
        switch (dna[left])
        {
        case 'A':
            a--;
            break;
        case 'C':
            c--;
            break;
        case 'G':
            g--;
            break;
        case 'T':
            t--;
            break;
        }
        switch (dna[right])
        {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;
        }
        if (a >= A && c >= C && g >= G && t >= T)
            pw++;
        left++;
        right++;
    }
    cout << pw;
    return 0;
}