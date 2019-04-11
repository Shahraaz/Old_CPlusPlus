#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int i, n , k , countalph[26] = {0},mincount=0,length = 0;
    cin >> n >> k;
    string str;
    cin >> str ;
    for(i=0;i<n;i++)
        countalph[str[i]-'A']++;
    mincount = countalph[0];
    for(i=1;i<k;i++)
        mincount = min(mincount,countalph[i]);
    length = mincount*k;
    for(i=k;i<26;i++)
        length += countalph[i];
    cout << length ;
    return 0;
}