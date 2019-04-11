#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,t,a,index,i,temp;
    float min,curr;
    cin >> n >> t >> a;
    cin >> temp;
    index = 1;
    min = abs(a-t+0.006*temp);
    for(i=2;i<=n;i++){
        cin >> temp;
        curr = abs(a-t+0.006*temp);
        if(curr<min){
            min = curr;
            index = i;
        }
    }
    cout << index;
    return 0;
}