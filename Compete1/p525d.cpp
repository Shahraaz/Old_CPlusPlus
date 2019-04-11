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

int q(int c,int d){
    cout << '?' << ' ' << c << ' ' << d << endl;
    int temp;
    cin >> temp;
    return temp;
}

int main(){
    fast;
    int i,a,b,prev,q1,q2;
    a = b = 0; prev = q(a,b);
    for(i=29;i>=0;i--){
        q1 = q(a|(1<<i),b);q2 = q(a,b|(1<<i));
        if(q1==q2){
            if(prev==1)
                a = a|(1<<i);
            else b = b|(1<<i);
            prev = q1;
        }
        else if(q2==1){
            a = a|(1<<i);
            b = b|(1<<i);
        }
    }
    cout << '!' << ' ' << a << ' ' << b << endl;
    return 0;
}