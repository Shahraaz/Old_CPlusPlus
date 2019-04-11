#include<iostream>
#include<string>
using namespace std;
int main(){
    string input,output,temp = " ";
    cin >> input;
    int i,length=input.length(),start=0;
    input += "AB";
    for(i=0;i<length;i++){
        if(input[i]=='W' && input[i+1]=='U' && input[i+2]=='B'){
            if(i==length-3) break;
            if(start==1)
                cout << ' ';
            i += 2;
        }
        else{
            cout << input[i];
            start = 1;
        }
    }
    return 0;
}