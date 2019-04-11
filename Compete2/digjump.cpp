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
const ll inf = numeric_limits<ll>::max();

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t=1;
    while(t--){
        string str;
        cin >> str;
        ll length = str.length();
        vector< vector<ll> > Adj(10);
        vector<ll> Dist(length,inf);
        Dist[0] = 0;
        for(ll i=0;i<length;++i)
            Adj[str[i]-'0'].pb(i);
        queue<ll> Q;
        Q.push(0);
        vector<bool> visited(length,0);
        vector<bool> Visit(10,0);
        visited[0] = true;
        // cout << 0 << '\n';
        while(!Q.empty()){
            ll temp = Q.front();
            Q.pop();
            // cout << temp << ' ';
            if(temp==(length-1)){
                cout << Dist[length-1] ;
                return 0;
            }
            visited[temp] = true;
            if(!Visit[str[temp]-'0'])
                for(ll x: Adj[str[temp]-'0']){
                        // cout << x << ' ';
                        if(!visited[x] && (Dist[x]>(Dist[temp]+1))){
                            Dist[x] = Dist[temp]+1;
                            Q.push(x);
                        }
                        visited[x] = true;
                }
            Visit[str[temp]-'0'] = true;
            if((temp-1)>=0){
                // cout <<temp-1 << ' ';
                ll x = temp - 1 ;
                if(!visited[x] && (Dist[x]>(Dist[temp]+1))){
                    Dist[x] = Dist[temp]+1;
                    Q.push(x);
                }
                visited[x] = true;
            }
            if((temp+1)>=0){
                // cout <<temp-1 << ' ';
                ll x = temp + 1 ;
                if(!visited[x] && (Dist[x]>(Dist[temp]+1))){
                    Dist[x] = Dist[temp]+1;
                    Q.push(x);
                }
                visited[x] = true;
            }
        }
    }    
    return 0;
}