#include<iostream>
#include<string>
using namespace std;
int main(){
    string temp;
    cin >> temp;
    int i,length = temp.length();
    temp += "AB";
    for(i=0;i<length;i++){
        if(temp[i]=='1' && temp[i+1]=='4' && temp[i+2]=='4')    i += 2;
        else if(temp[i]=='1' && temp[i+1]=='4')    i += 1;
        else if(temp[i]!='1'){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}