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
string fun(string temp){
    string str2 = "";
    for(ll i=0;i<temp.length();i++){
        if(temp[i]=='u')    str2 += "oo";
        else if(temp[i]=='h') str2 += "kh";
        else str2 += temp[i];
    }
    temp = "";
    for(ll i=0;i<str2.length();){
        if(str2[i]=='o'){
            if((i+1)!=str2.length()){
                if(str2[i+1]=='o'){ 
                    temp += 'u';
                    i++;i++;
                }
                else{ 
                    temp += 'o';
                    i++;
                }
            }
            else{ 
                temp += 'o';
                i++;
            }
        }
        else if(str2[i]=='k'){
            ll count = 0,j;
            for(j=i;j<str2.length();j++)
                if(str2[j]=='k') count++;
                else break;
            if(j!=str2.length()){
                if(str2[j]=='h'){    
                    temp += 'h';
                    i = j+1;
                }
                else{
                    for(ll k=0;k<count;k++)
                        temp += 'k';
                    i = j;
                }
            }
            else{
                for(ll k=0;k<count;k++)
                        temp += 'k';
                i = j;
            }
        }
        else{
            temp += str2[i];
            i++;
        }
    }
    // cout << temp << '\n';
    return temp;
}
int main(){
    fast;
    ll n;
    cin >> n;
    set<string> names;
    while(n--){
        string str;
        cin >> str;
        names.insert(fun(str));
    }
    cout << names.size();
    return 0;
}