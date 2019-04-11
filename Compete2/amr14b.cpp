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

ll p[200005];
ll f(ll a)
{
    if (a == p[a])
        return a;
    else
        return p[a] = f(p[a]);
}

void solve()
{
    ll n, m, i, u, v, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> Adj(20005);
    vector<pair<ll, pair<ll, ll>>> Edges;
    i = m;
    while (m--)
    {
        cin >> u >> v >> w;
        Adj[u].pb(mp(v, w));
        Adj[v].pb(mp(u, w));
        Edges.pb(mp(w, mp(u, v)));
    }
    m = i;

    // Dijkstra Algo
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push(mp(0, 0));
    vector<ll> Dist(n, 1e18), Parentweight(n, 0);
    Dist[0] = 0;
    vector<ll> Visited(n, false);
    Visited[0] = true;
    while (!q.empty())
    {
        auto temp = q.top();
        // cout << temp.f << ' ' << temp.s << '\n';
        q.pop();
        if (Dist[temp.s] != temp.f)
            continue;
        for (pair<ll, ll> x : Adj[temp.s])
            if (Dist[x.f] == Dist[temp.s] + x.s)
                Parentweight[x.f] = min(Parentweight[x.f], x.s);
            else if (Dist[x.f] > Dist[temp.s] + x.s)
            {
                Visited[x.f] = true;
                Dist[x.f] = Dist[temp.s] + x.s;
                q.push(mp(Dist[x.f], x.f));
                Parentweight[x.f] = x.s;
                // cout << "push " << temp.s << ' ' << x.f << '\n';
            }
    }
    // cout << "Graph\n";
    ll b = 0;
    for (i = 0; i < n; i++)
    {
        // cout <<  Visited[i] <<' '<< Dist[i] << ' ' << Dist2[i] << '\n';
        if (!Visited[i])
        {
            cout << "NO\n";
            return;
        }
        b += Parentweight[i];
        p[i] = i;
    }

    //Kruskal Algo
    sort(Edges.begin(), Edges.end());
    ll mstwt = 0;
    ll e = 0;
    for (i = 0; i < m; i++)
    {
        ll u = f(Edges[i].s.f), v = f(Edges[i].s.s);
        if (u != v)
        {
            p[u] = v;
            mstwt += Edges[i].f;
            e++;
            if (e == (n - 1))
                break;
        }
    }

    if (mstwt != b)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    // srand(time(NULL));
    while (t--)
        solve();
    return 0;
}