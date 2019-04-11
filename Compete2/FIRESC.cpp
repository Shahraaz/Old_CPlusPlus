//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
const ll size = 100005;
void solve()
{
    ll i, n, m, a, b;
    cin >> n >> m;
    vector<vector<ll>> Adj(size);
    for (i = 0; i < m; ++i)
    {
        cin >> a >> b;
        Adj[a].pb(b);
        Adj[b].pb(a);
    }
    vector<bool> Visited(size, false);
    ll csize = 0, ways = 1;
    for (i = 1; i <= n; ++i)
        if (!Visited[i])
        {
            ll size = 0;
            queue<ll> Q;
            Q.push(i);
            // cout << "Component : \n" ; 
            Visited[i] = true;
            while(!Q.empty())
            {
                size++;
                ll temp = Q.front();
                // cout << temp << ' ';
                Q.pop();
                for(ll x : Adj[temp])
                    if(!Visited[x]){
                        Visited[x] = true;
                        // cout << temp << " inserted " << x << '\n';
                        Q.push(x);
                    }
            // cout << '\n';
            }
            csize++;
            ways = (ways*size)%mod; 
        }
    // cout << "Output " ;
    cout << csize << ' ' << ways << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}