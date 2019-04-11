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
    ll n,a,b,i,x,y;
    cin >> n ;
    vector< vector<ll> > Adjx(1001),Adjy(1001);
    vector< pair<ll,ll> > Vect;
    for(i=0;i<n;i++){
        cin >> a >> b;
        Vect.pb(mp(a,b));
        Adjx[a].pb(i);
        Adjy[b].pb(i);
    }
    vector<bool> Visited(n,false);
    ll ans = 0;
    for(i=0;i<n;i++){
        if(!Visited[i]){
            ans++;
            queue< pair<ll,ll> > Q;
            Q.push(Vect[i]);
            while(!Q.empty()){
                pair<ll,ll> temp = Q.front();
                Q.pop();
                for(ll x : Adjx[temp.f])
                    if(!Visited[x]){
                        Q.push(Vect[x]);
                        Visited[x] = true;
                    }
                for(ll y : Adjy[temp.s])
                    if(!Visited[y]){
                        Q.push(Vect[y]);
                        Visited[y] = true;
                    }
            }
        }
    }
    cout << ans-1;
    return 0;
}