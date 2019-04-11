#include<iostream>
using namespace std;
int main(){
    int maxocurence=0,maxh=-1,maxm=-1,occurence=0,min=-1,hour=-1,n,x,y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        if(x==hour&&y==min) occurence++;
        else{
            occurence = 1;
            min = y;
            hour = x;
        }
        if(occurence>=maxocurence){
            maxocurence = occurence;
            maxh = hour;
            maxm = min;
        }
    }
    cout << maxocurence;
    return 0;
}