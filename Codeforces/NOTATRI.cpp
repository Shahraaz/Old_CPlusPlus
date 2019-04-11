#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cout.tie(NULL);
    int n;
    while(1){
        cin >> n;
        if(n==0) return 0;
        vector<int> V(n);
        int i,j,count=0;
        for(i=0;i<n;i++)
            cin >> V[i];
        sort(V.begin(),V.end());
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++){
                int min = V[j] - V[i],max = V[j] + V[i];
                auto low = lower_bound(V.begin()+j+1,V.end(),min);
                auto up = upper_bound(V.begin()+j+1,V.end(),max);
                count += up-low;
            }
        cout << (n-2)*(n-1)*n/6-count << '\n';
    }
}