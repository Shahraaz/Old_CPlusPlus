#include<iostream>
using namespace std;
unsigned long int ncr[10000][10000];
int main()
{
    int p,ni,ki;
    unsigned long long int n, k, ans;
    int t,i,j;
    ncr[0][0] = ncr[1][1] = ncr[1][0] = 1;
    for(i=2;i<10000;i++)
        for(j=1,ncr[i][0]=ncr[i][i]=1;j<i;j++)
            ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1]; 
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(n>10000)
        {
            n--;
            k--;
            ans = 1;
            if(k>n/2) k = n - k;
            for(i=0;i<k;i++)
            {
                ans = ans*(n-i);
                ans = ans/(i+1);
            }
            cout << ans << endl; 
        }
        else cout << ncr[n-1][k-1] << endl;
    }
    return 0;
}