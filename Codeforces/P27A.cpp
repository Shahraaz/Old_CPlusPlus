#include<iostream>
using namespace std;
int main(){
    int n,temp,i;
    bool arr[3002]={false};
    cin >> n;
    while(n--){
        cin >> temp;
        arr[temp] = true; 
    }
    for(i=1;i<3002;i++)
        if(!arr[i]){
            cout << i;
            break;
        }
    return 0;
}