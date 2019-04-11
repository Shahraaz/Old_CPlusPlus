#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int i,n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(i=0;i<n;i++)
        arr[i] = i+1;
    reverse(arr.begin(),arr.begin()+k+1);
    for(i=0;i<n;i++)
        cout << arr[i] << ' ';
    return 0;
}