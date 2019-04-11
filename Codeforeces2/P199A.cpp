#include<iostream>
using namespace std;
int main(){
    int i,temp,n,arr[8]={0},c124=0,c126=0,c136=0;
    cin >> n;
    while(n--){
        cin >> temp;
        arr[temp]++;
    }
    if(arr[7]==0 && arr[5]==0){
        if(arr[1]>=arr[2] && arr[2]>=arr[4]){
            arr[1] -= arr[4];
            arr[2] -= arr[4];
            c124 = arr[4];
        }
        else{
            cout << -1 ;
            return 0;
        }
        if(arr[1]>=arr[2] && arr[6]>=arr[2]){
            arr[1] -= arr[2];
            arr[6] -= arr[2];
            c126 = arr[2];
        }
        else{
            cout << -1;
            return 0;
        }
        if(arr[1]==arr[3] && arr[3]==arr[6])
            c136 = arr[1];
        else{
            cout << -1;
            return 0;
        }
    }
    else    
        cout << -1;
    for(i=0;i<c124;i++) cout << "1 2 4\n";
    for(i=0;i<c126;i++) cout << "1 2 6\n";
    for(i=0;i<c136;i++) cout << "1 3 6\n";
    return 0;
}