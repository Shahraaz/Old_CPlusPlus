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
    ll X, Y, L1, L2;
    ll x[8];
    cout << "Q " << 0 << ' ' << 0 << endl;
    cin >> x[0];
    cout << "Q " << 1000000000 << ' ' << 0 << endl;
    cin >> x[1];
    cout << "Q " << 0 << ' ' << 1000000000 << endl;
    cin >> x[2];
    cout << "Q " << 1000000000 << ' ' << 1000000000 << endl;
    cin >> x[3];
    if (x[0] <= 1000000000)
    {
        cout << "Q " << x[0] << ' ' << 0 << endl;
        cin >> x[4];
        Y = x[4] / 2;
        X = x[0] - Y;
        L1 = -x[2] + 1000000000 - X + Y;
        L2 = -x[1] + 1000000000 + X - Y;
    }
    else if (x[1] <= 1000000000)
    {
        cout << "Q " << 1000000000 - x[1] << ' ' << 0 << endl;
        cin >> x[4];
        Y = x[4] / 2;
        X = x[0] - Y;
        L1 = -x[2] + 1000000000 - X + Y;
        L2 = -x[1] + 1000000000 + X - Y;
    }
    else if (x[2] <= 1000000000)
    {
        cout << "Q " << 0 << ' ' << 1000000000 - x[2] << endl;
        cin >> x[4];
        Y = x[4] / 2;
        X = x[0] - Y;
        L1 = -x[2] + 1000000000 - X + Y;
        L2 = -x[1] + 1000000000 + X - Y;
    }
    else if (x[3] <= 1000000000)
    {
        cout << "Q " << 1000000000 - x[3] << ' ' << 0 << endl;
        cin >> x[4];
        Y = x[4] / 2;
        X = x[0] - Y;
        L1 = -x[2] + 1000000000 - X + Y;
        L2 = -x[1] + 1000000000 + X - Y;
    }
    cout << "A " << X << ' ' << Y << ' ' << X + L1 << ' ' << Y + L2 << endl;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}