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
    ll n, a, b, i;
    cin >> n >> b >> a;
    vector<ll> Vect(n + 1);
    vector<ld> Prefix(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> Vect[i];
        Prefix[i] = Prefix[i - 1] + Vect[i];
        // cout << i << ' ' << Prefix[i] << '\n';
    }
    // cout << '\n';
    ld res = 0, temp, sum;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i + a - 1; j <= n && j < (i + b); j++)
        {
            // cout << i << ' ' << j << ' ' << j - i + 1<< '\n'; 
            res = max(res, (Prefix[j] - Prefix[i-1]) / (j - i + 1));
        }
    }
    cout << setprecision(9) << fixed << res << '\n';
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