#include<iostream>
#include<string>
using namespace std;
int Fun(string &temp,int length){
    int i,counter=0;
    for(i=0;i<length;i++)
        if(temp[i]=='S') return 0;
    for(i=0;i<length;i++)
        if(temp[i]=='.'){
            temp[i]='_';
            counter++;
        }
    return counter;
}
int main(){
    int i,r,c,j,eaten=0;
    cin >> r >> c;
    string temp[r];
    for(i=0;i<r;i++){
        cin >> temp[i];
        eaten += Fun(temp[i],c);
    }
    for(i=0;i<c;i++){
        for(j=0;j<r;j++)
            if(temp[j][i]=='S') break;
        if(j==r)
            for(j=0;j<r;j++)
                if(temp[j][i]=='.'){
                    temp[j][i] = '_';
                    eaten++;
                }
    }
    cout << eaten;
    return 0;
}