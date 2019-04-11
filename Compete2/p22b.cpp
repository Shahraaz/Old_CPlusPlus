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
    cin.exceptions(cin.failbit);
    ll i, n, m, j, k, answer;
    cin >> n >> m;
    vector<string> Grid(n);
    vector<vector<ll>> Far(n, vector<ll>(m));
    vector<vector<ll>> Dist(n, vector<ll>(m, mod));
    answer = 0;
    for (i = 0; i < n; ++i)
    {
        cin >> Grid[i];
        for (j = m - 1; j >= 0; --j)
            if (Grid[i][j] == '1')
                Far[i][j] = j - 1;
            else if (j == (m - 1))
                Far[i][j] = j;
            else
                Far[i][j] = Far[i][j + 1];
    }
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
        {
            ll dist = mod;
            for (k = i; k < n && (Grid[k][j] == '0'); ++k)
            {
                dist = min(dist, Far[k][j]);
                answer = max(answer, 2 * (k - i + 1 + dist - j + 1));
            }
        }
    cout << answer;
    return 0;
}