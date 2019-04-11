#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,m,curr=1,temp;
    unsigned long long steps = 0;
    cin >> n >> m;
    while(m--){
        cin >> temp;
        if(temp>=curr)
            steps += temp - curr;
        else
            steps += n - curr + temp;
        curr = temp;
    }
    cout << steps;
    return 0;
}