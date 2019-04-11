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
ll x,n,c,low,high,answer,coins=1000;
ll query1(ll q){
    cout << "1 " << q << endl;
    cin >> q;
    coins--;
    return q;
}
ll solver(ll start,ll end){
    // cout << "(start,end)--(" << start << ',' << end << ')' << endl;
    // cout << "Coins " << coins << endl;    
    if(coins>=(end-start+c)){
        for(;start<end;start++)
            if(query1(start)==1){
                cout << "2" << endl;
                cout << "3 " << start << endl;
                return start;
            }
        // cout << "Coins " << coins << endl;
        cout << "3 " << start << endl;
        return start;
    }
    ll step = (end-start)/5;
    if(query1(start+step)==1){
        coins -= c;
        cout << 2 << endl;
        return solver(start,start+step);
    }
    else if(query1(start+2*step)==1){
        coins -= c;
        cout << 2 << endl;
        return solver(start+step+1,start+2*step);
    }
    else if(query1(start+3*step)==1){
        coins -= c;
        cout << 2 << endl;
        return solver(start+2*step+1,start+3*step);
    }
    else if(query1(start+4*step)==1){
        coins -= c;
        cout << 2 << endl;
        return solver(start+3*step+1,start+4*step);
    }
    else return solver(start+4*step,end);
}
int main(){
    fast;
    cin >> n >> c;
    solver(1,n);
    return 0;
}