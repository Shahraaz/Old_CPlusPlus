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

vector<int> prime;
void Seive(){
    vector<bool> seive(1000000,true);
    seive[0]=seive[1]=false;
    int i;
    for(i=3;i<1000;i+=2)
        if(seive[i])
            for(int j=i*i;j<1000000;j+=i)
                seive[j] = false;
    prime.push_back(2);
    for(i=3;i<1000000;i+=2)
        if(seive[i]) prime.push_back(i);
}

int main(){
    fast;
    Seive();
    ll n,m,i,j,x,y,min=10000000000;
    cin >> n >> m;
    vector< vector<ll> > Vect(n,vector<ll>(m,0));
    vector<ll> Vect1(m,0);
    for(i=0;i<n;i++){
        ll sum = 0;
        for(j=0;j<m;j++){
            cin >> x;
            y = *lower_bound(prime.begin(),prime.end(),x) - x;
            sum += y;
            Vect1[j] += y; 
        }
        if(sum<min) min = sum;
    }
    for(i=0;i<m;i++) 
        if(Vect1[i]<min) min = sum;;
    cout << min;
    return 0;
}