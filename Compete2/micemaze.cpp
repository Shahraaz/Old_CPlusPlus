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
const long long High = 1e16;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n, e, t, m, x, y, w,z;
    cin >> n >> e >> t >> m;
    vector<vector<pair<ll, ll>>> Adj(n + 1);
    while (m--)
    {
        cin >> x >> y >> z;
        Adj[y].pb(mp(x, z));
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(mp(0,e));
    vector<ll> Dist(n+1,High);
    Dist[e] = 0;
    while(!Q.empty())
    {
        auto temp = Q.top();
        Q.pop();
        if(temp.f == Dist[temp.s])
        {
            for(auto x : Adj[temp.s])
            {
                if(Dist[x.f] > temp.f + x.s )
                {
                    Dist[x.f] = temp.f + x.s;
                    Q.push(mp(Dist[x.f],x.f));
                }
            }
        }
    }
    ll ans = 0;
    n++;
    while(n--)
    {
        if(Dist[n] <= t)
            ans++;
    }
    cout << ans;
    return 0;
}