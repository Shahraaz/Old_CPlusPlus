//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    ll n,k,d,i,j;
    cin >> n >> k >> d;
    vector<ll> Dp(n+1,0),Dp1(n+1,0);
    for(i=1;i<=n;i++){
        if(i<=k){
            if(i>=d) Dp[i] = 1;
            else Dp1[i] = 1; 
        }
        for(j=1;j<=k;j++){ 
            if(i>j){
                Dp[i] = (Dp[i] + Dp[i-j])%mod;
                if(j>=d)
                    Dp[i] = (Dp[i] + Dp1[i-j])%mod;
                else
                    Dp1[i] = (Dp1[i] + Dp1[i-j])%mod;
            }
            else break;
        }
        // cout << Dp[i] << ' ' << Dp1[i] << '\n';
    }
    cout << Dp[n];
    return 0;
}