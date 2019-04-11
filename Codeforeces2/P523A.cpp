#include<iostream>
using namespace std;
int main(){
    int n,s,count=0;
    cin >> n >> s;
    count = s/n;
    s = s%n;
    if(s) count++;
    cout << count;
    return 0;
}