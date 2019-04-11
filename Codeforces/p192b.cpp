#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i,n,m,x,y;
    cin >> n >> m;
    vector<bool>  Hash(n+1,0);
    for(i=0;i<m;i++){
        cin >> x >> y;
        Hash[x] = Hash[y] = 1;
    }
    for(i=1;i<=n;i++)
        if(Hash[i]==0) break; 
    if(i!=n+1){
        cout << n - 1 << '\n';
        for(int j=1;j<=n;j++)
            if(j==i) continue;
            else cout << i << ' ' << j << '\n'; 
    }
    return 0;
}