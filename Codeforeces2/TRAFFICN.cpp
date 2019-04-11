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
const long long High = 1e17;

void solve()
{
    ll n, m, k, s, t, q;
    cin >> n >> m >> k >> s >> t;
    vector<vector<pair<ll, ll>>> Adj(n + 5);
    vector<vector<pair<ll, ll>>> Parent(n + 5);
    for (ll i = 1; i <= m; i++)
    {
        ll s, t, w;
        cin >> s >> t >> w;
        Adj[s].pb(mp(w, t));
        Parent[t].pb(mp(w, s));;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    vector<ll> Dist(n + 1, High);
    vector<ll> Dist1(n + 1, High);
    Dist[s] = 0;
    Q.push(mp(0, s));
    while (!Q.empty())
    {
        auto temp = Q.top();
        Q.pop();
        if (Dist[temp.s] == temp.f)
        {
            for (pair<ll, ll> x : Adj[temp.s])
            {
                if (temp.f + x.f < Dist[x.s])
                {
                    Dist[x.s] = temp.f + x.f;
                    Q.push(mp(Dist[x.s], x.s));
                }
            }
        }
    }
    Dist1[t] = 0;
    Q.push(mp(0, t));
    while (!Q.empty())
    {
        auto temp = Q.top();
        Q.pop();
        if (Dist1[temp.s] == temp.f)
        {
            for (pair<ll, ll> x : Parent[temp.s])
            {
                if (temp.f + x.f < Dist1[x.s])
                {
                    Dist1[x.s] = temp.f + x.f;
                    Q.push(mp(Dist1[x.s], x.s));
                }
            }
        }
    }
    ll mini = Dist[t];
    while (k--)
    {
        ll ui, vi, qi;
        cin >> ui >> vi >> qi;
        mini = min(mini,Dist[ui]+qi+Dist1[vi]);
        mini = min(mini,Dist[vi]+qi+Dist1[ui]);        
    }
    if (mini == High)
        cout << -1 << '\n';
    else
        cout << mini << '\n';
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