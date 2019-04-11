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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n,m,a,b;
    cin >> n >> m ;
    if(n!=m+1){
        cout << "NO";
        return 0;
    }
    vector<vector<ll>> Adj(n);
    while(m--)
    {
        cin >> a >> b;
        a--;
        b--;
        Adj[a].pb(b); 
        Adj[b].pb(a);
    }
    queue<ll> Q;
    ll cnt = 0;
    vector<ll> Visited(n);
    Q.push(0);
    Visited[0] = true;
    while(!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        cnt++;
        for(ll x : Adj[temp])
            if(!Visited[x])
            {
                Visited[x] = true;
                Q.push(x);
            }
    }
    if(cnt==n) cout << "YES";
    else cout << "NO" ;
    return 0;
}