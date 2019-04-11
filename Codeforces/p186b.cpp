#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    int m,l,r,dp[(str.length())+1],i;
    dp[0] = 0;
    for(i=1;i<str.length();++i)
        if(str[i]==str[i-1]) dp[i] = dp[i-1] + 1;
        else  dp[i] = dp[i-1];
    cin >> m;
    while(m--){
        cin >> l >> r;
        cout << dp[r-1] - dp[l-1] << '\n';
    }
}