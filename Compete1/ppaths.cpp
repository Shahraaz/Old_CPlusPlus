//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=0;i<(b);++i)
#define trav(a,x) for(auto& a : v)
#define all(x) x.begin(),x.end()
const long long mod = 1000000007;

vector<bool> Isprime(10001,true);
void seive(){
    Isprime[0] = Isprime[1] = false;
    for(ll i=4;i<=10000;i+=2)
        Isprime[i] = false;
    for(ll i=3;i*i<=10000;i+=2)
        if(Isprime[i]){
            for(ll j=i*i;j<=10000; j+=i)
                Isprime[j] = false;
        }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
    seive();
    ll t;
    cin >> t;
    while(t--){
        ll a , b;
        cin >> a >> b;
        if(a==b){
            cout << 0 << '\n';
            continue;
        }
        queue< pair<ll,ll> > Q;
        vector<bool> visited(10001,0);
        visited[a] = true;
        Q.push(mp(a,0));
        bool flag = true;
        while((!Q.empty()) && flag){
            pair< ll,ll > curr = Q.front();
            Q.pop();
            ll temp = (curr.f)%1000;
            for(ll i=1;(i<10) && flag;i++){
                // cout << i*1000+temp << ' '; 
                if(Isprime[i*1000+temp] && !visited[i*1000+temp]){
                    if((i*1000+temp)==b){
                        cout << curr.s + 1 << '\n';
                        flag = 0;
                        break;
                    }
                    Q.push(mp(i*1000+temp,curr.s+1));
                    visited[i*1000+temp] = true;
                }
            }
            temp = (curr.f)/1000*1000 + (curr.f)%100;
            for(ll i=0;(i<10) && flag;i++){
                    // cout << i*100+temp << ' '; 
                if(Isprime[i*100+temp] && !visited[i*100+temp]){
                    if((i*100+temp)==b){
                        cout << curr.s + 1 << '\n';
                        flag = 0;
                        break;
                    }
                    Q.push(mp(i*100+temp,curr.s+1));
                    visited[i*100+temp] = true;
                }
            }
            temp = (curr.f)/100*100 + (curr.f)%10;
            for(ll i=0;(i<10) && flag;i++){
                    // cout << i*10+temp << ' '; 
                if(Isprime[i*10+temp] && !visited[i*10+temp]){
                    if((i*10+temp)==b){
                        cout << curr.s + 1 << '\n';
                        flag = 0;
                        break;
                    }
                    Q.push(mp(i*10+temp,curr.s+1));
                    visited[i*10+temp] = true;
                }
            }
            temp = (curr.f)/10*10;
            for(ll i=0;(i<10) && flag;i++){
                    // cout << i+temp << ' '; 
                if(Isprime[i+temp] && !visited[i+temp]){
                    if((i+temp)==b){
                        cout << curr.s + 1 << '\n';
                        flag = 0;
                        break;
                    }
                    Q.push(mp(i+temp,curr.s+1));
                    visited[i+temp] = true;
                }
            }
        }
        if(flag)
            cout << "Impossible\n" ;
        // cout << '\n'; 
    }
    return 0;
}