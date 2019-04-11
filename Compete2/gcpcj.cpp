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

void solve()
{
    ll n,i,a,b;
    cin >> n;
    vector<vector<ll>> Adj(n);
    i = n - 1;
    while(i--)
    {
        cin >> a >> b;
        Adj[a].pb(b);
        Adj[b].pb(a); 
    }
    queue<pair<ll,ll>> Q;
    Q.push(mp(0,1));
    vector<ll> Level(n,0);
    Level[0] = 1;
    pair<ll,ll> maxi(0,1);
    while(!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        // cout << temp.f << ' ' << temp.s << '\n';
        if(maxi.s<temp.s) 
            maxi = temp;
        for(ll x : Adj[temp.f])
            if(Level[x]==0)
            {
                Level[x] = temp.s+1;
                Q.push(mp(x,temp.s+1));
            }
    }
    // cout << ((maxi.s/2) + ((maxi.s)&1)) << '\n';
    Q.push(mp(maxi.f,1));
    fill(Level.begin(),Level.end(),0);
    Level[maxi.f] = 1;
    maxi.s = 1;
    while(!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        if(maxi.s<temp.s) 
            maxi = temp;
        for(ll x : Adj[temp.f])
            if(Level[x]==0)
            {
                Level[x] = temp.s+1;
                Q.push(mp(x,temp.s+1));
            }
    }
    // cout << maxi.s << '\n';
    maxi.s--;
    cout << ((maxi.s/2) + ((maxi.s)&1)) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}