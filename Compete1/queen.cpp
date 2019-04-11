//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
ll a[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll b[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll n, m;
vector<vector<bool>> Board(1005,vector<bool>(1005));

bool isaccessible(pair<ll, ll> p)
{
    return (p.f >= 0) && (p.f < n) && (p.s >= 0) && (p.s < m) && (Board[p.f][p.s]);
}

void solve()
{
    ll i, j;
    pair<ll, ll> S, F;
    cin >> n >> m;
    string str;
    vector<vector<ll>> Dist(n, vector<ll>(m));
    for (i = 0; i < n; i++)
    {
        cin >> str;
        for (j = 0; j < m; j++)
        {    if (str[j] == 'S')
                S = mp(i, j);
            else if (str[j] == 'F')
                F = mp(i, j);
            if(str[j]=='X') 
                Board[i][j] = false;
            else Board[i][j] = true;
        }   
    }
    queue<pair<ll, ll>> Q;
    Q.push(S);
    Dist[S.f][S.s] = 1;
    while (!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        for (i = 0; i < 8; i++)
        {
            auto temp2 = mp(temp.f + a[i], temp.s + b[i]);
            while (isaccessible(temp2))
            {
                if (Dist[temp2.f][temp2.s] == 0)
                {
                    Dist[temp2.f][temp2.s] = Dist[temp.f][temp.s] + 1;
                    Q.push(temp2);
                }
                if (temp2 == F)
                {
                    cout << Dist[F.f][F.s] - 1 << '\n';
                    return;
                }
                temp2.f += a[i];
                temp2.s += b[i];
            }
        }
    }
    if (Dist[F.f][F.s] == 0)
        cout << -1 << '\n';
    else
        cout << Dist[F.f][F.s] - 1 << '\n';
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