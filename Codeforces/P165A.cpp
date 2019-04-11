#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b){
    return (b==0)? a : gcd(b,a%b);
}
int main(){
    int t,a;
    cin >> t;
    while(t--){
        cin >> a;
        if(gcd(360,180-a)==180-a) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}