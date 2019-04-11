//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = 0; i < (b); ++i)
#define trav(a, x) for (auto &a : v)
#define all(x) x.begin(), x.end()
const long long mod = 1000000007;
const long long size = 10007;
vector<vector<ll>> Adj(size);
vector<ll> Level(size, 0);

void DFS(ll index, ll time)
{
    Level[index] = time;
    for (ll a : Adj[index])
        if (Level[a] == 0)
            DFS(a, time + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll i, n, t, x, y;
    cin >> n;
    t = n - 1;
    while (t--)
    {
        cin >> x >> y;
        Adj[x].pb(y);
        Adj[y].pb(x);
    }
    DFS(1, 1);
    pair<ll, ll> maxi(-1, 0);
    for (i = 1; i <= n; i++)
    {
        if (Level[i] > maxi.f)
        {
            maxi.f = Level[i];
            maxi.s = i;
        }
        Level[i] = 0;
    }
    DFS(maxi.s, 1);
    maxi.f = -1;
    maxi.s = 0;
    for (i = 1; i <= n; i++)
        if (Level[i] > maxi.f)
        {
            maxi.f = Level[i];
            maxi.s = i;
        }
    cout << maxi.f - 1;
    return 0;
}