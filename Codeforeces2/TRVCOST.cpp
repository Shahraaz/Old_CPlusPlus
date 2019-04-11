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
    vector<vector<pair<ll, ll>>> Adj(505);
    ll n, a, b, c, u;
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c;
        Adj[a].pb(mp(b, c));
        Adj[b].pb(mp(a, c));
    }
    cin >> u;
    vector<ll> Dist(505, High);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(mp(0, u));
    Dist[u] = 0;
    while (!Q.empty())
    {
        auto temp = Q.top();
        Q.pop();
        if (Dist[temp.s] == temp.f)
        {
            for (auto x : Adj[temp.s])
            {
                if (Dist[x.f] > temp.f + x.s)
                {
                    Dist[x.f] = temp.f + x.s;
                    Q.push(mp(Dist[x.f], x.f));
                }
            }
        }
    }
    ll q,x;
    cin >> q;
    while(q--)
    {
        cin >> x;
        if(Dist[x]==High)
            cout << "NO PATH\n";
        else cout << Dist[x] << '\n';
    }
    return 0;
}