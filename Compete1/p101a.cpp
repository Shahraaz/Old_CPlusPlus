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

int main(){
    fast;
    string str1,str2,str3;
    ll H1[26] = {0},H2[26] = {0};
    cin >> str1 >> str2 >> str3;
    for(char ch : str1)
        H1[ch-'A']++;
    for(char ch : str2)
        H1[ch-'A']++;
    for(char ch : str3)
        H2[ch-'A']++;
    for(ll i=0;i<26;i++)
        if(H1[i]!=H2[i]){
            cout << "NO";
            return 0;
        }
    cout << "YES"; 
    return 0;
}