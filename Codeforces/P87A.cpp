#include<iostream>
using namespace std;
int main(){
    int n,a,b,capacity,maxcapacity;
    cin >> n;
    cin >> a >> b;
    maxcapacity = capacity = b;
    n--;
    while(n--){
        cin >> a >> b;
        if(a>capacity) capacity = 0;
        else capacity -= a;
        capacity += b;
        if(capacity>maxcapacity) 
            maxcapacity = capacity;
    }
    cout << maxcapacity;
    return 0;
}