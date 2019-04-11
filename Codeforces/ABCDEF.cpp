#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int *arr = new int[n],i,j,k;
    for(i=0;i<n;i++)
        cin >> arr[i];
    vector<int> M1,M2;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<n;k++){
                int temp = arr[i]*arr[j] + arr[k];
                M1.push_back(temp);
                if(arr[k])
                    M2.push_back((arr[i]+arr[j])*arr[k]);
            }
    long int count = 0;
    sort(M1.begin(),M1.end());
    sort(M2.begin(),M2.end());
    auto it = M1.begin(),endin = M1.end();
    int c1 = 1,value = *it;
    for(it++;it!=endin;it++){
        if(*it==value) c1++;
        else{
            auto low = lower_bound(M2.begin(),M2.end(),value);
            if(low!=endin && *low==value){
                auto up = upper_bound(M2.begin(),M2.end(),value);
                count += c1*(up-low);
            }
            value = *it;
            c1=1;
        }
    }
    auto low = lower_bound(M2.begin(),M2.end(),value);
    if(low!=endin && *low==value){
        auto up = upper_bound(M2.begin(),M2.end(),value);
        count += c1*(up-low);
    }
    cout << count;
    return 0;
}