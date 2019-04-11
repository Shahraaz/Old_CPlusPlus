//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ll> pul;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
const long long inf = 1e16;

void solve()
{
    ll n, m, x, y, source, sink, i;
    cin >> n >> m;
    ull w;
    vector<vector<pair<ull, ll>>> Adj(n + 1);
    vector<ll> Start(n + 1), End(n + 1);
    while (m--)
    {
        cin >> x >> y >> w;
        Adj[x].pb(mp(w, y));
        Adj[y].pb(mp(w, x));
    }
    vector<ll> Dist(n + 1, inf);
    n++; 
    while (n--)
    {
        sort(Adj[n].begin(), Adj[n].end());
        Start[n] = 0;
        End[n] = Adj[n].size() - 1;
    }
    cin >> source >> sink;
    priority_queue<pair<ll,pair<ll, pll>>, vector<pair<ll,pair<ll, pll>>>, greater<pair<ll,pair<ll, pll>>>> Q;
    Dist[source] = 0;
    Q.push(mp(0,mp(source, mp(1, 0))));
    while (!Q.empty())
    {
        auto temp = Q.top();
        Q.pop();
        Dist[temp.s.f] = min(temp.f, Dist[temp.s.f]);
        if (temp.s.s.f)
        {
            for (i = End[temp.s.f]; i >= 0; i--)
            {
                if (Adj[temp.s.f][i].f > temp.s.s.s)
                    Q.push(mp(temp.f+Adj[temp.s.f][i].f,mp(Adj[temp.s.f][i].s, mp(0, Adj[temp.s.f][i].f))));
                else
                    break;
            }
            End[temp.s.f] = i;
        }
        else
        {
            for (i = Start[temp.s.f]; i < Adj[temp.s.f].size(); i++)
            {
                if (Adj[temp.s.f][i].f < temp.s.s.s)
                    Q.push(mp(temp.f+Adj[temp.s.f][i].f,mp(Adj[temp.s.f][i].s, mp(1, Adj[temp.s.f][i].f))));
                else
                    break;
            }
            Start[temp.s.f] = i;
        }
    }
    /*     for (i = 1; i < Dist.size(); i++)
        cout << "i " << i << ' ' << Dist[i] << '\n';
 */
    if (Dist[sink] == inf)
        cout << "No Solution\n";
    else
        cout << Dist[sink] << '\n';
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