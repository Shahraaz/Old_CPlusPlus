#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int a,count=0,count1=0,count2=0;
    cin >> a;
    string temp,string1,string2;
    cin >> temp;
    string1 = temp; 
    count = 1;
    count1 = 1;
    a--;
    while(a--){
        cin >> temp;
        if(temp.compare(string1)==0)    count1++;
        else if(count==1){
            string2 = temp;
            count2++;
        }
        else count2++;
    }
    if(count1>count2) cout << string1;
    else cout << string2;
    return 0;
}