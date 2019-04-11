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
    string Vect1[] = {" "," ","a1","b1","b2","a2","a3","b3","b4","a4","a5","b5","b6","a6","a7","a8","b8","b7","c7","c8","d8","d7","d6","c6","c5","d5","d4","c4",
                            "c3","d3","d2","c2","c1","d1","e1","e2","e3","e4","e5","e6","e7","e8","f8","f7","f6","f5","f4","f3","f2","f1","g1","h1","h2","g2",
                            "g3","h3","h4","g4","g5","h5","h6","g6"};
    // cout << sizeof(Vect1)/sizeof(Vect1[0]) << '\n';
    ll n,i;
    /*for(i = 0;i<62;i++){
        cout << i << ' ' << Vect1[i] << '\n';
    }*/
    cin >> n;
    bool mark1=false,mark2=false;
    if(n==62){
        n=61;mark1=true;
    }
    else if(n==63){
        n=61;mark2=true;
    }
    for(i=2;i<=n;i++)
        cout << Vect1[i] << ' ';
    if(mark1)
        cout << "g7 h7 h8";
    else if(mark2)
        cout << "g8 g7 h7 h8";
    else{
        if((n==2) || (n==3) || (n==32) || (n==33) || (n==34) || (n==49))
            cout << "h1 h8";
        else if((n==5) || (n==4) || (n==31) || (n==30) || (n==35) || (n==48))
            cout << "h2 h8";
        else if((n==6) || (n==7) || (n==28) || (n==29) || (n==36) || (n==47) )
            cout << "h3 h8";
        else if((n==9) || (n==8) || (n==27) || (n==26) || (n==37) || (n==46))
            cout << "h4 h8";
        else if((n==10) || (n==11) || (n==24) || (n==25) || (n==38) || (n==45))
            cout << "h5 h8";
        else if((n==12) || (n==13) || (n==23) || (n==22) || (n==39) || (n==44))
            cout << "h6 h8";
        else if((n==14) || (n==17) || (n==18) || (n==21) || (n==40) || (n==43))
            cout << "h7 h8";
        else if((n==15) || (n==16) || (n==19) || (n==20) || (n==41) || (n==42))
            cout << "g8 h8";
        else if((n==50) || (n==53) || (n==54) || (n==57) || (n==58) || (n==61))
            cout << "g8 h8";
        else if((n==51) || (n==52) || (n==55) || (n==56) || (n==59) || (n==60))
            cout << "h7 h8";
    }
    return 0;
}