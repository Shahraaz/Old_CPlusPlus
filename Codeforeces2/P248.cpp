#include<iostream>
using namespace std;
int gcd(int a,int b){
    return (b==0)? a : gcd(b,a%b);
}
int main(){
    int n,i,temp,c100=0,c200=0;
    cin >> n;
    i=n;
    while(n--){
        cin >> temp;
        if(temp==100) c100++;
        else c200++;
    }
    n=i;
    if(n<2) cout << "NO";
    else if(c100==0 && (c200&1)==1 ) cout << "NO";
    else if( gcd((c100*100+c200*200),200)==200) cout << "YES";
    else cout << "NO";
    return 0;
}