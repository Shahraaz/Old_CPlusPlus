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

ll Abs(ll x)
{
    if (x < 0)
        x = -x;
    return x;
}

void solve()
{
    string Str;
    cin >> Str;
    vector<ll> Hash(26, 0);
    vector<int> V;
    for (int i = 1; i <= 26; ++i)
        if (Str.length() % i == 0)
            V.pb(i);
    for (char ch : Str)
        Hash[ch - 'A']++;
    ll mini = 1e16;
    vector<pair<int, int>> Seq;
    for (int i = 0; i < 26; ++i)
        Seq.emplace_back(Hash[i], i);
    sort(Seq.begin(),Seq.end(),greater< pair<int,int> >());
    for (int Dist : V)
    {
        // cout << Dist << '\n';
        ll h = 0, freq = Str.length() / Dist;
        vector<ll> Hash2(26, 0);
        for (int i = 0; i < 26; ++i)
            if (Hash[Seq[i].s] && Dist)
            {
                Dist--;
                Hash2[Seq[i].s] = freq;
            }
        for (int i = 0; i < 26; ++i)
            if (Dist && Hash2[Seq[i].s] == 0)
            {
                Hash2[Seq[i].s] = freq;
                Dist--;
            }
        for (int i = 0; i < 26; ++i)
        {
            // if (Hash[i] || Hash2[i])
                // cout << char(i + 'A') << ' ' << Hash[i] << ' ' << Hash2[i] << '\n';
            h += Abs(Hash[i] - Hash2[i]);
        }
        // cout << h / 2 << '\n';
        mini = min(mini, h);
        // cout << '\n';
    }
    // cout << "Anser ";
    cout << mini / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    // cout << Abs(5) << ' ' << Abs(-5) << '\n';
    while (t--)
        solve();
    return 0;
}