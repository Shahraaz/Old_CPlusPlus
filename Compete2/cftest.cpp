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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n, d, i, j;
    cin >> n >> d;
    vector<ll> Dp(n, mod);
    Dp[0] = 0;
    string str;
    cin >> str;
    vector<ll> loc;
    ll start = 0, end = 0;
    for (i = 0; i < n; ++i)
        if (str[i] == '1')
            end = i, loc.pb(i);
    for (ll x : loc)
    {
        if(x==0) continue;
        // cout << x << ' ';
        while (loc[start] < x - d) start++;
        Dp[x] = Dp[loc[start]] + 1;
        // cout << start << '\n';
    }
    cout << (Dp[n - 1] > (n+1) ? -1 : Dp[n - 1]);
    return 0;
}