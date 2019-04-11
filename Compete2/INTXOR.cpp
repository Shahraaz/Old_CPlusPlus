//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;
vector<ll> result;
ll shift;
ll ask1(ll a,ll b ,ll c){
    cout << 1 << ' ' << a << ' ' << b << ' ' << c <<  endl;
    ll res;
    cin >> res;
    return res;
}
void rec4(ll n){
    if(n==0) return;
    ll t1,t2,t3,t4,t5,t6,t7,t8,t9;
    t1 = ask1(shift+1,shift+2,shift+3);
    t2 = ask1(shift+2,shift+3,shift+4);
    t3 = ask1(shift+3,shift+4,shift+1);
    t4 = ask1(shift+4,shift+1,shift+2);
    t6 = t1^t2;
    t7 = t3^t2;
    t8 = t3^t4;
    t9 = t1^t4;
    result.pb(t1^t8);
    result.pb(t2^t9);
    result.pb(t3^t6);
    result.pb(t4^t7);
    shift += 4;
    rec4(n-4);
}
void solve5(){
    ll t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
    t1 = ask1(shift+1,shift+2,shift+3);
    t2 = ask1(shift+2,shift+3,shift+4);
    t3 = ask1(shift+3,shift+4,shift+5);
    t4 = ask1(shift+4,shift+5,shift+1);
    t5 = ask1(shift+5,shift+1,shift+2);
    t6 = t1^t2;
    t7 = t3^t2;
    t8 = t3^t4;
    t9 = t5^t4;
    t10 = t5^t1;
    result.pb(t5^t7);
    result.pb(t1^t8);
    result.pb(t2^t9);
    result.pb(t3^t10);
    result.pb(t4^t6);
    shift += 5;
}
void solve7(){
    ll t1,t2,t3,t4,t5,t6,t7,t8;
    t1 = ask1(shift+1,shift+2,shift+3);
    t2 = ask1(shift+2,shift+3,shift+4);
    t3 = ask1(shift+3,shift+4,shift+5);
    t4 = ask1(shift+4,shift+5,shift+6);
    t5 = ask1(shift+5,shift+6,shift+7);
    t6 = ask1(shift+6,shift+7,shift+1);
    t7 = ask1(shift+7,shift+1,shift+2);
    t8 = t1^t2^t3^t4^t5^t6^t7;
    result.pb(t8^t2^t5);
    result.pb(t8^t3^t6);
    result.pb(t8^t4^t7);
    result.pb(t8^t5^t1);
    result.pb(t8^t6^t2);
    result.pb(t8^t7^t3);
    result.pb(t8^t1^t4);
    shift += 7;
}
void solve(ll n){
    if(n%4==3){
        solve7();
        n -= 7;
    }
    else if(n%4==2){
        solve5();
        solve5();
        n -= 10;
    }
    else if(n%2==1){
        solve5();
        n -= 5;
    }
    rec4(n);
}
int main(){
    fast;
    ll t,n,i;
    cin >> t;
    while(t--){
        result.clear();
        shift = 0;
        cin >> n;
        solve(n);
        cout << 2 << ' ';
        for(i=0;i<n;i++)
            cout << result[i] << ' ';
        cout << endl;
        cin >> i;
        if(i==-1) return 0;
    }
    return 0;
}