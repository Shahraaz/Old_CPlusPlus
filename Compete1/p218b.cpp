//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

vector<int> prime;
int main(){
    fast;
    ll a,b,count = 0,psize=prime.size(),c1,c2;
    cin >> a >> b;
    if(a==b) cout << 0;
    else{
        c1 = 0,c2 = 0;
        while(a%2==0){
            a/=2;
            c1++;
        }
        while(b%2==0){
            b/=2;
            c2++;
        }
        count += abs(c1-c2);  
        c1 = 0,c2 = 0;
        while(a%3==0){
            a/=3;
            c1++;
        }
        while(b%3==0){
            b/=3;
            c2++;
        }
        count += abs(c1-c2);  
        c1 = 0,c2 = 0;
        while(a%5==0){
            a/=5;
            c1++;
        }
        while(b%5==0){
            b/=5;
            c2++;
        }
        count += abs(c1-c2);  
        if(a==b) cout << count;
        else cout << -1; 
    }
    return 0;
}