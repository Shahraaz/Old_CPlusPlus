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

bool fun(string str, ll n, string turn)
{
    // cout << str << '\n';
    for (ll i = 1; i < n; i++)
    {
        if (str[i] == 'P')
        {
            if (str[i - 1] == 'P')
                continue;
            str[i] = '.';
            str[i - 1] = 'P';
            if (!fun(str, n, (turn == "Ada" ? "O" : "Ada")))
            {
                // if (turn == "Ada")
                    // cout << "Ada " << str << '\n';
                return true;
            }
            str[i] = 'P';
            str[i - 1] = '.';
            if (i >= 2 && str[i - 2] == '.' && str[i - 1] == '.')
            {
                str[i] = '.';
                str[i - 2] = 'P';
                if (!fun(str, n, (turn == "Ada" ? "O" : "Ada")))
                {
                    // if (turn == "Ada")
                        // cout << "Ada " <<str << '\n';
                    return true;
                }
                str[i] = 'P';
                str[i - 2] = '.';
            }
        }
    }
    // if (turn == "O")
        // cout << "O " << str << '\n';
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t;
    cin >> t;
    // cout << "Start\n";
    while (t--)
    {
        ll n;
        string str;
        cin >> str;
        n = str.length();
        // cout << str << '\n';
        if (fun(str, n, "Ada"))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}