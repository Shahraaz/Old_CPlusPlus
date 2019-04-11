//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=0;i<(b);++i)
#define trav(a,x) for(auto& a : v)
#define all(x) x.begin(),x.end()
const long long mod = 1000000007;

ll add(ll a,ll b){
    return (a+b)%mod;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
    ll i,n,k,j;
    cin >> n >> k;
    vector< vector<ll> > Vect( k , vector<ll>(n+1) );
    for(i=1;i<=n;i++)
        Vect[0][i] = 1;
    for(i=1;i<k;i++)
        for(j=1;j<=n;j++)
            for(ll k=j;k<=n;k+=j)
                Vect[i][k] = add(Vect[i-1][j],Vect[i][k]) ;
    ll answer = 0;
    for(j=1;j<=n;j++)
        answer = add(answer,Vect[k-1][j]);    
    cout << answer;
    return 0;
}