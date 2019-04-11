#include<iostream>
using namespace std;
int main(){
    int i,index,n,min=1<<30,mincount=0,temp;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> temp;
        if(temp<min){
            index = i;
            min = temp;
            mincount = 1;
        }
        else if(temp==min) mincount++;
    }
    if(mincount>1) cout << "Still Rozdil";
    else cout << index ;
    return 0;
}