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
    ll n,i,j;
    cin >> n;
    vector<ll> Vect(n);
    for(ll &x : Vect)
        cin >> x;
    for(i=0;i<(1<<n);++i) // n = 2 00 01 10 11
    {
        ll angle = 0;
        for(j=0;j<n;j++)
        {
            if(i&(1<<j)) // i = 01 j = 0 01&01 1 j=1 01&&10 0
                angle += Vect[j];
            else angle -= Vect[j];
        }
        if(angle%360==0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}