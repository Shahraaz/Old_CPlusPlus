#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, m, k, i, q, j, fun, nomads=0;
    cin >> n >> m;
    int arr[m+1],temp[m+1],arr2[n+1];
    for(i=1;i<=m;i++)    
        arr[i] = 0;
    for(i=0;i<n;i++)    
        arr2[i] = 0;
    int key = 1;
    for(i=0;i<n;i++){
        cin >> q;
        if(q==0)
            continue;
        arr2[i] = 1;
        for(j=0;j<q;j++)
            cin >> temp[j];
        sort(temp,temp+q);
        if(arr[temp[0]])
            fun = arr[temp[0]];
        else fun = arr[temp[0]] = key++;
        for(j=0;j<q;j++){
            int morefun = arr[temp[j]];
            if(morefun)
                for(k=0;k<=m;k++)
                    if(arr[k]==morefun)
                        arr[k] = fun;
            arr[temp[j]] = fun;
        }
    }
    int distinct = 0,value = -1;
    sort(arr+1,arr+m+1);
    for(i=1;i<=m;i++){
    //     cout << arr[i] << ' ';
        if(arr[i] && arr[i]!=value){
            value = arr[i];
            distinct++;
        }
    }
    nomads = 0;
    for(i=0;i<n;i++)
        if(!arr2[i])
            nomads++;
//    cout << '\n';
  //  cout << distinct << '\n' << nomads << '\n';
    if(distinct>1)
        cout << distinct+nomads-1 ;
    else 
        cout << nomads;
    return 0;
}