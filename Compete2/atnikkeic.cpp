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
vector<ll> X(100005), Y(100005);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll i, n, x, y;
    cin >> n;
    vector<pair<ll, ll>> A;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;
        A.pb(mp(x - y, i));
    }
    // cout << '\n';
    sort(A.begin(), A.end());
    ll start = 0, end = n - 1;
    bool turn = true;
    ll ans = 0;
    vector<pair<ll, ll>> temp;
    ll prev = A[0].f;
    temp.pb(mp(X[A[0].s], Y[A[0].s]));
    for (i = 1; i < n; i++)
    {
        if (A[i].f == prev)
            temp.pb(mp(X[A[i].s], Y[A[i].s]));
        else
        {
            prev = A[i].f;
            sort(temp.begin(), temp.end());
            // for (auto x : temp)
                // cout << x.f << ' ' << x.s << '\n';
            // cout << '\n';
            start = 0;
            end = temp.size() - 1;
            ll j = temp.size();
            while (j--)
            {
                if (turn)
                    ans += temp[end--].f;
                else
                    ans -= temp[end--].s;
                turn = !turn;
            }
            temp.clear();
            temp.pb(mp(X[A[i].s], Y[A[i].s]));
        }
    }
    sort(temp.begin(), temp.end());
    // for (auto x : temp)
        // cout << x.f << ' ' << x.s << '\n';
    // cout << '\n';
    start = 0;
    end = temp.size() - 1;
    ll j = temp.size();
    while (j--)
    {
        if (turn)
            ans += temp[end--].f;
        else
            ans -= temp[end--].s;
        turn = !turn;
    }
    cout << ans;
    return 0;
}