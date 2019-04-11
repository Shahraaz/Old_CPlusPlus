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
    ll n,k,i,sum=0;
    cin >> n >> k;
    vector<ll> arr(n+1),Vect(n-k+1);
    for(i=0;i<n;i++)
        cin >> arr[i];
    for(i=0;i<k;i++)
        sum += arr[i];
    Vect[0] = sum;
    for(i=1;i<=n-k;i++){
        Vect[i] = Vect[i-1] + arr[i+k-1] - arr[i-1];
    }
    ll maxmax = -1,l=0,r=-1,l1 = 0;
    for(i=0;i<=n-2*k;i++){
        if(Vect[i]>Vect[l1]){
            l1 = i;
        }
        if(Vect[i+k]+Vect[l1]>maxmax){
            r = i + k;
            l = l1;
            maxmax = Vect[i+k]+Vect[l1];
        }
    }
    cout << l + 1 << ' ' << r + 1;
    return 0;
}