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

ll n;
vector<ll> factors;
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

long long gcd(long long a,long long b){
    return b==0 ? a : gcd(b,a%b);
}

vector< pair<ll,ll> > answer;

bool fun(ll i,ll k,ll sum){
    if(sum==(n-1)){ 
        cout << "YES\n";
        return true;
    }
    if(sum>(n-1)) return false;
    if(i==k)
        return false;    
    for(ll j=0;j<n/factors[i];j++){
        if(fun(i+1,k,sum)){
            ll gcd1 = 1 ; //gcd(j*factors[i],n); 
            if(j>1)
                answer.pb(mp(j*(factors[i])/gcd1,n/gcd1));
            return true;
        }
        sum += factors[i];
        if(fun(i+1,k,sum)){
            ll gcd1 = 1 ;//gcd((j+1)*factors[i],n);
            answer.pb(mp((j+1)*(factors[i])/gcd1,n/gcd1));
            return true;
        }
    }
    return false;
}

int main(){
    fast;
    Seive();
    n = 25;
    while(n--){
        factors.clear();answer.clear();
    ll n1 = n;
    for(ll i=0;i<prime.size() && prime[i]<n1;i++)
        if(n1%prime[i]==0){ 
            factors.pb(prime[i]);
        }
    if(fun(0,factors.size(),0)){
        cout << "n = "<<n << '\n';
        cout << answer.size() << '\n';
        for(ll i=0;i<answer.size();i++)
            cout << answer[i].f << ' ' << answer[i].s << '\n';
    }
    // else  cout << "NO";
    }
    return 0;
}