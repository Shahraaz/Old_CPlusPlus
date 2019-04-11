#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,l;
    cin >> n >> m;
    vector<int> Vect(n+1), Dp(n+2,0);
    vector<bool> Hash(100005,false);
    for(i=1;i<=n;i++)
        cin >> Vect[i];
    for(i=n;i>=1;i--){
        if(Hash[Vect[i]])
            Dp[i] = Dp[i+1];
        else{ 
            Dp[i] = Dp[i+1] + 1;
            Hash[Vect[i]] = true;
        }
    }
    while(m--){
        cin >> l;
        cout << Dp[l] << '\n';
    }
    return 0;
}