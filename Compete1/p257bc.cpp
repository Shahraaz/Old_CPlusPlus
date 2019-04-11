// Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
int main(){
    fast;
    ll x,y,n,arr[3];
    cin >> x >> y >> n;
    arr[0] = (mod+x)%mod;
    arr[1] = (mod+y)%mod;
    arr[2] = (mod+y-x)%mod;
    int sign;
    if(((n-1)/3)%2==0) sign = 1;
    else sign = -1;
    cout << (mod+sign*arr[(n-1)%3])%mod; 
    return 0;
}