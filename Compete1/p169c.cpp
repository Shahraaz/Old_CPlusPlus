//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    ll i, n, q, l, r;
    cin >> n >> q;
    vector<ll> Vect(n+1,0),Hash(n+2,0);
    for(i=1;i<=n;i++)
        cin >> Vect[i];
    while(q--){
        cin >> l >> r;
        Hash[l]++;Hash[r+1]--;
    }    
    for(i=1;i<=n;i++)
        Hash[i] += Hash[i-1];
    // for(i=1;i<=n;i++) cout << Hash[i] << ' ';cout << '\n';
    sort(Vect.begin()++,Vect.end()); 
    sort(Hash.begin()++,Hash.end());
    ll sum = 0;
    // for(i=1;i<=n;i++) cout << Vect[i] << ' ';cout << '\n'; 
    // for(i=1;i<=n;i++) cout << Hash[i+1] << ' ';cout << '\n';
    for(i=1;i<=n;i++)
        sum += Hash[i+1]*Vect[i];
    cout << sum;
    return 0;
}