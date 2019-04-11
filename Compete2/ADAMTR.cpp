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

string solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> Mat(n, vector<ll>(n));
    vector<vector<ll>> MatB(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> Mat[i][j];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> MatB[i][j];
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j <= i; j++)
        {
            if (Mat[i][j] == MatB[i][j])
                continue;
            else if (Mat[i][j] == MatB[j][i])
            {
                vector<ll> A(n);
                for (ll k = 0; k < n; k++)
                    swap(Mat[i][k],Mat[k][i]);
            }
            else
                return "No\n";
        }
    for (ll j = 0; j < n; j++)
        for (ll i = 0; i <= j; i++)
        {
            if (Mat[i][j] == MatB[i][j])
                continue;
            else if (Mat[i][j] == MatB[j][i])
            {
                vector<ll> A(n);
                for (ll k = 0; k < n; k++)
                    swap(Mat[i][k],Mat[k][i]);
            }
            else
                return "No\n";
        }
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            if (Mat[i][j] != MatB[i][j])
                return "No\n";
    return "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    while (t--)
        cout << solve();
    return 0;
}