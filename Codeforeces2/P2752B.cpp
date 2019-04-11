#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    string temp1,temp2;
    cin >> temp1;
    cin >> temp2;
    int i,plus1=0,min1=0,plus2=0,min2=0,ques=0;
    for(i=0;i<temp1.length();i++){
        if(temp1[i]=='+') plus1++;
        else min1++;
        if(temp2[i]=='+') plus2++;
        else if(temp2[i]=='-') min2++;
        else ques++;
    }
    int fact[11];
    fact[0] = 1;
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(10);
    for(i=1;i<=10;i++)
        fact[i] = i*fact[i-1];
    if(plus1 < plus2 || min1 < min2 || ques != plus1 + min1 - plus2 - min2)
        cout  << 0.0;
    else cout  << double(fact[ques]/fact[plus1-plus2]/fact[min1-min2])/(1<<ques);
    // cout << '\n' << fact[ques]<<" " <<fact[plus1-plus2]<<" " <<fact[min1-min2]<<" " <<  (1<<ques) ;
    return 0;
}