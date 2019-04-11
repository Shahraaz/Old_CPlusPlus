#include <iostream>
#include <cstdio>
#include <string>
#include <array>
using namespace std;
array<array<bool,10001>,100001> c8;
array<array<bool,10001>,100001> c7;
array<array<bool,10001>,100001> c6;
array<array<bool,10001>,100001> c5;
array<array<bool,10001>,100001> c4;
array<array<bool,10001>,100001> c3;
array<array<bool,10001>,100001> c2;
array<array<bool,10001>,100001> c1;
array<array<bool,10001>,100001> c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t,q,a,b,l1,l2,i,j;
    string s1,s2;
    cin >> t ;
    while(t--){
        cin >> s1 ;
        cin >> s2;
        l1 = s1.length()+1;
        l2 = s2.length()+1;
        if(s1[0]=='0' || s2[0]=='0')
            c[1][1] = true;
        else c[1][1] = false;
        for(i=2;i<l1;++i)
            if(s1[i-1]=='0')
                c[1][i] = true;
            else if(c[1][i-1])
                c[1][i] = false;
            else c[1][i] = true;
        for(i=2;i<l2;++i)
            if(s2[i-1]=='0')
                c[i][1] = true;
            else if(c[i-1][1])
                c[i][1] = false;
            else c[i][1] = true ;
        for(i=2;i<l1;++i)
            for(j=2;j<l2;++j)
                if( c[j][i-1] & c[j-1][i] )
                    c[j][i] = false;
                else c[j][i] = true;
        cin >> q;
        while(q--){
            cin >> a >> b;
            cout << c[a][b] ;
        }
        cout << '\n';
    }
    return 0;
}