//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

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
    ll n, i;
    cin >> n;
    vector<ll> Dp(n+1,0),Dp1(n+1,0);
    Dp1[1] = 3;
    for(i=2;i<=n;i++){
        Dp[i] = Dp1[i-1];
        Dp1[i] = ((3*Dp[i-1])%mod + (2*Dp1[i-1])%mod)%mod;
    }
    cout << Dp[n];
    return 0;
}