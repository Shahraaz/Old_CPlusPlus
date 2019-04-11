#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int x,y,sum;
    cin >> x >> y;
    sum = abs(x) + abs(y);
    if(x>0 && y>0) cout << "0 " << sum << " " << sum << " 0"; 
    else if(x>0 && y<0) cout << "0 " << -sum << " " << sum << " 0";
    else if(x<0 && y>0) cout << -sum << " 0 0 " << sum;
    else cout << -sum << " 0 0 " << -sum;
    return 0;
}