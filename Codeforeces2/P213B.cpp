#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int i,*arr = new int[n];
    int isfibo = 1,maxlen=2,len=2;
    for(i=0;i<n;i++)    cin >> arr[i];
    if(n==1) cout << 1;
    else if(n==2) cout << 2;
    else{
       for(i=n-3;i>=0;i--)
            if((arr[i]+arr[i+1])==(arr[i+2]))
                len++;
            else{
                if(maxlen<len) maxlen = len;
                len = 2;
            }
        if(maxlen<len) maxlen = len;
        cout << maxlen;
    }
    return 0;
}