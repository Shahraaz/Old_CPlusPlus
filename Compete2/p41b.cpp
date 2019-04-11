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
    ll n, k;
    cin >> n >> k;
    vector<ll> Vect(n+1);
    vector<bool> Value(n+1+k);
    ll ans = 0;
    vector<ll> Prefix(n+1+k, 0);
    for (ll i = 1; i <= n; i++)
        cin >> Vect[i];
    for (ll i = 1; i <= n; i++)
    {
        bool x;
        cin >> x;
        Prefix[i] = Prefix[i - 1];
        if (x)
            ans += Vect[i];
        else
            Prefix[i] += Vect[i];
        // cout << Prefix[i] << ' ';
        // cout << x << '\n';
    }
    // cout << '\n';
    ll maxi = 0;
    // cout << ans << '\n';
    for (ll i = 1; i <= (n - k + 1); i++)
        maxi = max(maxi, Prefix[i + k - 1] - Prefix[i-1]);
    cout << ans + maxi << '\n';
    return 0;
}