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
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    string str1,str2;
    cin >> str1 >> str2;
    if(str1.length()!=str2.length()) cout << "NO";
    else if(str1.length()==1) cout << (str1==str2 ? "YES" : "NO");
    else{
        bool mark1 = false;mark2=false;
        ll i,length = str1.length();
        for(i=0;i<length;i++){
            if(str1[i]=='1'){
                mark1 = true;
                break;
            }
        }
        for(i=0;i<length;i++){
            if(str2[i]=='1'){
                mark2=true;
                break;
            }
        }
        if(mark1==mark2) cout << "YES";
        else cout << "NO";
    }
    return 0;
}