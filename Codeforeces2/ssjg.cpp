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

void solve()
{
    ll n, m, a, b, i, j;
    cin >> n >> m;
    vector<vector<ll>> Grid(n + 2, vector<ll>(n + 2, 0));
    i = m;
    while (m--)
    {
        cin >> a >> b;
        Grid[a][b] = 1;
    }
    m = i;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++){
            Grid[i][j] = Grid[i][j - 1] + Grid[i - 1][j] - Grid[i - 1][j - 1] + (Grid[i][j]);
            // cout << "Grid[" << i << "][" << j << "] " << Grid[i][j] << '\n';
        }
    ll maxi = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            ll a = Grid[i][j];
            ll b = Grid[n][j] - a;
            ll c = Grid[i][n] - a;
            ll d = m - a - b - c;
            // cout << a << ' ' << b << ' ' << c << ' '  << d << '\n';
            a = min(a,b);
            b = min(c,d);
            a = min(a,b);
            maxi = max(maxi, a);
        }
    cout << maxi << '\n';
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