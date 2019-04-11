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
    ll n, m, x, y, z, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> Adj(n + 5);
    vector<bool> Sp(n + 5, false);
    while (k--)
    {
        cin >> x;
        Sp[x] = true;
    }
    while (m--)
    {
        cin >> x >> y >> z;
        Adj[x].pb(mp(y, z));
        Adj[y].pb(mp(x, z));
    }
    ll ans = High;
    for (ll i = 1; i <= n; ++i)
    {
        if (Sp[i])
        {
            vector<ll> Dist(n + 1, High);
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
            Q.push(mp(0, i));
            Dist[i] = 0;
            ll cnt = 0;
            while (!Q.empty())
            {
                auto temp = Q.top();
                Q.pop();
                if (Dist[temp.s] == temp.f)
                {
                    if (Sp[temp.s])
                        cnt++;
                    if (temp.f > ans)
                        break;
                    if ((cnt == 2))
                    {
                        // cout << i << " th special node closest special " << temp.s << " Dist " << temp.f <<'\n'; 
                        ans = min(ans, temp.f);
                        break;
                    }
                    for (auto x : Adj[temp.s])
                    {
                        if (Dist[x.f] > temp.f + x.s)
                        {
                            Dist[x.f] = temp.f + x.s;
                            // cout << temp.s << " Pushed " << x.f << " Dist src " << temp.f << " Dist tgt " << Dist[x.f] <<'\n';
                            Q.push(mp(Dist[x.f], x.f));
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}