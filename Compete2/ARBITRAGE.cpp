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
const long long INF = 1e16;

string solve(ll n)
{
    map<string, ll> Map;
    string str, str1;
    vector<vector<ld>> Dist(n, vector<ld>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        cin >> str;
        Map[str] = i;
        Dist[i][i] = 1;
    }
    ll m, j, k, i;
    cin >> m;
    ld cost;
    for (ll i = 0; i < m; i++)
    {
        cin >> str >> cost >> str1;
        Dist[Map[str]][Map[str1]] = cost;
    }
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                Dist[i][j] = max(Dist[i][j], Dist[i][k] * Dist[k][j]);
    for (j = 0; j < n; j++)
        if (Dist[j][j] > 1)
            return "Yes";
    return "No";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n;
    cin >> n;
    ll cnt = 1;
    while (n)
    {
        cout << "Case " << cnt << ':' << ' ';
        cout << solve(n) << '\n';
        cin >> n;
        cnt++;
    }
    return 0;
}