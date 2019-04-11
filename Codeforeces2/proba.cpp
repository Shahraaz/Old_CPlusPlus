#include<iostream>
#include<cmath>
using namespace std;
int fun(int x){
    int i = 0;
    for( ;x;x/=2)
        i++;
    return i;
}
int main(){
    int i;
    cin >> i;
    cout << fun(i) ;
    return 0;
}