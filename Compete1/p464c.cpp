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
    ll n;
    cin >> n;
    vector<ll> Vect(2 * n + 1,0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> Vect[i];
        Vect[i + n] = Vect[i];
    }
    cout << Vect[0] << ' ';
    for (ll i = 1; i <= 2 * n; i++)
    {
        Vect[i] += Vect[i - 1];
        cout << Vect[i] << ' ';
    }
    cout << '\n';
    ll s, f;
    cin >> s >> f;
    s = f - s ;
    ll maxi = -1;
    ll index = -1;
    for (ll i = 0; i <= n; i++)
        if (maxi < (Vect[i + s ] - Vect[i - 1]))
        {
            cout << maxi << " -> " ;
            maxi = Vect[i + s ] - Vect[i - 1];
            index = i;
            cout << maxi << " " << index << " Vect[i+s] " << Vect[i+s] << ' ' << Vect[i-1] << '\n';
        }
    cout << index << '\n';
    return 0;
}