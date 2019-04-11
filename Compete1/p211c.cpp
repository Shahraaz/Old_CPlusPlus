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

int main(){
    fast;
    string str,str1;
    cin >> str;
    ll i,ccurr=0,length=str.length();
    char curr = str[0];
    str += " ";
    bool mark = false;
    for(i=0;i<=length;i++){
        if(str[i]==curr)
            ccurr++;
        else{
            if(ccurr>=2) str1 += curr;
            str1 += curr;
            curr = str[i];
            ccurr = 1;
        }
    }
    curr = str[0];
    ccurr = 0;
    str = "";
    str1 += " ";
    mark = false;
    // cout << str1 ;
    for(i=0;i<str1.length();i++){
        if(str1[i]==curr)
            ccurr++;
        else{
            if(ccurr==2){
                if(mark){
                    mark = false;
                }
                else{ 
                    str += curr;
                    mark = true;
                }
            }
            else mark = false;
            str += curr;
            curr = str1[i];
            ccurr = 1;
        }
    }
    cout << str;
    return 0;
}