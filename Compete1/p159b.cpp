//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

int main(){
    fast;
    ll n,m,i,j,sc1=0,sc2=0,Sc1=0,Sc2=0,prev=0;
    cin >> n >> m;
    i = n; 
    j = m;
    bool turn = true;
    for(;i||j;){
        if(turn){
            if(prev==0){
                i--;
                prev = 1;
            }
            else if(prev==1){
                if(i){
                    i--;
                    sc1++;
                }
                else{
                    j--;
                    sc2++;
                    prev = 2;
                }
            }
            else{
                if(j){
                    j--;
                    sc1++;
                }
                else{
                    i--;
                    sc2++;
                    prev = 1;
                }
            }
            turn = false;
        }
        else{
            if(prev==1){
                if(j){
                    j--;
                    sc2++;
                    prev = 2;
                }
                else{
                    i--;
                    sc1++;
                }
            }
            else{
                if(i){
                    i--;
                    sc2++;
                    prev = 1;
                }
                else{
                    j--;
                    sc1++;
                }
            }
            turn = true;
        }
    }
    Sc1 = sc1;Sc2 = sc2;
    sc1 = 0; sc2 = 0;
    prev=0;
    turn = true;
    for(i=m,j=n;i||j;){
        if(turn){
            if(prev==0){
                i--;
                prev = 1;
            }
            else if(prev==1){
                if(i){
                    i--;
                    sc1++;
                }
                else{
                    j--;
                    sc2++;
                    prev = 2;
                }
            }
            else{
                if(j){
                    j--;
                    sc1++;
                }
                else{
                    i--;
                    sc2++;
                    prev = 1;
                }
            }
            turn = false;
        }
        else{
            if(prev==1){
                if(j){
                    j--;
                    sc2++;
                    prev = 2;
                }
                else{
                    i--;
                    sc1++;
                }
            }
            else{
                if(i){
                    i--;
                    sc2++;
                    prev = 1;
                }
                else{
                    j--;
                    sc1++;
                }
            }
            turn = true;
        }
    }
    if(Sc1>sc1)
        cout << Sc1 << ' ' << Sc2;
    else cout << sc1 << ' ' << sc2;
    return 0;
}