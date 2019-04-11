#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *arr = new int[n],i;
    for(i=0;i<n;i++)
        cin >> arr[i];
    int minindex = 0, maxindex = 0;
    for(i=0;i<n;i++)
        if(arr[i]<=arr[minindex])
            minindex = i;
        else if(arr[i]>arr[maxindex])
            maxindex = i;
    if(maxindex < minindex )
        cout << maxindex  + n - 1 - minindex ;
    else cout << maxindex  + n - 2 - minindex ;  
    return 0;
}