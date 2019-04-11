#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n],i,j,temp;
    long long int sum = 0 ; 
    for(i=0;i<n;i++)
        cin >> arr[i];
    for(i=0;i<n;i++)
        for(j =i+1,temp=arr[i];j<n;j++)
            sum += temp&arr[j];
    cout << sum << endl;
    return 0;
}