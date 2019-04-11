//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
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
    ll x, y, i, n, r;
    cin >> n >> r;
    vector<ll> Height(n + 1), C(n + 1);
    for (i = 1; i <= n; i++)
        cin >> Height[i];
    for (i = 1; i <= n; i++)
        cin >> C[i];
    vector<vector<ll>> Adj(n + 1);
    while (r--)
    {
        cin >> x >> y;
        Adj[x].pb(y);
        Adj[y].pb(x);
    }
    vector<unsigned long long> Dist1(n + 1, -1);
    vector<unsigned long long> Dist0(n + 1, -1);
    Dist0[1] = C[1];
    Dist1[1] = C[1];
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> Q;
    Q.push(mp(C[1], mp(1, 0)));
    Q.push(mp(C[1], mp(1, 1)));
    while (!Q.empty())
    {
        auto temp = Q.top();
        Q.pop();
        ll source = temp.s.f, sourcedist = temp.f;
        // cout << "Mode " << temp.s.s <<" source " << source << ' ' << "Dist " << sourcedist << '\n';
        if (temp.s.s == 1)
        {
            if (Dist1[source] == sourcedist)
            {
                for (auto x : Adj[source])
                {
                    if (Height[x] >= Height[source])
                    {
                        if (Dist1[x] > Dist1[source])
                        {
                            Dist1[x] = Dist1[source];
                            Q.push(mp(Dist1[x], mp(x, 1)));
                        }
                    }
                    if (Height[x] <= Height[source])
                    {
                        if (Dist0[x] > Dist1[source] + C[source])
                        {
                            Dist0[x] = Dist1[source] + C[source];
                            Q.push(mp(Dist0[x], mp(x, 0)));
                        }
                    }
                }
            }
        }
        else if (temp.s.s == 0)
        {
            if (Dist0[source] == sourcedist)
            {
                for (auto x : Adj[source])
                {
                    if (Height[x] <= Height[source])
                    {
                        if (Dist0[x] > Dist0[source])
                        {
                            Dist0[x] = Dist0[source];
                            Q.push(mp(Dist0[x], mp(x, 0)));
                        }
                    }
                    if (Height[x] >= Height[source])
                    {
                        if (Dist1[x] > Dist0[source] + C[source])
                        {
                            Dist1[x] = Dist0[source] + C[source];
                            Q.push(mp(Dist1[x], mp(x, 1)));
                        }
                    }
                }
            }
        }
    }
    ull mini = min(Dist0[n], Dist1[n]);
    if (mini == (-1))
        cout << -1;
    else
        cout << mini;
    return 0;
}