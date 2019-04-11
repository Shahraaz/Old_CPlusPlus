#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double n,x,y;
    cin >> n >> x >> y;
    if(n*y/100.0-x<0) cout << 0;
    else cout << ceil(n*y/100-x);
    return 0;
}