#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
#define f first
#define s second
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if((a+b+c)%2==0){
        int sum = (a+b+c)/2;
        if(sum-a<0 || sum - c<0 || sum - b<0)
            cout << "Impossible";
        else cout << sum - c <<' '<< sum - a << ' ' << sum - b;
    }
    else cout << "Impossible";
    return 0;
}