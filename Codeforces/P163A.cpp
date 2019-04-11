#include<iostream>
#include<string>
using namespace std;
int main(){
    string temp;
    int answer=0,i,length;
    cin >> length;
    cin >> temp;
    length--;
    for(i=0;i<length;i++)
        if(temp[i]==temp[i+1]) answer++;
    cout << answer;
    return 0;
}