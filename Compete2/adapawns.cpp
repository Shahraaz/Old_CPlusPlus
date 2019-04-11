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

bool fun(ll n)
{
    if (n & 1)
        return true;
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
        ll cnt = 0;
        vector<ll> V;
        for (ll i = 0; i < n; i++)
            if (str[i] == '.')
                cnt++;
            else{
                V.pb(cnt);
                cnt = 0;
            }
        string turn = "Ada";
        for (ll i = V.size()-1; i >=0 ; i-=2){
            if ((V[i] % 3))
                turn = (turn == "O" ? "Ada" : "O");
        }
        // cout << '\n';
        if (turn == "O")
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}