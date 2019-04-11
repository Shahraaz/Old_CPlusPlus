//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

ll add(ll a, ll b)
{
    return (a+b)%mod;
}
vector<vector<ll>> Dp(5001, vector<ll>(5001, 0)),Suff(5001, vector<ll>(5001, 0));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n,i,j;
    cin >> n;
    char inp[n];
    for (i = 0; i < n; i++)
        cin >> inp[i];
    Dp[0][0] = 1;
    for(i=1;i<n;i++)
    {
        Suff[i-1][n-1] = Dp[i-1][n-1];
        for(j=n-2;j>=0;j--)
            Suff[i-1][j] = add(Suff[i-1][j+1],Dp[i-1][j]);
        for(j=0;j<n;j++)
            if(inp[i-1]=='f')
            {
                if(j!=0)
                    Dp[i][j] = Dp[i-1][j-1];
                else Dp[i][j] = 0;
            }
            else 
                Dp[i][j] = Suff[i-1][j];
    }
    i = 0;
    for(j=0;j<n;j++)
        i = add(i,Dp[n-1][j]);
    cout << i;
    return 0;
}