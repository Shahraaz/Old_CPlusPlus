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

ll rem(string str,ll n){
    ll result=0,length=str.length();
    for(ll i=0;i<length;i++){
        result = result*10 + str[i] - '0';
        result %= n;
    }
    return result;
}

string solve(ll n){
    string str = "1";
    set<ll> Set;
    queue<string> Q;
    Q.push(str);
    while(!Q.empty()){
        str = Q.front();
        // cout << str << ' ';
        Q.pop();
        ll k = rem(str,n); 
        if(k==0)
            return str;
        if(Set.find(k) == Set.end()){
            Q.push(str+"0");
            Q.push(str+"1");
            Set.insert(k);
        }    
    }
    return str;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.exceptions(cin.failbit);
    ll t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << '\n';
    }   
    return 0;
}