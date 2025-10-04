#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int card_length = 0;
    cin >> card_length;
    if (card_length < 1 || card_length > 500000)
        return -1;

    queue<int> q;
    for (int i = 1; i <= card_length; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        int trash = 0;
        q.pop();
        trash = q.front();
        q.pop();
        q.push(trash);
    }

    cout << q.front() << endl;
    return 0;
}
