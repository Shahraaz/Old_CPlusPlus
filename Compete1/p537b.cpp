//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cin.exceptions(cin.failbit);
    int n, k, m, x;
    cin >> n >> k >> m;
    vector<int> po, answer;
    ll sum = 0, presum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        po.pb(x);
        sum += x;
    }
    sort(po.begin(), po.end());
    ld maxavg = (ld)sum / n, avg;
    for (int i = 0; i < n; ++i)
    {
        ll t = m - i, cnt = n - i;
        if (t < 0)
            break;
        t = min(t, cnt * k);
        ld avg = (ld)(t + sum - presum) / cnt;
        presum += po[i];
        maxavg = max(maxavg, avg);
        // cout << i << ' ' << avg << '\n';
    }
    cout << setprecision(9) << fixed << maxavg << '\n';
    return 0;
}