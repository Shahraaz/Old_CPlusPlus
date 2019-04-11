#include<iostream>
#include<vector>
using namespace std;
long long int fun(int n){
    if(n&1)
        return -(long long)(n+1)*(n+1)/4 + (long long)(n/2)*(n/2+1);
    return n + fun(n-1);
}
int main(){
    int q,l,r,mark;
    cin >> q;
    while(q--){
        cin >> l >> r ;
        cout << fun(r) - fun(l-1) << '\n';
    }
    return 0;
}