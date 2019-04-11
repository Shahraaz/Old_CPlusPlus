#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> Op,Operands,Paranthesis;
bool isoperator(char c){
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return false;
    return true;
}
void print(string Str,int i, int n){
    if(i==n)
        return;
    while(i<n){
        if(Str[i]=='(')
            Paranthesis.push('(');
        else if(Str[i]==')'){
            
            return ;
        }
        else{ 
            if(isoperator(Str[i]))
                if(Op.empty()) Op.push(Str[i]);
                else{
                    cout << Operands.top();
                    cout << Op.top();
                    Op.pop();
                    Operands.pop();
                    Op.push(Str[i]);
                }
            else{
                if(Operands.empty())
                    cout << Str[i];
                Operands.push(Str[i]);
            }
        }
        i++;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string temp;
        cin >> temp;
        print(temp,0,temp.length());
    }
    return 0;
}