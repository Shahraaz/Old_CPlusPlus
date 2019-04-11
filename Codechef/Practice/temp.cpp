#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot = arr[low],i=low,j;
    for(j=low+1;j<=high;j++)
        if(arr[j]<=pivot)
            swap(arr[++i],arr[j]);
    swap(arr[i],arr[0]);
    return i + 1;
}

void qsort(vector<int> &arr,int low,int high){
    if(low<high){
        int pi = partition(arr,low,high);
        qsort(arr,low,pi-1);
        qsort(arr,pi+1,high);
        for(low;low<=high;low++)
            cout << arr[low];
        cout << '\n';
    }
}

int main() {
    int n,temp,i;
    cin >> n;
    vector<int> arr;
    for(i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp); 
    }
    qsort(arr,0,n-1);
    return 0;
}
