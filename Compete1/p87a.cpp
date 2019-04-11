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
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    ll i,j,n,x,k;
    cin >> n;
    vector<ll> indegree(n+1,0);
    vector<ll> level(n+1,0);
    vector< vector<ll> > Adj(n+1);
    for(i=1;i<=n;i++){
        cin >> x;
        if(x!=-1){
            indegree[i]++;
            Adj[x].pb(i);
        }
    }
    queue<ll> temp;
    for(i=1;i<=n;i++){
        // cout << i << ' ' << indegree[i] << '\n';
        if(indegree[i]==0) temp.push(i);
    }
    while(temp.empty()!=true){
        j = temp.front();
        temp.pop();
        for(i = 0;i<Adj[j].size();i++){
            indegree[ Adj[j][i] ]--;
            level[ Adj[j][i] ] = max(level[ Adj[j][i] ],level[j]+1);
            if(indegree[Adj[j][i]]==0){
                temp.push(Adj[j][i]);
            }
        }
    }
    ll maxi = 0;
    for(i=1;i<=n;i++)
        maxi = max(maxi,level[i]);
    cout << maxi+1; 
    return 0;
}