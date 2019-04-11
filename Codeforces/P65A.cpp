#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    string temp;
    cin >> n;
    while(n--){
        cin >> temp;
        if(temp.length()>10)
            cout << temp[0] << temp.length()-2 << temp[temp.length()-1] << '\n';
        else cout << temp << '\n';
    }
    return 0;
}