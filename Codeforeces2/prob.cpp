#include<iostream>
#include<algorithm>
using namespace std;
int fun(int *arr,int n, int s){
    sort(arr,arr+n+1);
    int i,median = n/2,steps=0;
    if(arr[median]==s);
    else if(arr[median]>s)
        for(i=median;arr[i]>s&i>=n;i--)
                steps +=  arr[i] - s;
    else if(arr[median]<s)
        for(i=median;arr[i]<s&i<=n;i++)
            steps +=  s - arr[i];
    return steps;
}
int main(){
    int n,s,i;
    cin >> n >> s;
    int *arr = new int[n];
    for(i=0;i<n;i++)
        cin >> arr[i];
    cout << fun(arr,n-1,s);
    return 0;
}