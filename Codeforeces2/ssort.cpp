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
ll casei = 0;
void solve(ll n)
{
    casei++;
    vector<ll> Original(n), Sorted(n);
    ll i;
    for (i = 0; i < n; i++)
    {
        cin >> Original[i];
        Sorted[i] = Original[i];
    }
    sort(Sorted.begin(), Sorted.end());
    vector<ll> Adj(1005);
    ll res = 0;
    for (i = 0; i < n; i++)
        Adj[Sorted[i]] = Original[i];
    for (i = 0; i < n; i++)
        if (Adj[Sorted[i]] != Sorted[i])
        {
            // cout << Sorted[i] << " Sorted[" << i << "]" << " ADj " << Adj[Sorted[i]] << '\n';
            ll sum = 0, length = 0;
            ll j = Sorted[i];
            while (Adj[j] != j)
            {
                // cout << j << ' ' ;
                length++;
                sum += j;
                ll temp = Adj[j];
                Adj[j] = j;
                j = temp;
            }
            length--;
            sum -= Sorted[i];
            res += sum;
            res += min((length * Sorted[0] + 2 * (Sorted[0] + Sorted[i])), (length * Sorted[i]));
            // cout << '\n';
        }
    cout << "Case " << casei << ": " << res << '\n' << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n;
    cin >> n;
    while (n)
    {
        solve(n);
        cin >> n;
    }
    return 0;
}