#include<iostream>
#include<string>
using namespace std;
int Value(string temp){
    int i;
    for(i=0;i<3;i++)
        if(temp[i]=='+')
            return 1;
        else if(temp[i]=='-')
            return -1;
    return 0;
}
int main(){
    int i,answer=0;
    string temp;
    cin >> i;
    while(i--){
        cin >> temp;
        answer += Value(temp);
    }
    cout << answer;
    return 0;
}