#include<iostream>
using namespace std;

long long int RZero(long long int a){
    long long int Answer=0;
    for(;a;a /= 10)
        if(a%10!=0) Answer = Answer*10 + a%10;
    for(a=0;Answer;Answer /= 10)
        a = a*10 + Answer%10;
    return a;
}

int main(){
    long long int a,b,sum1,sum2;
    cin >> a >> b;
    sum1 = a+b;
    a =RZero(a);b=RZero(b);sum1=RZero(sum1);
    sum2 = a+b;
    if(sum1==sum2) cout << "YES";
    else cout << "NO";
    return 0;
}