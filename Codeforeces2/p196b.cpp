#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b==0 ? a : gcd(b,a%b);
}
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(b*c<=a*d){
        int g = gcd(a*d-b*c,a*d);
        cout << (a*d-b*c)/g << '/' << a*d/g;
    }
    else{
        int g = gcd(-a*d+b*c,b*c);
        cout << (-a*d+b*c)/g << '/' << b*c/g;
    }
    return 0;
}