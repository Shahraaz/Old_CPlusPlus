#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int fun(string temp){
    int i = 0,num = 0;
    temp += "0000";
    for(i=1;i<=4;i++)
        num = num*10 + temp[i] - '0';
    return num;
}
int main(){
    int t;
    string temp;
    size_t found;
    cin >> t;
    while(t--){
        cin >> temp;
        found = temp.find('.');
        if(found!=string::npos){
            temp = temp.substr(found);
            int num = fun(temp);
            for(int i=1;i<=10000;i++)
                if((num*i)%10000==0){
                    cout << i;
                    break;
                }
        }
        else cout << 1 ;
        cout << '\n';
    }
    return 0;
}