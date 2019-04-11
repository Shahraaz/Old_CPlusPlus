#include<iostream>
using namespace std;
int main(){
    int n,k,t,f,max,curr;
    cin >> n  >> k;
    cin >> f >> t;
    n--; 
    if(t<k) max = f;
    else max  = f - t + k;
    while(n--){
        cin >> f >> t;
        if(t<k) curr = f;
        else curr  = f - t + k;
        if(curr > max) max = curr;
    }
    cout << max ;
    return 0;
}