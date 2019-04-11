#include<iostream>
#include<string>
using namespace std;
int main(){
    int Hash[26]={0},i,odd;
    string str;
    cin >> str;
    for(i=0;i<str.length();i++)
        Hash[str[i]-'a']++;
    for(i=odd=0;i<26;i++)
        odd += Hash[i]&1;
    if(odd<=1) cout << "First";
    else if(odd&1) cout << "First";
    else cout << "Second";    
    return 0;
}