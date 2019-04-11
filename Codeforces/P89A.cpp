#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string Rvovel(string temp){
    string temp2;
    int i,length = temp.length();
    for(i=0;i<length;i++){
        if(temp[i]=='a' || temp[i]=='o' || temp[i]=='y' || temp[i]=='e' || temp[i]=='u' || temp[i]=='i')
            continue;
        else temp2 += "." + temp.substr(i,1);
    }
    return temp2;
}

int main(){
    string temp;
    cin >> temp;
    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    temp = Rvovel(temp);
    cout << temp;
    return 0;
}