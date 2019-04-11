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
    ll n,m,k=0,i;
    string str;
    cin >> n;
    cin >> str;
    vector<bool> Hashstr(26,false);
    vector<ll> HashTotal(26,0);
    for(i=0;i<n;i++)
        if(str[i]!='*')
            Hashstr[str[i]-'a'] = true;
    cin >> m;
    while(m--){
        bool flag = true;
        string str2;
        cin >> str2;
        vector<bool> HashHere(26,false);
        for(i=0;i<n;i++){
            if(str[i]=='*'){
                if(Hashstr[str2[i]-'a']){
                    flag = false;
                    break;
                }
                else    HashHere[str2[i]-'a'] = true;
            }
            else if(str2[i]==str[i]){

            }
            else{
                flag = false;
                break;
            } 
        }
        if(flag){
            k++;
            for(i=0;i<26;i++)
                HashTotal[i] += HashHere[i];
        }
    }
    ll totol = 0;
    for(i=0;i<26;i++)
        if(HashTotal[i]==k) totol++;
    cout << totol ;
    return 0;
}