#include<iostream>
#include<string>
using namespace std;
typedef long long int ll;

ll count = 0;

void Fun(string temp){
    if(temp.length()<2) return;
    ll i,integer = 0,length=temp.length();
    for(i=0;i<length;i++)
        integer = integer + (temp[i]-'0') ;
    temp = to_string(integer);
    count++;
    Fun(temp);
}


int main(){
    string temp;
    cin >> temp;
    Fun(temp);
    cout << count;
    return 0;
}