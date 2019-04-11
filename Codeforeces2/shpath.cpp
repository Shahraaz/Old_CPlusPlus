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
vector<vector<pair<ll, ll>>> Adj(10005);

void solve()
{
    ll n;
    cin >> n;
    map<string, ll> Map;
    string str, source, Target;
    for (ll i = 1; i <= n; i++)
    {
        cin >> str;
        Map[str] = i;
        ll m, c, x;
        cin >> m;
        Adj[i].clear();
        while (m--)
        {
            cin >> x >> c;
            Adj[i].pb(mp(c, x));
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        cin >> source >> Target;
        ll s = Map[source], t = Map[Target];
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
        vector<ll> Dist(n + 1, High);
        Dist[s] = 0;
        Q.push(mp(0, s));
        while (!Q.empty())
        {
            auto temp = Q.top();
            Q.pop();
            if (Dist[temp.s] == temp.f)
            {
                for (pair<ll,ll> x : Adj[temp.s])
                {
                    if (temp.f + x.f < Dist[x.s])
                    {
                        Dist[x.s] = temp.f + x.f;
                        Q.push(mp(Dist[x.s], x.s));
                    }
                }
            }
        }
        cout << Dist[t] << '\n';
    }
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