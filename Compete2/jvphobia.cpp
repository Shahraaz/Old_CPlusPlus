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
    ll n, m, k, S, a, b, w;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> Adj(n + 1);
    vector<bool> Visited(n + 1, false);
    while (m--)
    {
        cin >> a >> b >> w;
        Adj[a].pb(mp(b, w));
        Adj[b].pb(mp(a, w));
    }
    cin >> k >> S;
    queue<ll> Q;
    while (k--)
    {
        cin >> a;
        Q.push(a);
        Visited[a] = true;
    }
    while (!Q.empty())
    {
        ll temp = Q.front();
        Q.pop();
        for (pair<ll, ll> x : Adj[temp])
            if (!Visited[x.f] && x.s <= S)
            {
                Visited[x.f] = true;
                Q.push(x.f);
            }
    }
    ll ans = 0;
    for (auto x : Visited)
        ans += x;
    cout << ans;
    return 0;
}