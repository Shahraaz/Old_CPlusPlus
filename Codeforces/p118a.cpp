#include<iostream>
#include<string>
using namespace std;
int main(){
    string d1,d2;
    cin >> d1 >> d2; 
    if(d1.length()!=d2.length()) cout << "NO";
    else{
        char c[26]={0},c1[26]={0};
        int i,diff=0;
        for(i=0;i<d1.length();++i){
            if(d1[i]!=d2[i]){
                diff++;
                if(diff>2){
                    cout << "NO";
                    return 0;
                }
            }
            c[d1[i]-'a']++;
            c1[d2[i]-'a']++;
        }
        if(diff==2){
            for(i=0;i<26;i++)
                if(c[i]!=c1[i]){
                    cout << "NO";
                    return 0;
                }
            cout << "YES";
        }
        else if(diff==0){
            for(i=0;i<26;i++)
                if(c[i]>2){
                    cout << "YES";
                    return 0;
                }
            cout << "NO";
        }
        else cout << "NO";
    }
    return 0;
}