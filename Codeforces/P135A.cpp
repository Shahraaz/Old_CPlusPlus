#include<iostream>
#include<string>
using namespace std;
int gcd(int a,int b){
    return (b == 0) ? a : gcd(b,a%b);
}
int main(){
    int k,ctr=0,l;
    cin >> k;
    string str;
    cin >> str;
    int i,j,length=str.length(),arr[26]={0};
    for(i=0;i<length;i++)
        arr[str[i]-'a']++;
    for(i=0;i<26;i++)
        if(arr[i]==0);
        else if(gcd(arr[i],k)==k){
            ctr++;
        }
        else{
            cout << -1;
            return 0;
        }
    for(i=0;i<k;i++){
        for(j=0;j<26;j++)
            if(arr[j]) 
                for(l=0,length=arr[j]/k;l<length;l++)
                    cout << char(j+97);
    }
    return 0;
}