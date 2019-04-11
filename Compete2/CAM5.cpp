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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    while(t--){
        ll n,e,a,b;
        cin >> n >> e;
        vector< vector<ll> > Edges(n);
        vector<bool> visited(n);
        while(e--){
            cin >> a >> b;
            Edges[a].pb(b);
            Edges[b].pb(a);
        }
        ll Components = 0;
        for(ll i=0;i<n;i++){
            if(!visited[i]){
                queue<ll> Q;
                Q.push(i);
                visited[i] = true;
                while(!Q.empty()){
                    ll temp = Q.front();
                    Q.pop();
                    for(ll x : Edges[temp])
                        if(!visited[x]){
                            visited[x] = true;
                            Q.push(x);
                        }
                }
                Components++;
            }
        }
        cout << Components << '\n'; 
    }    
    return 0;
}