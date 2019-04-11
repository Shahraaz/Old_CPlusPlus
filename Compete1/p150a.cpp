//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    ll i,n,k,x,ctr;
    cin >> n >> k;
    vector<ll> Hash(n*k+1,false);
    vector<ll> Base(k+1,0);
    for(i=1;i<=k;i++){
        cin >> x;
        Hash[x] = true;
        Base[i] = x;
    }
    ctr = 1;
    for(i=1;i<=k;i++){
        cout << Base[i] << ' ';
        for(ll j=1;j<n;j++){
            while(Hash[ctr]) ctr++;
            Hash[ctr] = true;
            cout << ctr << ' ';
        }
        cout << '\n';
    }
    return 0;
}