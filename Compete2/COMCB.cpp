//Optimise Yourself
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

ll a, b;
vector<pair<ll, ll>> res(27 * 27);
vector<vector<bool>> Visited(27, vector<bool>(27));
ll cnt;
ll c[] = {-1, 1, -2, 2, -2, 2, -1, 1};
ll d[] = {-2, -2, -1, -1, 1, 1, 2, 2};

bool isin(ll i, ll j)
{
    return i >= 0 && i < a && j >= 0 && j < b;
}

bool BFS(ll i, ll j)
{
    Visited[i][j] = true;
    res[cnt].f = i;
    res[cnt].s = j;
    cnt++;
    if (cnt == (a * b))
    {
        for (i = 0; i < cnt; i++)
            cout << char('A' + res[i].s) << res[i].f + 1;
        cout << '\n';
        return true;
    }
    for (ll k = 0; k < 8; k++)
    {
        ll i1 = i + c[k];
        ll j1 = j + d[k];
        if (isin(i1, j1) && !Visited[i1][j1])
            if (BFS(i1, j1))
                return true;
    }
    cnt--;
    Visited[i][j] = false;
    return false;
}

void solve()
{
    cin >> a >> b;
    ll i, j;
    for (i = 0; i < a; ++i)
        for (j = 0; j < b; ++j)
            Visited[i][j] = false;
    for (i = 0; i < a; ++i)
        for (j = 0; j < b; ++j)
        {
            cnt = 0;
            if (BFS(i, j))
                return;
        }
    cout << -1 << '\n';
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