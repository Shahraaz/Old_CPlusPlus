#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a[3],n,i,j,k;
    vector<long long> Dp(4001,-1e5);
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    set<int> Set;
    Set.insert(a[0]);
    Set.insert(a[1]);
    Set.insert(a[2]);
    for(std::set<int>::iterator it=Set.begin(); it!=Set.end(); ++it)
            Dp[*it]=1;
    for(i=*Set.begin()+1;i<=n;i++)
        for(std::set<int>::iterator it=Set.begin(); it!=Set.end(); ++it)
            if(i-*it>=0) Dp[i] = max(Dp[i],1+Dp[i-*it]);
    for(i=0;i<=n;i++)
        cout << i << ' ' << Dp[i] << '\n';
    cout << Dp[n];
    return 0;
}