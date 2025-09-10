#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N,M,i,j;
    cin>>N>>M;
    int num[100002];
    int section_sum[100002];
    num[0]=0;
    section_sum[0]=0;
    for(int a=1; a<=N; a++)
    {
        cin>>num[a];
        section_sum[a]=section_sum[a-1]+num[a];
    }
    for(int a=0;a<M;a++)
    {
        cin>>i>>j;
        cout<<section_sum[j]-section_sum[i-1]<<'\n';
    }
    return 0;
}