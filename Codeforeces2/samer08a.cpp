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
void solve(ll n, ll m)
{
    vector<map<ll, ll>> Adj(n);
    vector<set<ll>> Parent(n);
    vector<ll> Dist(n, High);
    ll s, d;
    cin >> s >> d;
    while (m--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        Adj[x][y] = z;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push(mp(0, s));
    Dist[s] = 0;
    while (!Q.empty())
    {
        pair<ll, ll> temp = Q.top();
        Q.pop();
        if (temp.f == Dist[temp.s])
        {
            for (auto x = Adj[temp.s].begin(); x != Adj[temp.s].end(); x++)
            {
                if (temp.f + x->s == Dist[x->f])
                    Parent[x->f].insert(temp.s);
                else if (temp.f + x->s < Dist[x->f])
                {
                    Dist[x->f] = x->s + temp.f;
                    Parent[x->f].clear();
                    Parent[x->f].insert(temp.s);
                    Q.push(mp(Dist[x->f], x->f));
                }
            }
        }
    }
    queue<ll> q;
    q.push(d);
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        for(auto it = Parent[temp].begin();it!=Parent[temp].end();it++)
        {
            q.push(*it);
            Adj[*it][temp] = High;
        }
    }
    Q.push(mp(0, s));
    fill(Dist.begin(),Dist.end(),High);
    Dist[s] = 0;
    while (!Q.empty())
    {
        pair<ll, ll> temp = Q.top();
        Q.pop();
        if (temp.f == Dist[temp.s])
        {
            for (auto x = Adj[temp.s].begin(); x != Adj[temp.s].end(); x++)
            {
                if (temp.f + x->s == Dist[x->f])
                    Parent[x->f].insert(temp.s);
                else if (temp.f + x->s < Dist[x->f])
                {
                    Dist[x->f] = x->s + temp.f;
                    Parent[x->f].clear();
                    Parent[x->f].insert(temp.s);
                    Q.push(mp(Dist[x->f], x->f));
                }
            }
        }
    }
    if(Dist[d]>=High)
        cout << -1 << '\n';
    else cout << Dist[d] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n, m;
    cin >> n >> m;
    while (n && m)
    {
        solve(n, m);
        cin >> n >> m;
    }
    return 0;
}